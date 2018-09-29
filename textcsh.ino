#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <stdlib.h>

#define CLK 8  //(Use pin 11 on Mega)
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

int globalStart[2];

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {
  matrix.begin();
  globalStart[0] = {30};
  globalStart[1] = {1};
  computer(globalStart);
}

void loop(){
  
}

// Handles creation of COMPUTER
void computer(int wordStart[2]){
  //createCC();
  createO();
  createM();
  createP();
  createUC();
  createT();
  createEC(wordStart);
  createR(wordStart);
  
}

// Handles creation of C for Computer
void createCC(){
  
}

void createO(){
  
}

void createM(){
  
}

void createP(){
  
}

void createUC(){

}

void createT(){
  
}

void createEC(int letterStart[2]){
  int x = letterStart[0] - 4;
  int y = letterStart[1];
  matrix.drawLine(x, y, x - 2, y, matrix.Color333(1,0,0));
  matrix.drawLine(x - 2, y, x - 2, y + 6, matrix.Color333(1,0,0));
  matrix.drawLine(x - 2, y + 3, x, y + 3, matrix.Color333(1,0,0));
  matrix.drawLine(x - 2, y + 6, x, y + 6, matrix.Color333(1,0,0));
}

void createR(int letterStart[2]){
  int x = letterStart[0];
  int y = letterStart[1];
  matrix.drawLine(x, y, x, y + 4, matrix.Color333(1,0,0));
  matrix.drawLine(x, y, x - 2, y, matrix.Color333(1,0,0));
  matrix.drawLine(x - 2, y, x - 2, y + 6, matrix.Color333(1,0,0));
  matrix.drawPixel(x - 1, y + 4, matrix.Color333(1,0,0));
  matrix.drawLine(x - 1, y + 5, x, y + 6, matrix.Color333(1,0,0));
}

