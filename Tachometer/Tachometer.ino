volatile unsigned int ticks;
const int interruptPin = 2;

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
  delay(50);
  detachInterrupt(digitalPinToInterrupt(interruptPin));
  ticks = ((60000 / 50) * ticks) / 2;
  Serial.print("RPM: ");
  Serial.println(ticks);
}
