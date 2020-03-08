#ifndef SevSegStepper_h
#define SevSegStepper_h

#include "Arduino.h"

class SevSegStepper
{
private:
  // Hardware pin numbers
  uint8_t _pinA;
  uint8_t _pinB;
  uint8_t _pinC;
  uint8_t _pinD;
  uint8_t _pinE;
  uint8_t _pinF;
  uint8_t _pinG;
  uint8_t _pinDot;

  int _testDelay = 250;
  int _animationDelay = 80;

  uint8_t _actPos = 0;

  const byte NUMBERS[10] = {
  // ABCDEFG.  
    0b11111100, // 0
    0b01100000, // 1
    0b11011010, // 2
    0b11110010, // 3
    0b01100110, // 4
    0b10110110, // 5
    0b10111110, // 6
    0b11100000, // 7
    0b11111110, // 8
    0b11110110  // 9
  };
  
  const byte UNLIMITED[8] = {
    0b10000000,
    0b01000000,
    0b00000010,
    0b00001000,
    0b00010000,
    0b00100000,
    0b00000010,
    0b00000100
  };

  const byte ROUND[6] = {
    0b10000000,
    0b01000000,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00000100
  };

  const byte DOWN[3] = {
    0b10000000,
    0b00000010,
    0b00010000
  };

  const byte DOWNUP[4] = {
    0b10000000,
    0b00000010,
    0b00010000,
    0b00000010
  };

  const byte UP[3] = {
    0b00010000,
    0b00000010,
    0b10000000
  };

  const byte ALL = 0b11111111;

  const byte DOT = 0b00000001;

  const byte NONE = 0b00000000;

  void write(byte sign);
  void show();

public:
  SevSegStepper(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG, uint8_t pinDot);

  void Test();
  void All();
  void Reset();
  void Off();
  void Inc();
  void Dec();
  void Set(uint8_t);
  void AnimateRound();
  void AnimateUnlimited();
  void AnimateDown();
  void AnimateDownUp();
  void AnimateUp();
  void Flash();
};

#endif