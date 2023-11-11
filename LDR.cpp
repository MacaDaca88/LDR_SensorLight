// LDR.cpp

#include "LDR.h"
#include "Pins.h"

int value = 0;
int output = 0;
unsigned long oldTime = 0;
int oldLdr = 0;

/////////////////  LED   SETUP   ///////////////////////
ldrLed::ldrLed(int Led) {
  _Led = Led;
}

void ldrLed::init() {
  pinMode(_Led, OUTPUT);
}

void ldrLed::on() {
  digitalWrite(_Led, HIGH);
}

void ldrLed::off() {
  digitalWrite(_Led, LOW);
}

void ldrLed::adaptive(int MIN, int MAX, int ON, int OFF) {
  output = map(value, MIN, MAX, ON, OFF);
  analogWrite(_Led, output);
}

////////////////  LDR  SETUP  //////////////////////////
ldr::ldr(int Ldr, int LdrPwrPin, int PWRSAVE, int SCREENTIME, int Led, int PWROFF)
  : ledInstance(Led), powerSave(false) {
  _Ldr = Ldr;
  _LdrPwrPin = LdrPwrPin;
  _PWRSAVE = PWRSAVE;
  _SCREENTIME = SCREENTIME;
  _Led = Led;
  _PWROFF = PWROFF;
}

void ldr::init() {
  pinMode(_Ldr, INPUT);
  pinMode(_LdrPwrPin, OUTPUT);
  ledInstance.init();  // Initialize the LED instance
}

void ldr::off() {
  digitalWrite(_LdrPwrPin, LOW);
  ledInstance.off();  // Turn off the LED
}

void ldr::on() {
  digitalWrite(_LdrPwrPin, HIGH);
  ledInstance.on();  // Turn on the LED
  DisplayPWRsave(_PWROFF);
}

void ldr::Read() {
  on();
  value = analogRead(_Ldr);
  if (powerSave = true) {
    DisplayPWRsave(_PWROFF);  // Use _SCREENTIME directly
  } else {
    Display(_SCREENTIME);
  }
}

void ldr::PWRsave() {
  if (value - oldLdr >= 700) {
    Serial.println("Turning off due to significant light level Suggests Day Time");
  }
  oldLdr = value;
  off();
}

void ldr::PWRsaveOff() {
  on();
}

void ldr::Display(int SCREENTIME) {
  unsigned long time = millis();
  if (time - oldTime >= _SCREENTIME) {
    oldTime = time;
    _SCREENTIME = SCREENTIME;
    Serial.print("value  =  ");
    Serial.println(value);
    Serial.print("Output PWM  =  ");
    Serial.println(output);
  }
}

void ldr::DisplayPWRsave(int PWROFF) {
  unsigned long time = millis();
  if (time - oldTime >= _PWROFF) {
    oldTime = time;
    _PWROFF = PWROFF;
    Serial.print("value  =  ");
    Serial.println(value);
    Serial.print("Output PWM  =  ");
    Serial.println(output);
  }
}
