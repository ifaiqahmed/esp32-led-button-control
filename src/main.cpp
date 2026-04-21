#include <Arduino.h>

const int ledPin = 5;
const int buttonPin = 4;

bool ledState = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);

    Serial.println(ledState ? "LED ON" : "LED OFF");
    delay(200);
  }

  lastButtonState = buttonState;
}