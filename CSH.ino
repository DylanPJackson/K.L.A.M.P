/*
 * Basic interactivity with CSH logo. 
 * Maintains array of possible colors, but stays at one
 * 
 * 26x26
 * 
 * Future functionality will allow interactivity
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

int pause = 1000;

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

int col[6][3] = {{7,0,0}, {7,2,0}, {7,4,0}, {0,7,0}, {0,0,7}, {5,0,7}};


void setup() {
  matrix.begin();
  drawC(col[3]);
  drawS(col[3]);
  drawH(col[3]);
  
}

void loop() {
  
}

void drawC(int col[3]){
  
  matrix.drawRect(3,3,20,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(3,5,2,22, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(3,27,20,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(21,5,2,6, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(21,21,2,6, matrix.Color333(col[0],col[1],col[2]));
}

void drawS(int col[3]){
  matrix.drawRect(17,7,2,4, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,7,12,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,9,2,6, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,15,12,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(17,17,2,8, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,23,10,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(7,21,2,2, matrix.Color333(col[0],col[1],col[2]));
}

void drawH(int col[3]){
  matrix.drawRect(21,13,2,6, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(23,15,6,2, matrix.Color333(col[0],col[1],col[2]));
  matrix.drawRect(27,3,2,26, matrix.Color333(col[0],col[1],col[2]));
}

