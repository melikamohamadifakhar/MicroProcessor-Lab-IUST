// Melika Mohammadi Fakhar (99522086)

#include <mega32.h>

// Define constants for 7-segment display patterns
#define SEG_0 0x3F
#define SEG_1 0x06
#define SEG_2 0x5B
#define SEG_3 0x4F
#define SEG_4 0x66
#define SEG_5 0x6D
#define SEG_6 0x7D
#define SEG_7 0x07
#define SEG_8 0x7F
#define SEG_9 0x6F
#define SEG_DOT 0x80

int clock[6] = {2, 3, 5, 8, 0, 0};
int current_7seg = 0;

void increase_clock() {
    clock[5]++;
    if (clock[5] == 10) {
        clock[5] = 0;
        clock[4]++;
    }   
    
    if (clock[4] == 6) {
        clock[4] = 0;
        clock[3]++;
    }    
    
    if (clock[3] == 10) {
        clock[3] = 0;
        clock[2]++;
    }     
    
    if (clock[2] == 6) {
        clock[2] = 0;
        clock[1]++;
    }
    
    if (clock[0] == 2) {
        if (clock[1] == 4) {
            clock[1] = 0;
            clock[0] = 0;
        }  
    } else {
        if (clock[1] == 10) {
            clock[1] = 0;
            clock[0]++;
        }
    }
}

unsigned char convert_to_7seg(int a) {
    switch(a) {
        case 0: return SEG_0;      
        case 1: return SEG_1;
        case 2: return SEG_2;
        case 3: return SEG_3;
        case 4: return SEG_4;
        case 5: return SEG_5;
        case 6: return SEG_6;
        case 7: return SEG_7;
        case 8: return SEG_8;
        case 9: return SEG_9;
    }
}

int has_dot() {
    if (current_7seg % 2 == 1 && clock[current_7seg] % 2 == 0) {
        return 1;
    }
    return 0; 
}

void display(int segment, int number) {
    switch(segment) {
        case 0: PORTD = 0b11111110; break;
        case 1: PORTD = 0b11111101; break;
        case 2: PORTD = 0b11111011; break;
        case 3: PORTD = 0b11110111; break;
        case 4: PORTD = 0b11101111; break;
        case 5: PORTD = 0b11011111; break;
    }
    
    PORTC = convert_to_7seg(number);
    
    if (has_dot()) {
        PORTC |= SEG_DOT;
    }
}

interrupt [TIM0_COMP] void timer0_comp_isr(void) {
    current_7seg++;
    if (current_7seg == 6) {
        current_7seg = 0;
    }
    display(current_7seg, clock[current_7seg]); 
}

interrupt [TIM1_COMPA] void timer1_compa_isr(void) {
    increase_clock();
}

void main(void) {
    // Port initialization
    PORTA = 0x00; // Set Port A as input
    DDRA = 0x00;

    PORTB = 0x00; // Set Port B as output
    DDRB = 0xFF;

    PORTC = 0x00; // Set Port C as output
    DDRC = 0xFF;

    PORTD = 0x00; // Set Port D as output
    DDRD = 0xFF;

    // Timer1 initialization (skipped for brevity, already provided)

    // Timer/Counter Interrupts initialization
    TIMSK = 0b00010010; // Enable Timer0 and Timer1 Compare Match interrupts

    // Global enable interrupts
    
    #asm("sei"); // Enable global interrupts

    while (1) {

    }
}

