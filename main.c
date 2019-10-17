/*
 * GccApplication7.c
 *
 * Created: 10/17/2019 11:04:39 AM
 * Author : new
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


void UART_Init();
char UART_RxChar();
void UART_TxChar(char data);

int main(void)
{
	char myValue;
	
	UART_Init();
	
	while (1)
	{
		myValue = UART_RxChar();
		UART_TxChar(myValue);
	}
}

void UART_Init(){
	UBRR0L = 103;
	UCSR0B = (1<<TXEN0)|(1<<RXEN0);
	UCSR0C = (1<<UCSZ00)|(1<<UCSZ01);
}

void UART_TxChar(char data){
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

char UART_RxChar(){
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}
