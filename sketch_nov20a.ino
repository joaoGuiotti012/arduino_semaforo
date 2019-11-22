// Display LCD 7 segmentos
// Contagem regressiva de 9 a 0
byte seven_seg_digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  //0
  {0, 0, 0, 0, 1, 1, 0},  //1
  {1, 1, 0, 1, 1, 0, 1},  //2
  {1, 1, 1, 1, 0, 0, 1},  //3
  {0, 1, 1, 0, 0, 1, 1},   //4
  {1, 0, 1, 1, 0, 1, 1},   //5
  {0, 0, 1, 1, 1, 1, 1},   //6
  {1, 1, 1, 0, 0, 0, 0},   //7
  {1, 1, 1, 1, 1, 1, 1},   //8
  {1, 1, 1, 0, 0, 1, 1},   //9
};
    

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11,OUTPUT);     //define o led verde
  pinMode(12,OUTPUT);     //define o amarelo
  pinMode(13,OUTPUT);    //define o vermelho
  writeDot(0); // Inicia com o sinal das casas decimais desligado
}

void writeDot(byte dot){
  digitalWrite(9,dot);
}

void sevenSegWrite(byte digit){
  byte pin = 2;
  for(byte segCount = 0; segCount < 9 ; ++segCount){
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;    
  }
}


void loop() {

  for(byte count = 10; count > 0; --count){
    digitalWrite(11,HIGH); 
    delay(800);
    sevenSegWrite(count - 1);
    digitalWrite(11,LOW);  
    
  }
  digitalWrite(12,HIGH);
  delay(2000);  // aguarda por 4 segundos
  digitalWrite(12,LOW);
  
  for(byte count = 10; count > 0; --count){
    digitalWrite(13,HIGH); 
    delay(800);
    sevenSegWrite(count - 1);
    digitalWrite(13,LOW);  
    
  }

}
