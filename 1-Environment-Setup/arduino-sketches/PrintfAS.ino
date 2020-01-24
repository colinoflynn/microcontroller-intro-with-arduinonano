#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

//Ignored
void setup() {
  ;
}

int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);
FILE mystdout;
FILE mystdin;
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

  fdev_setup_stream(&mystdout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  fdev_setup_stream(&mystdin, NULL, uart_getchar, _FDEV_SETUP_READ);
  
  stdout = &mystdout;
  stdin = &mystdin;
}

// Main.c
void loop() {
  
  init_uart();

  char st[100];

  printf("Hello World\n");
  printf("Who are you: ");
  scanf("%s", st);
  printf("\nOK, Hi %s!!\n", st);

  //Prevent running again
  while(1);
}
