//final 期末專題
/*期末專題的評分項目：

基本要求：
1. 可以彈奏音樂
2. 可以記錄彈奏過程，包括音高與拍子長短，並存在 MPC82G516 的 "expanded RAM" 之中。
3. 人機介面是否好用（有没有善用 LED 作為操作模式與錄、放音的指引）
4. 程式內容：是否有正確縮排，變數的命名，有否使用正確大小的變數型別以節省記憶空間，註解，易讀性等

加分項目：
1. 錄放彈奏過程的重現度（怎麼彈的，就怎麼錄）
2. 八度音升降
3. 半音階
4. 升降調
5. 外加功能
*/

#include <8051.h>
#include "LED_Display.h"
#include "Keypad4x4.h"

#define SPEAKER P2_3//聲音位置
#define P2_7 0 	//亮燈位置
#define BEAT 3036

char input_key = 0;
char beat_counter = 0;
char song_counter = 0;
char record_counter = 0;
unsigned d1, d2, current_freq, shift;
__xdata unsigned char recorded[50];

void delay(unsigned n) {
	for  (d1 = 0; d1 < 1000; d1++){
		for  (d2 = 0; d2 < n; d2++);
	}
}

//對應的音高
unsigned const pitch[ ] = {
    65536 - 1000000 / (2 * 262 ),  // C
	65536 - 1000000 / (2 * 277 ),  // C#
    65536 - 1000000 / (2 * 294 ),  // D
    65536 - 1000000 / (2 * 311 ),  // D#
    65536 - 1000000 / (2 * 330 ),  // E
    65536 - 1000000 / (2 * 349 ),  // F
    65536 - 1000000 / (2 * 370 ),  // F#
    65536 - 1000000 / (2 * 392 ),  // G
    65536 - 1000000 / (2 * 415 ),  // G#
    65536 - 1000000 / (2 * 440 ),  // A
    65536 - 1000000 / (2 * 466 ),  // A#
    65536 - 1000000 / (2 * 494 ),  // B
    0,0,0,0,0 //const會疊再一起所以用0去區隔，不然會呼叫錯誤
};

unsigned const high_pitch[ ] = {
    65536 - 1000000 / (2 * 523 ),  // high C
	65536 - 1000000 / (2 * 554 ),  // high C#
    65536 - 1000000 / (2 * 587 ),  // high D
    65536 - 1000000 / (2 * 622 ),  // high D#
    65536 - 1000000 / (2 * 659 ),  // high E
    65536 - 1000000 / (2 * 698 ),  // high F
    65536 - 1000000 / (2 * 740 ),  // high F#
    65536 - 1000000 / (2 * 784 ),  // high G
    65536 - 1000000 / (2 * 831 ),  // high G#
    65536 - 1000000 / (2 * 880 ),  // high A
    65536 - 1000000 / (2 * 932 ),  // high A#
    65536 - 1000000 / (2 * 988 ),  // high B
    0,0,0,0,0
};
//預設歌曲
unsigned const default_song[50] = {
    0,0,16,0,0,16,7,7,16,7,7,16,//12
    9,9,16,9,9,16,7,7,16,16,16,//11
    5,5,16,5,5,16,4,4,16,4,4,16,//12
    2,2,16,2,2,16,0,0,16,//9
    16,16,16,16,16,16//6
};

//撥放音樂的timer
void beat_isr (void) __interrupt (1) __using (1)
{
    beat_counter++;
    TH0 = (BEAT >> 8);
    TL0 = (BEAT & 0xff);
}

// speaker 播放 current_freq 的音
void pitch_fre (void) __interrupt (3) __using (3)
{
    SPEAKER = SPEAKER ? 0 : 1;
    TH1 = (current_freq >> 8);
    TL1 = (current_freq & 0xff);
}

void main() {
	//Initialization 初始化
    char is_record = 0;
    char is_play = 0;
    char is_shift = 0;
    char is_default_play = 0;
   
	//interrup設定 
	//set M0 on
    TMOD = 0x11;
    // set TR0 on
    TCON = 0x50;
    // set EA, ET0 ET1, on
    EA = 1;
    ET0 = 1;
    ET1 = 1;

    SPEAKER = 0;
    
	while (1) {
        //從keypad得到對應的值0~16
		input_key = keypad4x4();
    
        //7段顯示對應的值
		dispaly(input_key);

        //平時播對應的音
        if(is_shift == 0){
            current_freq = pitch[input_key];
        } 
        else if(is_shift == 1){
            current_freq = high_pitch[input_key];
        }
        //錄音
        if(is_record == 1){
            recorded[record_counter] = input_key ;
            record_counter = record_counter + 1;
            delay(50);

            while(record_counter > 50){
                //錄完初始化
                is_record = 0;
                record_counter = 0;
                current_freq = 0;
                dispaly(15);
                delay(1000);
            }
        }

        //撥放音樂
        if(is_play == 1){
            if(is_shift == 0){
                 current_freq = pitch[recorded[song_counter]];
            }else if(is_shift == 1){
                 current_freq = high_pitch[recorded[song_counter]];
            }
            song_counter = song_counter + 1;
            dispaly(recorded[song_counter]);
            delay(50);
            while(song_counter > 50){
                //撥完音樂初始化
                is_play = 0;
                song_counter = 0;
                current_freq = 0;
                dispaly(15);
                delay(1000);
            }
        }

        //播放預設音樂
        if(is_default_play == 1){
             if(is_shift == 0){
                 current_freq = pitch[default_song[song_counter]];
            }else if(is_shift == 1){
                 current_freq = high_pitch[default_song[song_counter]];
            }
            song_counter = song_counter + 1;
            dispaly(default_song[song_counter]);
            delay(50);
            while(song_counter > 50){
                //撥完音樂初始化
                is_default_play = 0;
                song_counter = 0;
                current_freq = 0;
                dispaly(15);
                delay(1000);
            }
        }

        //功能鍵
        if (input_key == 12) {
            is_record = 1;
            delay(500);
        }
        else if(input_key == 13){
            is_play = 1;
            delay(500);
        }
        else if(input_key == 14){
            is_shift = is_shift ? 0 : 1;
            delay(500);
        }
        else if(input_key == 15){
            is_default_play = is_default_play ? 0 : 1;
            delay(500);
        }
	}
}
