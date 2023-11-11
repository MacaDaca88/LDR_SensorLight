# LDR_SensorLight
 Simple Library to handle all the functions of LDR and Serial.print and map to LED 



 use following calls 

 for LDR sensor 

ldr.init();
ldr.on();
ldr.off();
ldr.Read();
ldr.PWRsave();
ldr.PWRsaveOff();
ldr.Display(int SCREENTIME);
ldr.DisplayPWRsave(int PWROFF);


for inbuilt Led 


ldrLed.init();
ldrLed.on();
ldrLed.off();
ldrLed.adaptive();