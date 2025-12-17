/*
  Author: Anamika VV
  Date: 12-12-2025
*/
#include <Arduino.h>
#define pin 2

/*
1.Initialize serial monitor
2.Initialize ESP8266 ? i dont know
3.Display current on serial monitor
4.Show the result
5.Go to step 4
*/

int d;
void setup() {
  d=5000;
  pinMode(pin, OUTPUT);
}

void loop() {
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(d);               // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(d);               // wait for a second
}
