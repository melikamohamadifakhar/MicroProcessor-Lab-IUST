/* Melika Mohammadi Fakhar 
99522086 */

#include <mega32.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here

// Standard Input/Output functions
#include <stdio.h>

void CRLF() {
    putchar(13);
    putchar(10);
}

void main(void)
{

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x33;

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 16
lcd_init(16);

while (1)
      {
      int i;             
      char name[] = "Mahdi Amiri";
      char c = getchar();
      putchar(c);
      lcd_putchar(c);  
               
      switch (c) {
            case 'C':
                lcd_clear();
                break;
            case 'c':
                for (i = 0; i < 24; i++) CRLF();
                break;  
            case 'N':
                CRLF();
                for (i = 0; name[i]; i++) {
                    putchar(name[i]);
                }
                CRLF();
                break;  
            case 'M': 
                lcd_clear();
                lcd_puts(name);
                break;
      }
      
      }
}
