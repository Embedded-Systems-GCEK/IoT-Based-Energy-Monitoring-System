#define pin 2
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