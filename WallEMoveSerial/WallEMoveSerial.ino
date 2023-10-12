#include "Keyboard.h"

const int TX = 1;
const int LREV =43; // 1-63
const int LFOR = 85; // 65-127
const int LSTOP = 64;
const int RREV = 148; // 128-191
const int RFOR = 213; // 193-255
const int RSTOP = 192;
const int TURNMOD = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Keyboard.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char inChar = Serial.read();

    switch (inChar) {
      case 'w':
        Serial.write(LFOR);
        Serial.write(RFOR);
        break;
      case 'a':
        Serial.write(LFOR-TURNMOD);
        Serial.write(RFOR+TURNMOD);
        break;
      case 's':
        Serial.write(LFOR+TURNMOD);
        Serial.write(RFOR-TURNMOD);
        break;
      case 'd':
        Serial.write(LREV);
        Serial.write(RREV);
        break;
    }
  }
  else {

  }

}
