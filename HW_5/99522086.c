/*******************************************************
This program was created by the
CodeWizardAVR V3.14 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : P5
Version : 
Date    : 11/21/2023
Author  : Melika Mohammadi Fakhar
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/
#include <mega32.h>
#include <delay.h>


const unsigned char Code[]=
{
	0xFF,	//	0001		
	0xFF,	//	0002		 
	0xFF,	//	0003		
	0xFF,	//	0004		
	0xFF,	//	0005		
	0xFF,	//	0006		
	0xFF,	//	0007		
	0xFF,	//	0008		
	0xFF,	//	0009		
	0xFF,	//	000A		
	0xFF,	//	000B		
	0xFF,	//	000C		
	0xFF,	//	000D		
	0xFF,	//	000E		
	0xFF,	//	000F		
	0xFF,	//	0010		
	0x1F,	//	0011		 
	0xC3,	//	0012		
	0xDC,	//	0013		
	0xDC,	//	0014		
	0xC3,	//	0015		
	0x1F,	//	0016		
	0xFF,	//	0017		
	0x00,	//	0018		
	0x76,	//	0019		
	0x76,	//	001A		
	0x76,	//	001B		
	0x89,	//	001C		
	0xFF,	//	001D		
	0xC3,	//	001E		
	0xBD,	//	001F		 
	0x7E,	//	0020		 
	0x7E,	//	0021		
	0x7E,	//	0022		
	0x7E,	//	0023		
	0xFF,	//	0024		
	0x00,	//	0025		
	0x7E,	//	0026		 
	0x7E,	//	0027		
	0x7E,	//	0028		
	0xBD,	//	0029		
    0xC3,    //    002A        
    0xFF,    //    002B        
    0x00,    //    002C        
    0x76,    //    002D        
    0x76,    //    002E        
    0x76,    //    002F        
    0x7E,    //    0030        
    0xFF,    //    0031        
    0x00,    //    0032        
    0xF6,    //    0033        
    0xF6,    //    0034       
    0xF6,    //    0035       
    0xF6,    //    0036       
    0xFF,    //    0037        
    0xFF,    //    0038        
    0xFF,    //    0039        
    0xFF,    //    003A        
    0xFF,    //    003B        
    0xFF,    //    003C        
    0xFF,    //    003D        
    0xFF,    //    003E        
    0xFF,    //    003F        
    0xFF     //    0040        
};



void main(void)
{
    unsigned char Row, Scan, Refresh, Index, S;

    // Set data direction registers
    DDRC = 0xFF; // Port C as output
    DDRD = 0xFF; // Port D as output
    DDRB = 0xFF; // Port B as output

    while (1) // Infinite loop
    {
        for (S = 0; S < 56; S++) // Loop from 0 to 55
        {
            for (Refresh = 1; Refresh < 11; Refresh++) // Loop from 1 to 10
            {
                Scan = 0b00000001; // Initialize Scan variable

                for (Row = 0; Row < 8; Row++) // Loop from 0 to 7
                {
                    Index = (56 - S) + Row; // Calculate Index value

                    // Display on the first half of the LED matrix
                    PORTD = Scan;           // Set PORTD
                    PORTB = 0x00;           // Set PORTB to 0
                    PORTC = Code[Index];    // Display value from Code array
                    delay_ms(2);            // Delay for 2 milliseconds

                    // Display on the second half of the LED matrix
                    PORTB = Scan;                  // Set PORTB
                    PORTD = 0x00;                  // Set PORTD to 0
                    PORTC = Code[(Index + 8) % 64]; // Display value from Code array
                    delay_ms(2);                   // Delay for 2 milliseconds

                    Scan = Scan << 1; // Shift Scan to the left
                }
            }
        }
    }
}