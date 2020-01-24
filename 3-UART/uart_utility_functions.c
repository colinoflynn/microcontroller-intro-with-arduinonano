/*
 * GccApplication7.c
 *
 * Created: 2017-01-03 10:27:53 AM
 * Author : JF
 */ 

#include <stdio.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);
FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
FILE mystdin = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);
/******************************************************************************
******************************************************************************/
int uart_putchar(char c, FILE *stream)
{
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	return 0;
}
/******************************************************************************
******************************************************************************/
int uart_getchar(FILE *stream)
{
	/* Wait until data exists. */
	loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
}
/******************************************************************************
******************************************************************************/
void init_uart(void)
{
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	UBRR0 = 103;  //With 16 MHz Crystal, 9600 baud = 103
	stdout = &mystdout;
	stdin = &mystdin;
}