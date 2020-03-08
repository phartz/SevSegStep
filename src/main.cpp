#include <Arduino.h>
#include <SevSegStepper.h>
#include <OneButton.h>
#include <ServoCounter.h>

SevSegStepper segment(A0,A1,A2,A3,A4,A5,2,3);
ServoCounter servoCounter(7,6);

OneButton btnDown(4, true);
OneButton btnUp(5, true);

void btnDownClick(){
  segment.Dec();
  servoCounter.Dec();
}

void btnUpClick(){
  segment.Inc();
  servoCounter.Inc();
}

void setup() {
  btnDown.attachClick(btnDownClick);
  btnUp.attachClick(btnUpClick);
  segment.Reset();
  servoCounter.Init();
  servoCounter.Set(0);
  randomSeed(analogRead(0));
}

void loop() {
  btnDown.tick();
  btnUp.tick();

  for (int i = 1; i < 11; i++)
  {
    continue;
    servoCounter.Set(i * 10);
    delay(1000);
  }
  
  // servoCounter.Set(random(100));
  // delay(2000);
}