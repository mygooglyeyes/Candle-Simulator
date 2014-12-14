#include <Adafruit_NeoPixel.h>

#define PIN 0
int numpix = 6;  //set the number of Pixels you have/want - more = brighter
int randNumber;
int color;
int wait;
int randpix;
//initalize the neopixel library
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numpix, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
	pinMode(2, INPUT);  //use pin 2 as input for the random seed - pick an unused analog read pin
	strip.begin();
	strip.show(); // Initialize all pixels to 'off'
	randomSeed(analogRead(2));  //Set random number generator seed from analog pin 2
}

void loop()
{
	wait = random(100, 120);  //set a random wait period
	randpix = random(0, numpix + 1); //choose a random number of pixels
	color = random(0, 2); //Pick either yellow or orange
	for (int i = 0; i < numpix / 2; i = i++) //so it leaves a certain number of yellow pixels on (number of pixels/3)
	{
		strip.setPixelColor(i, 255, 120, 0);  //set the number of pixels to turn on and color value (yellowish)
	}
	strip.show(); //turn pixels on

	if (color == 0)  //if red was chosen
	{
		flickred(strip.Color(115, 50, 0), wait, randpix); // call flickred and pass it the red (orangeish) color values - change values to change color
	}
	else  // otherwise use yellow
	{
		flickYellow(strip.Color(180, 80, 0), wait, randpix); // call flickYellow and pass it the yellow color values (change values to change color), and wait time and random pixel count
	}
}  //end main loop


// Function for when red is chosen
void flickred(uint32_t c, uint8_t wait, uint8_t p)
{
	for (int i = 0; i < p - 2; i = i++) //loop for given random pixel count (passed from loop)
	{
		strip.setPixelColor(i, c);
	}

	strip.show();  //turn pixels on

	delay(wait);

	for (int i = 0; i < p; i = i++)
	{
		strip.setPixelColor(i, 0);        //turn pixel off
	}
}  //end flickred


// function for when yellow is chosen
void flickYellow(uint32_t c, uint8_t wait, uint8_t p)
{
	for (int i = 0; i < p; i = i++)  //loop for given random pixel count (passed from loop)
	{
		strip.setPixelColor(i, c);
	}
	
	strip.show();  //turn pixels on

	delay(wait);

	for (int i = 0; i < p; i = i++)
	{
		strip.setPixelColor(i, 0);        //turn pixel off
	}
}  //end flickYellow
