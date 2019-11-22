#include <SevenSegmentsUtils.h>

SevenSegmentsUtils sevenSegmentsUtils = SevenSegmentsUtils();

byte digits_display[21][7] = {
  {1, 1, 1, 1, 1, 1, 0},  //0
  {0, 0, 0, 0, 1, 1, 0},  //1
  {1, 1, 0, 1, 1, 0, 1},  //2
  {1, 1, 1, 1, 0, 0, 1},  //3
  {0, 1, 1, 0, 0, 1, 1},   //4
  {1, 0, 1, 1, 0, 1, 1},   //5
  {0, 0, 1, 1, 1, 1, 1},   //6
  {1, 1, 1, 0, 1, 0, 0},   //7
  {1, 1, 1, 1, 1, 1, 1},   //8
  {1, 1, 1, 0, 0, 1, 1},   //9

  {1, 1, 1, 0, 1, 1, 1},   //A
  {1, 0, 0, 1, 1, 1, 1},   //E
  {0, 0, 0, 0, 1, 1, 0},   //I
  {1, 1, 1, 1, 1, 1, 0},   //O
  {0, 1, 1, 1, 1, 1, 0},   //U
  
  //utilizados na animação - de 16 à 21
  {1, 0, 0, 0, 0, 0, 0},   
  {0, 1, 0, 0, 0, 0, 0},   
  {0, 0, 1, 0, 0, 0, 0},    
  {0, 0, 0, 1, 0, 0, 0},    
  {0, 0, 0, 0, 1, 0, 0},    
  {0, 0, 0, 0, 0, 1, 0}    
};

//Portas digitais utilizadas no display de 7 segmentos
int ports[] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  Serial.begin(9600);
  sevenSegmentsUtils.begin();
  sevenSegmentsUtils.controllPoint(1);
}

int nums[] = {1, 3, 5, 8};
String aeiou = "aeiou";

void loop() {
  
  if (Serial.available()) {
    String data = Serial.readString();
    if (data.equalsIgnoreCase("X")){
      sevenSegmentsUtils.animacao(digits_display, ports);
    } else if (data.equalsIgnoreCase("N")) {
      int size = sizeof(nums)/sizeof(int);
      sevenSegmentsUtils.printDigits(nums, size, 500, digits_display, ports);
    } else if (data.equalsIgnoreCase("A")) {
      sevenSegmentsUtils.printText(aeiou, digits_display, ports);
    } 
  }
}
