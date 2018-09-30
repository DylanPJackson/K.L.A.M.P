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
int pause = 500;

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {
  delay(pause);
  matrix.begin();
  globalStart[0] = {30};
  globalStart[1] = {1};
  computer(globalStart);
}

void loop(){
  delay(pause);
  matrix.fillRect(0,0,32,32,matrix.Color333(0,0,0));
  globalStart[0] ++;
  computer(globalStart);
}

// Handles creation of COMPUTER
void computer(int wordStart[2]){
  createCC(wordStart);
  createO(wordStart);
  createM(wordStart);
  createP(wordStart);
  createUC(wordStart);
  createT(wordStart);
  createEC(wordStart);
  createR(wordStart);
  
}

void createCC(int letterStart[2]){
  int x = letterStart[0] - 28;
  int y = letterStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(1,0,0));
  matrix.drawPixel(x%32, y + 6, matrix.Color333(1,0,0));
  matrix.drawLine((x - 1)%32, y, (x - 1)%32, y + 6, matrix.Color333(1,0,0));
}

void createO(int letterStart[2]){
  int x = letterStart[0] - 24;
  int y = letterStart[1];
  matrix.drawLine(x%32, y, x%32, y + 6, matrix.Color333(1,0,0));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y + 6, matrix.Color333(1,0,0));  
}

void createM(int letterStart[2]){
  int x = letterStart[0] - 20;
  int y = letterStart[1];
  matrix.drawLine(x%32, y, x%32, y + 6, matrix.Color333(1,0,0));
  matrix.drawLine((x - 1)%32, y, (x - 1)%32, y + 2, matrix.Color333(1,0,0));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(1,0,0));
}

void createP(int letterStart[2]){
  int x = letterStart[0] - 16;
  int y = letterStart[1];
  matrix.drawLine(x%32, y, x%32, y + 4, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y + 4, matrix.Color333(1,0,0));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(1,0,0));
}

void createUC(int letterStart[2]){
  int x = letterStart[0] - 12;
  int y = letterStart[1];
  matrix.drawLine(x%32, y, x%32, y + 6, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y + 6, matrix.Color333(1,0,0));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(1,0,0));
}

void createT(int letterStart[2]){
  int x = letterStart[0] - 8;
  int y = letterStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 2)%32, y, matrix.Color333(1,0,0));
  matrix.drawLine((x - 1)%32, y, (x - 1)%32, y + 6, matrix.Color333(1,0,0));
}

void createEC(int letterStart[2]){
  int x = letterStart[0] - 4;
  int y = letterStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(1,0,0));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(1,0,0));
  matrix.drawPixel(x%32, y + 3, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y + 3, matrix.Color333(1,0,0));
  matrix.drawPixel(x%32, y + 6, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y + 6, matrix.Color333(1,0,0));
}

void createR(int letterStart[2]){
  int x = letterStart[0];
  int y = letterStart[1];
  matrix.drawLine(x%32, y, x%32, y + 4, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(1,0,0));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y + 4, matrix.Color333(1,0,0));
  matrix.drawPixel((x - 1)%32, y + 5, matrix.Color333(1,0,0));
  matrix.drawPixel(x%32, y + 6, matrix.Color333(1,0,0));
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

