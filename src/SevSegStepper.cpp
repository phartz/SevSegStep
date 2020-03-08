#include "SevSegStepper.h"

SevSegStepper::SevSegStepper(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG, uint8_t pinDot){
  _pinA = pinA;
  _pinB = pinB;
  _pinC = pinC;
  _pinD = pinD;
  _pinE = pinE;
  _pinF = pinF;
  _pinG = pinG;
  _pinDot = pinDot;
  pinMode(_pinA, OUTPUT);
  pinMode(_pinB, OUTPUT);
  pinMode(_pinC, OUTPUT);
  pinMode(_pinD, OUTPUT);
  pinMode(_pinE, OUTPUT);
  pinMode(_pinF, OUTPUT);
  pinMode(_pinG, OUTPUT);
  pinMode(_pinDot, OUTPUT);
}

void SevSegStepper::All(){
  write(ALL);
}

void SevSegStepper::Test() {
  for (int i = 0; i < 10; i++)
  {
    write(NUMBERS[i]);
    delay(_testDelay * 4);
  }  
}

void SevSegStepper::write(byte sign){
  digitalWrite(_pinA,   (sign & 0b10000000) ? HIGH : LOW);
  digitalWrite(_pinB,   (sign & 0b01000000) ? HIGH : LOW);
  digitalWrite(_pinC,   (sign & 0b00100000) ? HIGH : LOW);
  digitalWrite(_pinD,   (sign & 0b00010000) ? HIGH : LOW);
  digitalWrite(_pinE,   (sign & 0b00001000) ? HIGH : LOW);
  digitalWrite(_pinF,   (sign & 0b00000100) ? HIGH : LOW);
  digitalWrite(_pinG,   (sign & 0b00000010) ? HIGH : LOW);
  digitalWrite(_pinDot, (sign & 0b00000001) ? HIGH : LOW);
}

void SevSegStepper::Reset(){
  _actPos = 0;
  show();
}

void SevSegStepper::show(){
  write(NUMBERS[_actPos]);
}

void SevSegStepper::Off(){
  write(NONE);
}

void SevSegStepper::Inc(){ 
  if ((_actPos + 1) > 9) Flash();
  (_actPos + 1) > 9 ? 9 : _actPos++;
  show();
}

void SevSegStepper::Dec(){ 
  if ((_actPos - 1) < 0) Flash(); 

  (_actPos - 1) < 0 ? 0 : _actPos--;
  show();
}

void SevSegStepper::Set(uint8_t pos){
  if (pos < 0) {
    _actPos = 0;
  } else if (pos > 9) {
    _actPos = 9;
  } else {
    _actPos = pos;
  }
  show();
}

void SevSegStepper::AnimateRound(){
  for (uint8_t i = 0; i < 6; i++)
  {
    write(ROUND[i]);
    delay(_animationDelay);
  }  
}

void SevSegStepper::AnimateUnlimited(){
  for (uint8_t i = 0; i < 8; i++)
  {
    write(UNLIMITED[i]);
    delay(_animationDelay);
  }  
}

void SevSegStepper::AnimateDown(){
  for (uint8_t i = 0; i < 3; i++)
  {
    write(DOWN[i]);
    delay(_animationDelay * 3);
  }  
}

void SevSegStepper::AnimateDownUp(){
  for (uint8_t i = 0; i < 4; i++)
  {
    write(DOWNUP[i]);
    delay(_animationDelay * 3);
  }  
}

void SevSegStepper::AnimateUp(){
  for (uint8_t i = 0; i < 3; i++)
  {
    write(UP[i]);
    delay(_animationDelay * 3);
  }  
}

void SevSegStepper::Flash(){
  return;
  for (uint8_t i = 0; i < 3; i++){
    write(NONE);
    delay(_animationDelay * 2);
    show();
    delay(_animationDelay * 2);
  }
}