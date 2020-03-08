#include <ServoCounter.h>

ServoCounter::ServoCounter(uint8_t pinDigit, uint8_t pinDeci)
{
  _pinDigit = pinDigit;
  _pinDeci  = pinDeci;
}

void ServoCounter::Init(){
  _servoDigit.attach(_pinDigit);
  _servoDeci.attach(_pinDeci);

  _servoDigit.write(_minDigit);
  _servoDeci.write(_minDeci);
  delay(100);
  _servoDigit.write(_maxDigit);
  _servoDeci.write(_maxDeci);
  delay(100);
  _servoDigit.write(_minDigit);
  _servoDeci.write(_minDeci);
}

void ServoCounter::moveTo(uint8_t number){
  int actDeci = _actPos / 10;
  int actDigit = _actPos % 10;

  int posDeci = number / 10;
  int posDigit = number % 10;

  int stepDeci = (posDeci - actDeci);
  int stepDigit = (actDigit - posDigit);

  actDeci = actDeci * 10 + _minDeci;
  actDigit = _minDigit - actDigit * 10;

  for (uint8_t i = 0; i < 10; i++)
  {
    actDeci += stepDeci;
    actDigit += stepDigit;
    _servoDeci.write(actDeci);
    _servoDigit.write(actDigit);
    delay(_moveDelay);
  }
  
  _actPos = number;
}

void ServoCounter::Inc(){
  if (_actPos == 99) return;
  moveTo(_actPos + 1);
}

void ServoCounter::Dec(){
  if (_actPos == 0) return;
  moveTo(_actPos - 1);
}

void ServoCounter::Set(uint8_t pos){
  moveTo(pos);
}
