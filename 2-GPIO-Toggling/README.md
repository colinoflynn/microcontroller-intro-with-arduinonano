# Introduction to GPIO

The following video goes through the relevant material on the General Purpose Input/Output (GPIO) pins:

[![](youtube-gpio.png)](https://youtu.be/WKQMCwCtVrs)

[ENGI 2203-02: Introduction to GPIO with ATMega328P](https://youtu.be/WKQMCwCtVrs)

GPIO are one of the most important pins you can use! You can toggle LEDs, check buttons, and more! The GPIO pins on the Arduino board map to specific pins on the Microcontroller itself. See the [Quick Reference](https://github.com/colinoflynn/microcontroller-intro-with-arduinonano/blob/master/Reference-Material/Arduino-nano-pinout-micheleardito.info_-1024x541.png) for these.

You'll find lots of shorthand, like **PD5** means **PORTD5**, which refers to bit number 5 of PORTD.

## Gpio Reference

Most of the time, we will be using only a few GPIO registers:
* Data Direction Register (DDR) configures pin as input or output.
* PORT writes OUTPUT DATA to the pin.
* PIN reads INPUT DATA from the pin.

⚠ Watch out - a common mistake is to attempt to WRITE to the ```PIN``` register to change the I/O pin status, or READ from the ```PORT``` register to read the physical pin status. You *can* do this - but if you are reading the ```PORT``` register it only gives you the status of the last value you wrote to the pin.

![](gpio-registers.png)

The registers are connected as given below:

![](gpio-diagram.png)

## Example Code

The simple code to read a single pin register and forward to the LED is given below:

	#define F_CPU 16000000UL
	#include <avr/io.h>
	#include <util/delay.h>
	
	int main(void)
	{
		DDRB |= (1 << DDB5); //00100000
		
	    /* Replace with your application code */
	    while (1) 
	    {
			if (PINC & (1<<PINC0)) {
				PORTB |= (1<<PORTB5);
				} else {
				PORTB &= ~(1<<PORTB5); //In video PORTB = ~(1<<PORTB5);
			}	
	    }
	}
	
