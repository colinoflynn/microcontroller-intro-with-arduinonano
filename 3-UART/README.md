
## Setting up Serial Terminal

A common serial terminal program to use is Putty on Windows, which you can download at [https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html).

Other "terminal emulators" can be used however, for example TeraTerm is popular (see the [https://learn.sparkfun.com/tutorials/terminal-basics/tera-term-windows](Spark Fun tutorial)).



## Main Code

The following shows the example code you can run to see ```printf``` & ```scanf``` running.

	#include <avr/io.h>
	#define F_CPU 16000000UL
	#include <util/delay.h>


	int main(void){
		init_uart(); // initialization
		printf("System Booted, built %s on %s\n", __TIME__, __DATE__);
		printf("Hello There. What is your name?\n");
		char name[32];
		scanf("%s", name); // wait for your name (from host)
		printf("Alright %s. What is a number?\n", name); // returns it.
		int number;
		if (scanf("%d", &number) == 1){ // waits for an integer
			printf("OK %s, did you pick %d?\n", name, number); // return the info
		}
		else {
			printf("Hi %s - This is not an integer. Try again.\n", name);
		}
		
		while(1){
			printf("PIND Status: %02x\n", PIND);
			_delay_ms(1000);
		}
	}