const int LED_PIN = 13;  // Pin connected to the LED

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED on
  delay(1000);                  // wait 1 second
  digitalWrite(LED_PIN, LOW);   // LED off
  delay(1000);                  // wait 1 second
}