//Lab5-main.c
#include <8051.h>
char timer = 0;
char beat_counter = 0;
char song_counter = 0;
#define BEAT 3036
#define SPEAKER P0_7

// current_freq 為當前要播的音
unsigned current_freq;

unsigned pitch[] = {
    65536 - 1000000 / (2 * 660),    // E
    65536 - 1000000 / (2 * 698),    // F
    65536 - 1000000 / (2 * 740),    // F#
    65536 - 1000000 / (2 * 784),    // G
    65536 - 1000000 / (2 * 830),    // G#
    65536 - 1000000 / (2 * 880),    // A
    65536 - 1000000 / (2 * 932),    // A#
    65536 - 1000000 / (2 * 988),    // B
    65536 - 1000000 / (2 * 1048),   // C
    65536 - 1000000 / (2 * 1108),   // C#
    65536 - 1000000 / (2 * 1176),   // D
    65536 - 1000000 / (2 * 1244),   // D#
    65536 - 1000000 / (2 * 1320),   // E
    65536 - 1000000 / (2 * 1396),   // F
    65536 - 1000000 / (2 * 622),    // D#
    65536 - 1000000 / (2 * 588),    // D
};

const unsigned char song[] = {
    // 1
    7, 7, 7, 7, 5, 3, 3, 2, 0, 0, 3, 7, 12, 12, 12, 12, 10, 8,
    // 2
    8, 7, 5, 5, 7, 8, 7, 8, 7, 11, 8, 7, 7, 5, 3, 3, 2, 0, 2, 2, 2, 2, 3, 2, 0, 0, 0, 0,
    // 3
    3, 3, 3, 3, 2, 0, 0, 14, 14, 14, 15, 14, 9, 9, 9, 9, 11, 9, 9, 7, 7, 7, 9, 11, 13, 13, 13,
    // 4
    12, 10, 11, 8, 8, 8, 8, 7, 5, 3, 3, 3, 3, 5, 2, 0, 0, 0, 0, 0, 0
};

// 計算 beat, beat_counter = 10 換下個音 (0.625s)
void beat_isr (void) __interrupt (1) __using (1)
{
    beat_counter++;
    TH0 = (BEAT >> 8);
    TL0 = (BEAT & 0xff);
}

// speaker 播放 current_freq 的音
void pitch_isr (void) __interrupt (3) __using (3)
{
    SPEAKER = SPEAKER ? 0 : 1;
    TH1 = (current_freq >> 8);
    TL1 = (current_freq & 0xff);
}

void main()
{
    //set M0 on
    TMOD = 0x11;
    // set TR0 on
    TCON = 0x50;
    // set EA, ET0 ET1, on
    EA = 1;
    ET0 = 1;
    ET1 = 1;
    SPEAKER = 0;
    current_freq = pitch[song[0]];

    // 計算 beat, beat_counter = 10 換下個音 (0.625s)
    while (1) {
        if (beat_counter == 10) {
            song_counter = ((song_counter + 1) % sizeof(song));
            current_freq = pitch[song[song_counter]];
            beat_counter = 0;
        }
    }
}