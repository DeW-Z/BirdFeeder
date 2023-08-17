#include <Arduino.h>
#include<ESP8266WiFi.h>

const int stepPin = 6;
const int dirPin = 5;
const int stepsPerRevolution = 200 * 32;
const int breakBeamPin = 2;
const int hallEffectPin = 3;
const int rstPin = 7;
const int slpPin = 8;
const int desiredRPM = 60;
const float microsecondDelay = 60.0 * 1000000 / (stepsPerRevolution * desiredRPM);
const int rpmMismatchThreshold = 5;
const int rpmReportingThreshold = 2;

volatile unsigned long lastPulseTime = 0;
volatile unsigned long lastRPMUpdateTime = 0;
unsigned long mismatchStartTime = 0;
unsigned long noRPMReportedStartTime = 0;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(rstPin, OUTPUT);
  pinMode(slpPin, OUTPUT);
  pinMode(breakBeamPin, INPUT);
  pinMode(hallEffectPin, INPUT_PULLUP);
  digitalWrite(rstPin, HIGH);
  digitalWrite(slpPin, HIGH);
  Serial.begin(115200);
  delay(2000);
  attachInterrupt(digitalPinToInterrupt(hallEffectPin), measureRPM, RISING);
  Serial.println("Setup complete.");
}

void loop() {
  int breakBeamState = digitalRead(breakBeamPin);
  if (breakBeamState == HIGH) {
    lastRPMUpdateTime = millis();
    noRPMReportedStartTime = 0; // Reset the no RPM reported counter
    Serial.println("Break Beam Sensor Activated, pausing...");
    delay(1000);
  } else {
    Serial.println("Spinning motor...");

    digitalWrite(dirPin, LOW);
    for (int x = 0; x < stepsPerRevolution; x++) {
      if (digitalRead(breakBeamPin) == HIGH) {
        lastRPMUpdateTime = millis(); // Reset last RPM update time
        noRPMReportedStartTime = 0; // Reset the no RPM reported counter
        Serial.println("Break Beam Sensor Activated, breaking loop...");
        break;
      }

      if (lastRPMUpdateTime > 0 && millis() - lastRPMUpdateTime > rpmReportingThreshold * 1000) {
        if (noRPMReportedStartTime == 0) {
          noRPMReportedStartTime = millis();
          Serial.println("No RPM reported, starting timer...");
        } else if (millis() - noRPMReportedStartTime >= rpmMismatchThreshold * 1000) {
          Serial.println("No RPM reported within threshold, stopping motor...");
          stopStepperMotor();
          digitalWrite(rstPin, LOW);
          digitalWrite(slpPin, LOW);
          while (true);
        }
      }

      digitalWrite(stepPin, HIGH);
      delayMicroseconds(microsecondDelay);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(microsecondDelay);
    }
  }
}

void stopStepperMotor() {
  digitalWrite(stepPin, LOW);
  Serial.println("Motor stopped.");
}

void measureRPM() {
  unsigned long currentPulseTime = micros();
  unsigned long pulseDuration = currentPulseTime - lastPulseTime;
  lastPulseTime = currentPulseTime;

  if (pulseDuration > 0) {
    float actualRPM = 60.0 / ((pulseDuration * 18) / 1000000.0);
    Serial.print("Actual RPM: ");
    Serial.println(actualRPM);
    lastRPMUpdateTime = millis();
    noRPMReportedStartTime = 0; // Reset the no RPM reported counter if an RPM is reported

    if (abs(actualRPM - desiredRPM) > desiredRPM * 0.1) {
      if (mismatchStartTime == 0) {
        mismatchStartTime = millis();
        Serial.println("RPM mismatch detected, starting timer...");
      } else if (millis() - mismatchStartTime >= rpmMismatchThreshold * 1000) {
        stopStepperMotor();
        while (true);
      }
    } else {
      mismatchStartTime = 0;
      Serial.println("RPM is within range, resetting timer.");
    }
  }
}
