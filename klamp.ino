#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <stdlib.h>

#define CLK 11  //(Use pin 11 on Mega)
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);
int state = 900;

// For BLIND
int brightnesses[3] = {1,2,0};

// For TEXTCSH
int globalStart[2] = {30, 1};
int pauses[3] = {500, 1000, 2000}; // Also used for GSH
int colors[3] = {5,0,7};

// For GSH
int j = 6;
int col[6][3] = {{7,0,0}, {7,2,0}, {7,4,0}, {0,7,0}, {0,0,7}, {5,0,7}}; // Also used for CSH

void setup(){
  matrix.begin();
  Serial.begin(9600);
  /*matrix.drawPixel(0,0, matrix.Color333(7,0,0));
  matrix.drawPixel(0,1, matrix.Color333(0,7,0));
  matrix.drawPixel(0,2, matrix.Color333(0,0,7));
  matrix.drawPixel(0,3, matrix.Color333(7,0,7));
  matrix.drawPixel(0,4, matrix.Color333(0,7,7));
  */
}

int test1(){
  int counter = 0;
  state = 11;
  while(true){
    if(Serial.available() > 0){
      state = Serial.read();
    }
    if(state == '0'){
      state = 900;
      return 1;
    }else if(state == '1'){
      //matrix.drawRect(0,0,7,7, matrix.Color333(col[counter][0], col[counter][1], col[counter][2]));
      matrix.drawRect(0,0,7,7, matrix.Color333(counter, counter, counter));
      counter ++;
      counter = counter % 7;
      state = 900;
    }
  }
}

int test2(){
  int counter = 0;
  state = 11;
  while(true){
    if(Serial.available() > 0){
      state = Serial.read();
    }
    if(state == '0'){
      state = 900;
      return 1;
    }else if(state == '1'){
      //matrix.drawRect(0,0,15,15, matrix.Color333(col[counter][0], col[counter][1], col[counter][2]));
      matrix.drawRect(0,0,15,15, matrix.Color333(counter, counter, counter));
      counter++;
      counter = counter % 7;
      state = 900;
    }
  }
}

// Main loop for blind mode
int blind(){
  int counter = 0;
  state = 11;
  while(true){
    if(Serial.available() > 0){
      state = Serial.read();
    }
    if(state == '0'){
      state = 900;
      return 1;
    }else if(state == '1'){
      matrix.fillRect(0,0,32,32, matrix.Color333(brightnesses[counter], brightnesses[counter], brightnesses[counter]));
      counter ++;
      counter = counter % 3;
      state = 900;
    }
  }
}

void clean(){
  matrix.fillRect(0,0,32,32, matrix.Color333(0,0,0));
}

// Main loop for textcsh mode
int textcsh(){
  int counter = 0;
  globalStart[0] = {30};
  state = 11;
  while(true){
    if(Serial.available() > 0){
      state = Serial.read();
    }
    if(state == '0'){
      state = 900;
      return 1;
    }else if(state == '1'){
      counter ++;
      counter = counter % 3;
      state = 900;
    }
    delay(pauses[counter]);
    clean();
    globalStart[0] ++;
    make_csh();
  }
}

/*
 * The following functions belong to textcsh functionality
 */

// Calls computer && science && house
void make_csh(){
  computer(globalStart);
  science(globalStart);
  house(globalStart);
}

// Handles creation of COMPUTER
void computer(int wordStart[2]){
  createCC(wordStart);
  createOC(wordStart);
  createMC(wordStart);
  createPC(wordStart);
  createUC(wordStart);
  createTC(wordStart);
  createEC(wordStart);
  createRC(wordStart);
  
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

// End implementation of textcsh

// Main loop for gsh mode
int gsh(){
  int counter = 0;
  state = 900;
  while(true){
    if(Serial.available() > 0){
      state = Serial.read();
    }
    if(state == '0'){
      state = 900;
      return 1;
    }else if(state == '1'){
      counter ++;
      counter = counter % 3;
      state = 900;
    }
    delay(pauses[counter]);
    display_gsh();
  }
}

/*
 * The following functions belong to gsh functionality
 */

void display_gsh(){
  sec_1(col[j%6]);
  sec_2(col[(j+1)%6]);
  sec_3(col[(j+2)%6]);
  sec_4(col[(j+3)%6]);
  sec_5(col[(j+4)%6]);
  sec_6(col[(j+5)%6]);
  j = j + 5;
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

// End implementation of gsh

int csh(){
  int counter = 0;
  state = 900;
  while(true){
    if(Serial.available() > 0){
      state = Serial.read();
    }
    if(state == '0'){
      state = 900;
      return 1;
    }else if(state == '1'){
      display_csh(counter);
      counter ++;
      counter = counter % 6;
      state = 900;
    }
  }
}

/*
 * The following functions belong to csh functionality
 */

void display_csh(int counter){
  drawC(counter);
  drawS(counter);
  drawH(counter);
}

void drawC(int counter){
  
  matrix.drawRect(3,3,20,2, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(3,5,2,22, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(3,27,20,2, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(21,5,2,6, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(21,21,2,6, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
}

void drawS(int counter){
  matrix.drawRect(17,7,2,4, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(7,7,12,2, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(7,9,2,6, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(7,15,12,2, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(17,17,2,8, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(7,23,10,2, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(7,21,2,2, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
}

void drawH(int counter){
  matrix.drawRect(21,13,2,6, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(23,15,6,2, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
  matrix.drawRect(27,3,2,26, matrix.Color333(col[counter][0],col[counter][1],col[counter][2]));
}


void loop(){
  if(Serial.available() > 0){
    state = Serial.read();
  }
  if(state == '0'){
    while(true){
      blind();
      clean();
      textcsh();
      clean();
      gsh();
      clean();
      csh();
      clean();
    }
  } 
}
