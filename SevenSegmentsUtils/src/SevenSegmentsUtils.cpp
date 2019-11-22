#include <SevenSegmentsUtils.h>

//Construtor
SevenSegmentsUtils::SevenSegmentsUtils() {
}

//Implementação da função/método 'begin'
void SevenSegmentsUtils::begin() {
    for (int i = START_PIN; i <= END_PIN; i++) {
        pinMode(i, OUTPUT);
    }
}

void SevenSegmentsUtils::controllPoint(byte value) {
  digitalWrite(9, value); //controle do ponto 9 no display
}

void SevenSegmentsUtils::printDigit(byte digit, byte digits_display[LENGTH_SET][LENGTH_SEVEN_SEGMENTS], int ports[LENGTH_SEVEN_SEGMENTS]) {
  for (byte count = 0; count <= LENGTH_SEVEN_SEGMENTS; count++) {
    digitalWrite(ports[count], digits_display[digit][count]);
  }
}

void SevenSegmentsUtils::animacao(byte digits_display[LENGTH_SET][LENGTH_SEVEN_SEGMENTS], int ports[LENGTH_SEVEN_SEGMENTS]) {
  for (int i = START_PIN_ANIMATION; i < LENGTH_SET; i++) {
    printDigit(i, digits_display, ports);
    delay(100);
  }
  for (int i = START_PIN_ANIMATION; i < LENGTH_SET; i++) {
    printDigit(i, digits_display, ports);
    delay(100);
  }
}

void SevenSegmentsUtils::printDigits(int digits[], int size, int time, byte digits_display[LENGTH_SET][LENGTH_SEVEN_SEGMENTS], int ports[LENGTH_SEVEN_SEGMENTS]) {
  for (int i = 0; i < size; i++) {
    printDigit(digits[i], digits_display, ports);
    delay(time);
  }
}

void SevenSegmentsUtils::printText(String data, byte digits_display[LENGTH_SET][LENGTH_SEVEN_SEGMENTS], int ports[LENGTH_SEVEN_SEGMENTS]) {
  for (int i = 0; i < data.length(); i++) {
    String letter = data.substring(i, i+1);
    if (letter.equalsIgnoreCase("A")) {
      printDigit(10, digits_display,  ports);
    } else if (letter.equalsIgnoreCase("E")) {
      printDigit(11, digits_display, ports);
    } else if (letter.equalsIgnoreCase("I")) {
      printDigit(12, digits_display, ports);
    } else if (letter.equalsIgnoreCase("O")) {
      printDigit(13, digits_display, ports);
    } else {
      printDigit(14, digits_display, ports);
    }
    delay(500);
  }
}
