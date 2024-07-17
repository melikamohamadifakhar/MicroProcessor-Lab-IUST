/*******************************************************
This program was created by the
CodeWizardAVR V3.14 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : hw6
Version : 
Date    : 11/27/2023
Author  : Melika Mohammadi Fakhar 99522086
Company : IUST
Comments: 


Chip type               : ATtiny10
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Tiny
External RAM size       : 0
Data Stack size         : 8
*******************************************************/

#include <mega32.h>
#include <stdio.h>


#include <alcd.h>


int clock[7] = {2, 3, 5, 8, 0, 0, 0};

void increase_clock()
{
    clock[6]++;
    if (clock[6] == 10)
    {           
        clock[6] = 0;
        clock[5]++;
    }
    
    if (clock[5] == 10)
    {           
        clock[5] = 0;
        clock[4]++;
    }   
    
    if (clock[4] == 6)
    {
        clock[4] = 0;
        clock[3]++;
    }    
    
    if (clock[3] == 10)
    {
        clock[3] = 0;
        clock[2]++;
    }     
    
    if (clock[2] == 6)
    {
        clock[2] = 0;
        clock[1]++;
    }
    
    if (clock[0] == 2)
    {
        if (clock[1] == 4)
        {
            clock[1] = 0;
            clock[0] = 0;
        }  
    }
    else
    {
        if (clock[1] == 10)
        {
            clock[1] = 0;
            clock[0]++;
        }
    }
}

void display_clock()
{
    char charValue;
    lcd_gotoxy(4,1);
    charValue = clock[0]+'0';
    lcd_putchar(charValue);
    charValue = clock[1]+'0';
    lcd_putchar(charValue);
    
    lcd_gotoxy(7,1);
    charValue = clock[2]+'0';
    lcd_putchar(charValue);
    charValue = clock[3]+'0';
    lcd_putchar(charValue);
    
    lcd_gotoxy(10,1);
    charValue = clock[4]+'0';
    lcd_putchar(charValue);
    charValue = clock[5]+'0';
    lcd_putchar(charValue);
    
    lcd_gotoxy(13,1);
    charValue = clock[6]+'0';
    lcd_putchar(charValue);
}

interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{
    increase_clock();
    display_clock();
}

void main(void)
{
    DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
    PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);


    DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
    PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);


    DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
    PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

    DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
    PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);
    
    TCCR1A=0x00;
    TCCR1B=0x0B;
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x20;
    OCR1AL=0x00;
    OCR1BH=0x00;
    OCR1BL=0x00;


TIMSK=0b00010010;


#asm("sei")

lcd_init(16);
lcd_gotoxy(4,0);
lcd_puts("LCD Clock");
lcd_gotoxy(6,1);
lcd_putchar(':');
lcd_gotoxy(9,1);
lcd_putchar(':');
lcd_gotoxy(12,1);
lcd_putchar(',');


while (1)
    {

    }
}
