//Author: Ruben Filipe
//part of this code was made by adafruit, i just adapted it for this project. 

#include <Adafruit_NeoPixel.h> //neopixel library. Download if you don't have.

#define PIN 3 //input pin Neopixel is attached to

#define NUMPIXELS 8 //number of neopixels in strip, change if using another quantity;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; //time delay in milliseconds, change if you want.

int redColor; //initialize variables
int greenColor;
int blueColor;

void setup() {
  Serial.begin(9600); //initialize serial
  pixels.begin(); //Initialize the NeoPixel library.
}

void loop() {
  double redColor = analogRead(0)/4.02; //Take the analog value of the potentiometer (0-1023)
  double greenColor = analogRead(1)/4.02; //and divide it by 4 so that this value is between 0-255.
  double blueColor = analogRead(2)/4.02; //the division for 4 prevents the value from exceeding 255 and causes an error.
  
  //prints the serial values of each potentiometer (Red, green, Blue). This is optional.
  Serial.print("r: "); 
  Serial.println(redColor);
 
  
  Serial.print("g: ");
  Serial.println(greenColor);
  
  
  Serial.print("b: ");
  Serial.println(blueColor);
  
  Serial.println("");
  
  for (int i=0; i < NUMPIXELS; i++) {
    //pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    //this sends the updated pixel color to the hardware.
    pixels.show();
    
    //delay for a period of time (in milliseconds).
    delay(delayval);
  }
}
