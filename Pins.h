/*/////////////////////Pin Definitions////////////////////

Edit to suit each pin is PWM (RED,GREEN,BLUE)

LDR = analog INPUT
LDRPWRPIN = Power leg to LDR
LED = LED??
////////////////////////////////////////////////////////*/
#ifndef PINS_H
#define PINS_H
#if defined(__AVR_ATmega328P__) || (__AVR_ATmega168__)
// Check if compiling for ATmega328p (e.g., Arduino Nano)
#define LDR A0
#define LDRPWRPIN 13
#define LED 9
////////////////////////////////////////////////////////

#elif defined(__AVR_ATtiny85__)  // Check if compiling for ATtiny85
// Burn Bootloader at 8MHz Internal Clock  For (1000ms = 1sec)
#define LDR A3
#define LDRPWRPIN 4
#define LED 1

////////////////////////////////////////////////////////
#elif defined(ESP8266)
// Check if compiling for ESP8266 (e.g., Wemos D1 R2 & mini)
#define LDR A0
#define LDRPWRPIN 8
#define LED 4

///////////////////////////////////////////////////////
#elif defined(ESP32)
// Check if compiling for ESP32  (e.g., ESP32 38pin("ESP32 DEV module"))
#define LDR A0
#define LDRPWRPIN 27
#define LED 26

//////////////////////////////////////////////////////
#else
#error "Unsupported board selected"
#error "Define New Board Or Pins"
bool serial = false;



#endif
#endif
