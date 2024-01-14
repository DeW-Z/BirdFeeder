#include <Arduino.h>
#include <TMCStepper.h>
#include <SoftwareSerial.h>

#define RMS_VALUE                1350   // SET YOUR MOTORS AMPERAGE HERE IN mA. 1350 = 1.35amps. RECOMMEND 80% OF LISTED VALUE.
#define REVERSE_DIRECTION        0      // Set to 1 to reverse direction, 0 for normal direction
#define ENABLE_STALL_HANDLING    0      // **BETA** Set to 1 to enable, 0 to disable
//
//////// EDIT BELOW THIS AT YOUR OWN RISK. DAMAGE MAY OCCUR. ////////
//
#define TOFF_VALUE               4
#define stallPin                 7
#define EN_PIN                   12
#define SW_RX                    9
#define SW_TX                    8
#define statusPin                4
#define breakBeamPin             2
#define accPin                   6
#define speedAdj                 A1
#define DRIVER_ADDRESS           0b00
#define RESET_DELAY              5000
#define R_SENSE                  0.11f
#define STALL_VALUE              0
#define SG_THRESHOLD             3
#define MAX_COUNT                3
#define TIME_PERIOD              1000
unsigned int stallCount = 0;
unsigned long lastCheckTime = 0;

SoftwareSerial SoftSerial(SW_RX, SW_TX);

TMC2209Stepper driver(&SoftSerial, R_SENSE, DRIVER_ADDRESS);

using namespace TMC2209_n;

void setup() {
  Serial.begin(115200);
  while(!Serial);
  driver.beginSerial(115200);
  SoftSerial.begin(115200);

  pinMode(statusPin, OUTPUT);
  pinMode(stallPin, INPUT);
  pinMode(breakBeamPin, INPUT);
  pinMode(accPin, INPUT);
  pinMode(statusPin, OUTPUT);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(statusPin, HIGH);
  digitalWrite(EN_PIN, LOW);
 

  driver.begin();
  driver.intpol(true);
  driver.en_spreadCycle(0);
  driver.toff(TOFF_VALUE);
  driver.blank_time(24);
  driver.rms_current(RMS_VALUE);
  driver.mstep_reg_select(true);
  driver.microsteps(4);
  driver.TCOOLTHRS(0xFFFFF);
  driver.semin(5);
  driver.semax(2);
  driver.sedn(0b01);
  driver.SGTHRS(STALL_VALUE);
  driver.pdn_disable(true);
}

void loop() {
  digitalWrite(EN_PIN, LOW);
  driver.SGTHRS(STALL_VALUE);
  delay(500);

  int potValue = analogRead(speedAdj);
  int mappedValue = map(potValue, 0, 1023, 0, -100);
  #if REVERSE_DIRECTION
   mappedValue = -mappedValue;
  #endif
  driver.VACTUAL(mappedValue);

  int breakBeamState = digitalRead(breakBeamPin);
  int accPinState = digitalRead(accPin);
  int stallPinState = digitalRead(stallPin);
  static unsigned long stallDetectedTime = 0;

  if (breakBeamState == LOW) {
    handleBreakBeam();
  } else if (stallPinState == HIGH) {
    //handleStall();
    stallDetectedTime = millis();
    driver.VACTUAL(mappedValue);
  } else if (millis() - stallDetectedTime > RESET_DELAY) {
    driver.VACTUAL(mappedValue);
  }
  //Serial.println(getDiagnosticInfo());
#if ENABLE_STALL_HANDLING
  if (driver.SG_RESULT() < SG_THRESHOLD) {
    if (millis() - lastCheckTime <= TIME_PERIOD) {
      stallCount++;
    } else {
      stallCount = 1;
      lastCheckTime = millis();
    }
  } 

  if (stallCount >= MAX_COUNT) {
    handleStall();
    stallCount = 0;
    lastCheckTime = millis();
  }
#endif
}

void handleBreakBeam() {
  driver.VACTUAL(0);
  Serial.print("Motor stopped due to break beam sensor.   ");
  flashStatusPin(1, 250);
}

void handleStall() {
  driver.VACTUAL(0);
  driver.SGTHRS(0);
  Serial.print("Jam Detected.   ");
  flashStatusPin(50, 50);
  digitalWrite(EN_PIN, HIGH);
  delay(50);
  digitalWrite(EN_PIN, LOW);
  
}

void flashStatusPin(int times, int delayTime) {
  for (int i = 0; i < times; i++) {
    digitalWrite(statusPin, HIGH);
    delay(delayTime);
    digitalWrite(statusPin, LOW);
    delay(delayTime);
  }
}

String getDiagnosticInfo() {
  int breakBeamState = digitalRead(breakBeamPin);
  String info = "Diag Status: ";
  info += digitalRead(stallPin);
  info += " ";
  info += driver.cs2rms(driver.cs_actual()), DEC;
  info += " ";
  info += driver.SG_RESULT(), DEC;
  info += "       ";
  info += driver.SGTHRS();
  info += " ";
  return info;
}
  