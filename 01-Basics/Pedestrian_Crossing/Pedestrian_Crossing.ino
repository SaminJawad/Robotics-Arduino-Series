const int CAR_RED    = 8;
const int CAR_YELLOW = 9;
const int CAR_GREEN  = 10;
const int PED_RED    = 11;
const int PED_GREEN  = 12;
const int BUTTON_PIN = 2;

const unsigned long MIN_GREEN_TIME  = 3000;  // cars keep green at least this long
const unsigned long YELLOW_TIME     = 2000;
const unsigned long CLEARANCE_TIME  = 1000;  // all red, lets the road clear
const unsigned long WALK_TIME       = 5000;
const unsigned long WARNING_TIME    = 3000;  // pedestrian green blinks
const unsigned long BLINK_INTERVAL  = 250;

enum State { CARS_GREEN, CARS_YELLOW, CARS_RED, WALK, WALK_WARNING };

State state = CARS_GREEN;
unsigned long stateStart = 0;
bool requestPending = false;

void setup() {
  pinMode(CAR_RED, OUTPUT);
  pinMode(CAR_YELLOW, OUTPUT);
  pinMode(CAR_GREEN, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  enterState(CARS_GREEN);
}

void loop() {
  // Remember a press at any moment. Bounce is harmless: it only sets a flag.
  if (digitalRead(BUTTON_PIN) == LOW) {
    requestPending = true;
  }

  unsigned long elapsed = millis() - stateStart;

  switch (state) {
    case CARS_GREEN:
      setLights(LOW, LOW, HIGH, HIGH, LOW);
      if (requestPending && elapsed >= MIN_GREEN_TIME) enterState(CARS_YELLOW);
      break;

    case CARS_YELLOW:
      setLights(LOW, HIGH, LOW, HIGH, LOW);
      if (elapsed >= YELLOW_TIME) enterState(CARS_RED);
      break;

    case CARS_RED:
      setLights(HIGH, LOW, LOW, HIGH, LOW);
      if (elapsed >= CLEARANCE_TIME) enterState(WALK);
      break;

    case WALK:
      setLights(HIGH, LOW, LOW, LOW, HIGH);
      if (elapsed >= WALK_TIME) enterState(WALK_WARNING);
      break;

    case WALK_WARNING: {
      bool blinkOn = (elapsed / BLINK_INTERVAL) % 2 == 0;
      setLights(HIGH, LOW, LOW, LOW, blinkOn);
      if (elapsed >= WARNING_TIME) {
        requestPending = false;
        enterState(CARS_GREEN);
      }
      break;
    }
  }
}

void enterState(int newState) {
  state = (State)newState;
  stateStart = millis();
}

// Sets all five LEDs in one call
void setLights(int carR, int carY, int carG, int pedR, int pedG) {
  digitalWrite(CAR_RED, carR);
  digitalWrite(CAR_YELLOW, carY);
  digitalWrite(CAR_GREEN, carG);
  digitalWrite(PED_RED, pedR);
  digitalWrite(PED_GREEN, pedG);
}