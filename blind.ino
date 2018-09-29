/*
 * file : blind.ino
 * 
 * Basic functionality of setting entire matrix to white
 * 
 * author : Dylan P. Jackson
 */

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <stdlib.h>

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

int brightnesses[7] = {1,2,3,4,5,6,7};

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {
  matrix.begin();
}

void loop(){
  blind(brightnesses[0]);
}

void blind(int brightness){
  matrix.fillRect(0,0,32,32, matrix.Color333(brightness, brightness, brightness));
}

