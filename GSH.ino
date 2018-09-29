/*
 * The relevant part of the matrix is the CSH logo. This is a 26 x 26 logo. 
 * There are six sections in the logo which each hold a distinct color at one time. 
 * There are six methods which create the six sections individually. There is an array
 * of six colors, and as the loop progresses, the color of each section is indexed by 
 * one, then wraps.
 * 
 * Make scrolling text of "Computer Science House" 
 * Make colors spread out from the center
 * Pulsating colours
 * Bring the strip and surround the matrix with it and coordinate the colors 
 * with the color present on the matrix color
 * 
 * Interactivity, something that you can touch so that it changes color
 * Tied to a lamp so that it's a light, tied to a rotating lamp post
 * so that you can tilt it up and turn it all white
 * 
 * 
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

int pause = 750;

int j = 6;
int col[6][3] = {{7,0,0}, {7,2,0}, {7,4,0}, {0,7,0}, {0,0,7}, {5,0,7}};

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {
  matrix.begin();
}

// Draws top four lines
void sec_1(int col[3]){
  matrix.drawRect(3,3,20,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(3,5,2,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(21,5,2,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(27,3,2,4, matrix.Color333(col[0],col[1],col[2]));
}

// Draws lines 5-8
void sec_2(int col[3]){
  matrix.drawRect(3,7,2,4, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,7,12,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(21,7,2,4, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(27,7,2,4, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,9,2,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(17,9,2,2, matrix.Color333(col[0],col[1],col[2]));
}

// Draws line 9-12
void sec_3(int col[3]){
  matrix.drawRect(3,11,2,5, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,11,2,5, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(9,15,10,1, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(21,13,2,3, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(23,15,4,1, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(27,11,2,5, matrix.Color333(col[0],col[1],col[2]));
}

// Draws line 13-16
void sec_4(int col[3]){
  matrix.drawRect(3,16,2,4, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,16,12,1, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(21,16,2,3, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(23,16,4,1, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(27,16,2,4, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(17,17,2,3, matrix.Color333(col[0],col[1],col[2]));
}

void sec_5(int col[3]){
  matrix.drawRect(3,20,2,4, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,21,2,3, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(9,23,10,1, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(17,20,2,3, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(21,21,2,3, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(27,20,2,4, matrix.Color333(col[0],col[1],col[2]));
}

void sec_6(int col[3]){
  matrix.drawRect(3,24,2,5, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,24,12,1, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(5,27,16,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(21,24,2,5, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(27,24,2,5, matrix.Color333(col[0],col[1],col[2]));
}

void loop() {
   sec_1(col[j%6]);
   sec_2(col[(j+1)%6]);
   sec_3(col[(j+2)%6]);
   sec_4(col[(j+3)%6]);
   sec_5(col[(j+4)%6]);
   sec_6(col[(j+5)%6]);
   j = j + 5;
   delay(pause);
}


