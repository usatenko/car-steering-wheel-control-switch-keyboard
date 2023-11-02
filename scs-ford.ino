#include "BluetoothSerial.h"
#include <BleKeyboard.h>

//#define BS

BleKeyboard bleKeyboard("Ford Wheel Keys", "GM Production", 100);

#ifdef BS
BluetoothSerial SerialBT;
#endif

byte delta = 200;
int zero = 100;

boolean bts[6] = { 0, 0, 0, 0, 0, 0 };
unsigned long tmg = 0;
boolean snt = true;
int val[6] = { 3810, 2810, 1948, 1290, 800, 445 };

void setup() {
  Serial.begin(115200);

  pinMode(A2, INPUT);
  analogSetPinAttenuation(A2, ADC_11db);

  bleKeyboard.begin();

  #ifdef BS
    SerialBT.begin("ESP32");
  #endif
}

unsigned long a2 = 0;

void loop() {
  a2 = 0;
  for (int i = 0; i < 128; ++i) {
    a2 += analogRead(A2);
  }
  a2 = a2 / 128;
  Serial.println(a2);
  #ifdef BS
    SerialBT.println(x);
  #endif
  if (bleKeyboard.isConnected()) {
    boolean reset = true;
    for (byte i = 0; i < 6; i++) {
      if (a2 >= val[i] - delta && a2 <= val[i] + delta) {
        if (tmg - millis() > 200 && snt == false) {
          snt = true;
          if (i == 0) {
            Serial.println('u');
            bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
          } else
          if (i == 1) {
            Serial.println('d');
            bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
          } else
          if (i == 2) {
            Serial.println('n');
            bleKeyboard.write('n');
          } else
          if (i == 3) {
            Serial.println('p');
            bleKeyboard.write('p');
          } else
          if (i == 4) {
            Serial.println('c');
            bleKeyboard.write('c');
          } else
          if (i == 5) {
            Serial.println('v');
            bleKeyboard.write('v');
          }
        }
        reset = false;
      }
    }
    if (reset) {
      for (byte i = 0; i < 6; i++) {
        tmg = millis();
        snt = false;
      }
    }
  }
  #ifdef BS
    delay(100);
  #else
    delay(100);
  #endif
}