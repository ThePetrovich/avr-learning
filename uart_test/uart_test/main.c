/*
 * uart_test.c
 *
 * Created: 07.06.2019 9:18:59
 * Author : IKS2019
 */ 

#include <avr/io.h>
#define F_CPU 8000000L
#include <util/delay.h>
#include <string.h>

int main(void)
{
	UCSR1B |= (1 << TXEN1)|(1 << RXEN1);
	UBRR1L = 51;
	char hello[] = "Hello worldadlsfhalsdhgljdfagbp\r\n";	
	DDRG |= (1 << 3);
	
    while (1) 
    {
		for(int i = 0; i < strlen(hello); i++){
			UDR1 = hello[i];
			while(!(UCSR1A & (1 << UDRE1)));
		}
		PORTG |= (1 << 3);
		_delay_ms(500);
		PORTG &= ~(1 << 3);
		_delay_ms(500);
    }
}

