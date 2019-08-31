//Define ticks for coil pulses
volatile unsigned int ticks;
unsigned int rpm = 0;
const int interruptPin = 2;
//Sets parameters
const int timeSample = 50;
const int timeFrame = 60000;
const int numCyl = 4;

void rev() {
  ticks++;
}

void setup() {
  pinMode(3, INPUT);
  digitalWrite(3, HIGH);
}

void loop() {
  // Number of coil ticks
  ticks = 0;
  attachInterrupt(digitalPinToInterrupt(interruptPin), rev, RISING);
  delay(timeSample);
  detachInterrupt(digitalPinToInterrupt(interruptPin));
  Serial.print("RPM: ");
  Serial.println(((timeFrame / timeSample) * ticks) / numCyl);
}
