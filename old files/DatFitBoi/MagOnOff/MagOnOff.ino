#define MAG_PIN 11

void setup() {
  pinMode(MAG_PIN, OUTPUT);
}

void loop() {
  digitalWrite(MAG_PIN, HIGH);
  delay(1000);
  digitalWrite(MAG_PIN, LOW);
  delay(1000);
}
