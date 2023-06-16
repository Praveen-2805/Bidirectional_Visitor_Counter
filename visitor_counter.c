#include<reg51.h>

// P1 connected to LCD data pins.
#define lcd P1
// pins P3.6 and P3.7 to rs and e pins of LCD display.
sbit rs=P3^6;
sbit e=P3^7;

// pins P2.0 and P2.1 are connected to the data pins of the IR sensor.
// usually these pins act as a input pins.
sbit s1=P0^0;
sbit s2=P0^1;

// usually LCD requires ascii values as a input, to display the characters and numbers.
// so, in order to display numbers from 0 to 9, we need to send ascii values to the lcd from 48 to 57.
int no[10]={48,49,50,51,52,53,54,55,56,57};

// initializing all used function globally.
void delay (int);
void cmd (unsigned char);
void display (unsigned char);
void init (void);
void view (int);
void string (char *);
int count=0,entr=0,exit=0;

// delay function which produce approx of 1ms delay if d is 1.
// so, if d is 1000 it produce approx 1sec delay.
void delay (int d)
{
	unsigned char i=0;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
		for(i=248;i>0;i--);
	}
}

//the function will holds a set of primary commands to display which is used to initialize it.
void cmd (unsigned char c)
{
	lcd=c;
	rs=0;
	e=1;
	delay(5);
	e=0;
}

// display function is used to give data to the lcd, which is to be displayed.
// usually a single character.
void display (unsigned char c)
{
	lcd=c;
	rs=1;
	e=1;
	delay(5);
	e=0;
}

// string function is used display the string characters (words).
// this function will work by keep on calling the display function to display the individual character in a word,
// untill it detect '/0'. usually an end of string (word).
void string (char *p)
{
	while(*p)
	{
		display(*p++);
	}
}

//the function will holds a set of primary commands to display which is used to initialize it.
void init (void)
{
	cmd(0x38);
	cmd(0x0c);
	cmd(0x01);
	cmd(0x80);
}

// NOTE : we cant send the 2 or more digit values directly to the LCD display. like, 22, 234, 4321, etc....
// to over come this problem this _view_ function will split the 2 digit value (as this project concentrate
// only values from 00 to 99) seperately and send them one by one to the display function.
void view (int n)
{
	display(no[(n/10)%10]);
	display(no[n%10]);
}


void main()
{
	P2=0x00;// as the IR sensor connected to PORT2, to detect the 1 (HIGH) o/p from the IR sensor make this PORT as 0 (LOW).

	init();// call init function to to initialize the display.

	string("   Bidirectional  ");
	cmd(0xc0);
	string("     Counter      ");
	delay(1000);
	cmd(0x01);
// as the count value was 0, the view function will make the LCD to display 00 initially.


	// once if, s1 detects high follow by s2 then the value will increament.
	// unless if, s2 detects high follow by s1 then the value will decreament.
	while(1)
	{
		if(s1==1)// this condition will become true if, first sensor o/p will become HIGH at first.

		{
			while(s2==0);// this condition will wait until the second sensor o/p becomes HIGH.
			count=count+1;// increament statement.
			entr=entr+1;
			cmd(0x80);
			while(s2==1);// this condition will wait until the second sensor o/p becomes LOW.
			string("ENTR:");
			view(entr);
			
		}
		else if(s2==1)// this condition will become true if, secont sensor o/p will become HIGH at first.
		{
			while(s1==0);// this condition will wait until the first sensor o/p becomes HIGH.
			if(count!=0)// this condition will stop the decreament, once if the count reaches 0.
			count=count-1;// decreament statement.
			exit=exit+1;
			cmd(0xc0);
			while(s1==1);// this condition will wait until the first sensor o/p becomes LOW.
			string("EXIT: ");
			view(exit);
			
		}
		cmd(0x89);
		string("TOT:");
		view(count);
		if(count!=0){
			P0=0x80;
			P0=0x40;	
		}
	}
}