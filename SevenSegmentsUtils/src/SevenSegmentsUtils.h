#ifndef _sevensegmentsutils_H
#define _sevensegmentsutils_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
 
class SevenSegmentsUtils {

    public:
        const static int LENGTH_SEVEN_SEGMENTS = 7;
        const static int START_PIN = 2;
        const static int END_PIN = 9;
        const static int LENGTH_SET = 21;
        const static int START_PIN_ANIMATION = 16;

        SevenSegmentsUtils();
        void printDigit(byte digit, byte digits_display[LENGTH_SET][LENGTH_SEVEN_SEGMENTS], int ports[LENGTH_SEVEN_SEGMENTS]);
        void printDigits(int digits[], int size, int time, byte digits_display[LENGTH_SET][LENGTH_SEVEN_SEGMENTS], int ports[LENGTH_SEVEN_SEGMENTS]);
        void controllPoint(byte value);
        void begin();
        void animacao(byte digits_display[LENGTH_SET][LENGTH_SEVEN_SEGMENTS], int ports[LENGTH_SEVEN_SEGMENTS]);
        void printText(String dados, byte digits_display[LENGTH_SET][LENGTH_SEVEN_SEGMENTS], int ports[LENGTH_SEVEN_SEGMENTS]);
};
#endif