const int BUTTON_PIN = 2;
const int LED_PIN    = 8;

bool ledState = false;
int lastButtonState = HIGH;  // HIGH = not pressed (INPUT_PULLUP)

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState != lastButtonState) {
    delay(20);                           // wait out bounce on press & release
    buttonState = digitalRead(BUTTON_PIN);

    if (buttonState != lastButtonState) {
      if (buttonState == LOW) {          // confirmed press
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
      }
      lastButtonState = buttonState;
    }
  }
}