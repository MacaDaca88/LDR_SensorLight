////////////////////////////////////////////////////////////

// LDR = Light Dpendant Resistor


//////////////////////// Bill of materials/////////////////
/*

1x LDR
1x 100k resistor
1x Led


*/
////////////////////////End ///////////////////////////////
//#include "Arduino.h"
#include "Pins.h"
#include "LDR.h"

// select for power save mode
#define USE_PWRpin
//#define 5v_Pin
#define PWRSAVE 5000  // Powersave timer
#define MIN 0
#define MAX 1023
#define OFF 0
#define ON 255
#define SCREENTIME 500
#define PWROFF 5000

// Predifed Pins or Chose your OWN uncomment
//ldr ldr(A3, 13,5000,5000);  // LDR = Pin Defined  (A3 , D13)  LED_BUILTIN on when Sensor powered
ldr ldr(LDR, LDRPWRPIN, PWRSAVE, SCREENTIME, LED, PWROFF);  // LDR = Pin Defined in Pins.h   (A3 , D13)  LED_BUILTIN on when Sensor powered
//LdrLed ldrLed(9);  // Chose your own pin PWM
ldrLed ldrLed(LED);  // Led for displaying reading   DEFAULT D9  PWM


void setup() {

  // Initialize serial communication if availible
#if defined(ESP8266) || (ESP32) || (__AVR_ATmega328P__) || (__AVR_ATmega168__)
  Serial.begin(9600);  // Set the baud rate as needed
#endif
  ldr.init();  // Start the LDR
}

void loop() {
  ldr.PWRsave();  // Sleep till retest to save power
  ldr.Read();                          // Start with sensor on Take a reading  store in variable value
  ldrLed.adaptive(MIN, MAX, OFF, ON);  // Map and set LED brightness
#if (value - oldLdr >= 200)
  Serial.println("Turning on due to significant change in light level");
  value = oldLdr;
#endif
}
