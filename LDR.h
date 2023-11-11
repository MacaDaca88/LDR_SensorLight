#ifndef LDR_H
#define LDR_H

#if defined(__AVR_ATmega328P__) || (__AVR_ATmega168__)

#include <LowPower.h>

#endif

class ldrLed {
   bool powerSave;
public:
  ldrLed(int Led);
  void init();
  void on();
  void off();
  void adaptive(int MIN, int MAX, int ON, int OFF);
private:
  int _Led;
};

class ldr {
public:
  ldr(int Ldr, int LdrPwrPin, int PWRSAVE, int SCREENTIME, int Led, int PWROFF);
  void init();
  void off();
  void on();
  void Read();
  void PWRsave();
  void PWRsaveOff();
  void Display(int SCREENTIME);
  void DisplayPWRsave(int PWROFF);


private:
  int _Ldr;
  int _LdrPwrPin;
  int _PWRSAVE;
  int _SCREENTIME;
  int _Led;
  ldrLed ledInstance;  // Added instance of ldrLed
  int value;
  int output;
  unsigned long oldTime;
  int oldLdr;
  int _PWROFF;
};

#endif

#if defined(ESP8266) || (ESP32) || (__AVR_ATmega328P__) || (__AVR_ATmega168__)
// Only for boards with serial support
extern bool serial;
#else
#warning "No Serial.print"
#endif
