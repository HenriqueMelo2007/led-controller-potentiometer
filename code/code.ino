#define POTENTIOMETER A5

int mappedValue;

void turnOnOffLEDs(int mappedValue);

void setup() {
  pinMode(POTENTIOMETER, INPUT);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  mappedValue = map(analogRead(POTENTIOMETER), 0, 1023, 0, 8);
  turnOnOffLEDs(mappedValue);
}

void turnOnOffLEDs(int mappedValue) {
  for (int i = mappedValue - 8; i < 0; i++) {
    digitalWrite(i + 10, LOW);
  }

  for (; mappedValue > 0; mappedValue--) {
    digitalWrite(mappedValue + 1, HIGH);
  } 
}