#include <avr/io.h>
#include <util/delay.h>

//Ignored
void setup() {
  ;
}

// Main.c
void loop() {
  DDRB |= 1<<DDB5;

  while(1){
    PORTB ^= 1<<DDB5;
    _delay_ms(1000);
  }


  //Prevent running again
  while(1);
}
