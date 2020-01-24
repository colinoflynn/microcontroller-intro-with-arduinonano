# Running Examples with Arduino

The Arduino IDE runs on Mac, which may be a desired feature. You can still follow along with these bare-metal C examples.

Arduino calls their code blocks a "sketch". Your normal Arduino sketch has a single file that is shown in the editor, and for example if you open the blink example it would look like this:

	// the setup function runs once when you press reset or power the board
	void setup() {
	  // initialize digital pin LED_BUILTIN as an output.
	  pinMode(LED_BUILTIN, OUTPUT);
	}
	
	// the loop function runs over and over again forever
	void loop() {
	  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
	  delay(1000);                       // wait for a second
	  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
	  delay(1000);                       // wait for a second
	}

A few notes here:

* There are no ```#include``` lines which normal code has. All this is hidden from you in the Arduino IDE, but we can still add them as normal.
* This is using Arduino functions such as ```pinMode()``` and ``digitalWrite```. We will be ignoring those.
* There is no ```main()```, instead you get ```setup()``` and ```loop()```.

To use our code, we'll add the ```include``` blocks at the start. We'll just run everything in ```loop()```, and not take advantage of ```setup()```. Since our normal ```main()``` would only run once, we'll also add a block at the end of ```loop()```. Our sketch could look like this now:

	#include <avr/io.h>
	#include <util/delay.h>
	
	//Ignored
	void setup() {
	  ;
	}
	
	// Main
	void loop() {
	  DDRB |= 1<<DDB5;
	
	  while(1){
	    PORTB ^= 1<<DDB5;
	    _delay_ms(1000);
	  }
	
	
	  //Prevent running again
	  while(1);
	}

This exact sketch is ```BlinkAS.ino``` in this folder.

### Using Serial Port

In our examples, we use printf() and similar functions. This isn't done by default in Arduino. Compared to our straight C examples, there are more changes needed.

The file ```PrintfAS.ino``` gives you a starting point for this as well. Simply download that file, and add your own logic to the setup() block.