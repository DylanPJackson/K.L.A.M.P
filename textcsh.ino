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
int colors[3] = {5,2,7};

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {
  delay(2000);
  matrix.begin();
  globalStart[0] = {30};
  globalStart[1] = {1};
  csh(globalStart);
}

void loop(){
  delay(pause);
  matrix.fillRect(0,0,32,32,matrix.Color333(0,0,0));
  globalStart[0] ++;
  csh(globalStart);
}

// Calls computer && science && house
void csh(int globalStart[2]){
  computer(globalStart);
  science(globalStart);
  house(globalStart);
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
  matrix.drawPixel(x%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 1)%32, y, (x - 1)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createOC(int letterStart[2]){
  int x = letterStart[0] - 24;
  int y = letterStart[1];
  matrix.drawLine(x%32, y, x%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));  
}

void createMC(int letterStart[2]){
  int x = letterStart[0] - 20;
  int y = letterStart[1];
  matrix.drawLine(x%32, y, x%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 1)%32, y, (x - 1)%32, y + 2, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createPC(int letterStart[2]){
  int x = letterStart[0] - 16;
  int y = letterStart[1];
  matrix.drawLine(x%32, y, x%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createUC(int letterStart[2]){
  int x = letterStart[0] - 12;
  int y = letterStart[1];
  matrix.drawLine(x%32, y, x%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createTC(int letterStart[2]){
  int x = letterStart[0] - 8;
  int y = letterStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 2)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 1)%32, y, (x - 1)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createEC(int letterStart[2]){
  int x = letterStart[0] - 4;
  int y = letterStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 3, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 3, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createRC(int letterStart[2]){
  int x = letterStart[0];
  int y = letterStart[1];
  matrix.drawLine(x%32, y, x%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 5, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 6, matrix.Color333(colors[0], colors[1], colors[2]));
}

// Handles creation of SCIENCE
void science(int tempWordStart[2]){
  int wordStart[2] = {tempWordStart[0] - 2, tempWordStart[1] + 11};
  createSS(wordStart);
  createCS1(wordStart);
  createIS(wordStart);
  createE1S(wordStart);
  createNS(wordStart);
  createCS2(wordStart);
  createES2(wordStart);
}

void createSS(int wordStart[2]){
  int x = wordStart[0] - 25;
  int y = wordStart[1];
  matrix.drawLine(x%32, y, x%32, y + 1, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 3, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 3, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine(x%32, y + 3, x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y + 6, (x - 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createCS1(int wordStart[2]){
  int x = wordStart[0] - 21;
  int y = wordStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createIS(int wordStart[2]){
  int x = wordStart[0] - 17;
  int y = wordStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 2)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x- 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 1)%32, y, (x - 1)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createE1S(int wordStart[2]){
  int x = wordStart[0] - 13;
  int y = wordStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createNS(int wordStart[2]){
  int x = wordStart[0] - 8;
  int y = wordStart[1];
  matrix.drawLine(x%32, y, x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 3)%32, y, (x - 3)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 2)%32, y + 3, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createCS2(int wordStart[2]){
  int x = wordStart[0] - 4;
  int y = wordStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createES2(int wordStart[2]){
  int x = wordStart[0];
  int y = wordStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}

// Handles creation of house
void house(int tempWordStart[2]){
  int wordStart[2] = {tempWordStart[0] - 11, tempWordStart[1] + 22};
  createHH(wordStart);
  createOH(wordStart);
  createUH(wordStart);
  createSH(wordStart);
  createEH(wordStart);
}

void createHH(int wordStart[2]){
  int x = wordStart[0] - 16;
  int y = wordStart[1];
  matrix.drawLine(x%32, y, x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createOH(int wordStart[2]){
  int x = wordStart[0] - 12;
  int y = wordStart[1];
  matrix.drawLine(x%32, y, x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createUH(int wordStart[2]){
  int x = wordStart[0] - 8;
  int y = wordStart[1];
  matrix.drawLine(x%32, y, x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createSH(int wordStart[2]){
  int x = wordStart[0] - 4;
  int y = wordStart[1];
  matrix.drawLine(x%32, y, x%32, y + 1, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 3, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 3, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine(x%32, y + 3, x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y + 6, (x - 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}

void createEH(int wordStart[2]){
  int x = wordStart[0];
  int y = wordStart[1];
  matrix.drawPixel(x%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 4, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel(x%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawPixel((x - 1)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
  matrix.drawLine((x - 2)%32, y, (x - 2)%32, y + 7, matrix.Color333(colors[0], colors[1], colors[2]));
}
