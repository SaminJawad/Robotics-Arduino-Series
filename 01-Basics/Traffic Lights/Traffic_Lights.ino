const int RED_PIN    = 8;
const int YELLOW_PIN = 9;
const int GREEN_PIN  = 10;

const int GREEN_TIME  = 3500;  // ms
const int YELLOW_TIME = 2000;  // ms
const int RED_TIME    = 3500;  // ms

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  setLights(LOW, LOW, HIGH);   // green
  delay(GREEN_TIME);

  setLights(LOW, HIGH, LOW);   // yellow
  delay(YELLOW_TIME);

  setLights(HIGH, LOW, LOW);   // red
  delay(RED_TIME);
}

// Sets all three LEDs in one call so only one color is ever on
void setLights(int red, int yellow, int green) {
  digitalWrite(RED_PIN, red);
  digitalWrite(YELLOW_PIN, yellow);
  digitalWrite(GREEN_PIN, green);
}