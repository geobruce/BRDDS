/*
	DIO.h - Library for initialising digital-pins
 	for the BRDDS home automation system
 	Created by Bruce Helsen, February 21, 2014
 */
#ifndef DIO_h
#define DIO_h

#include "Arduino.h"

class DIO
{
public:
  DIO();
  void Init(int pin, char mode ='i', int value = 0, int enabled = 0);
  int Pin(int pin = -1);
  char Mode(char mode = '0');
  int Enabled(int enabled = -1);
  int Value(int value = -1);
  bool refresh();
private:
  int _pin;
  char _mode;
  int _enabled;
  int _value;
};

#endif
