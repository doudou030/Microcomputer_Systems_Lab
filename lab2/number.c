#include <8051.h>
#include "utils.c"
#define Button_set P0_0
#define Button_plus P0_1

void main()
{
	Button_plus = 1;
	Button_set  = 1;
	unsigned set_count = 0;
	flash_delay=1000;

	while(1)
	{
		//用if(Button_set)判斷set按鍵有沒有被按 
		if(Button_set == 0) {
			// 被按之後裡面的set_count+1
			set_count++;
			delay(100);
			while(Button_set == 0){
				delay(0);
			}
		}
		
		if(set_count==0) {
			//裡面一個 if(Button_plus)為十位數+1
			ten = 0;
			digit = 0;
			display(0);
		}
		
		//用if(set_count==1)將十位數的七段顯示器做閃爍及加法  
		if(set_count==1) {
			//裡面一個 if(Button_plus)為十位數+1
			
			if(Button_plus == 0)
			{
				ten = ((ten + 1) % 10);
				delay(100);
			} 
			while(Button_plus==0){
				display(1);
			}
			display(1);
		}
			
			 
		//用if(set_count==2)將個位數的七段顯示器做閃爍及加法 
		if(set_count==2) {
			//裡面一個 if(Button_plus)為個位數+1
			if(Button_plus == 0)
			{
				digit = ((digit + 1) % 10);
				delay(100);
			}
			while(Button_plus==0){
				display(2);
			}
			display(2);
		}
			
			
			
		//用if(set_count==3)開始倒數
		if(set_count==3) { 
			//倒數
			sum = ten * 10 + digit; 
			while(sum != 0){
				if (digit == 0) {
					digit = 9;
					ten--;
				} else {
					digit--;
				}
				sum--;
				display(0);	
				P1 = 0X00;
				display(0);	
			}
			
			//最後將 set_count = 0 ，可以重複跑 
			set_count = 0;
		}
	}
}