/*
	DIO.h - Library for initialising digital-pins
 	for the BRDDS home automation system
 	Created by Bruce Helsen, February 21, 2014
 */
#include "Arduino.h"
#include "DIO.h"
DIO::DIO()
{
}

bool DIO::refresh(){
  /*
	checks if the pin is an input pin.
   	if so it compares the current with the previous value
   	if it is changed it will be saved
   	and the function will return 1
   	otherwise it will return 0
   */

  if(_enabled&&(_mode=='i')){
    if(_value!=digitalRead(_pin)){
      _value = digitalRead(_pin);
      return 1;
    }
  }
  else{
    return 0;
  }
}

int DIO::Pin(int pin){
  /*
	to set the pin:
   	DIO.Pin(value);
   	
   	to get the pin:
   	value=DIO.Pin();
   */
  if(pin == -1){
    return _pin;
  }
  else{
    //the pin still need to be validated
    _pin = pin;
  }
}

void DIO::Init(int pin, char mode, int value, int enabled){
  _pin =pin;
  _value =value;
  _enabled = enabled;
  _mode = mode;
  if(_mode=='i'){
    pinMode(_pin,INPUT);
  }
  else if(_mode=='o'||_mode=='p'){
    pinMode(_pin,OUTPUT);
  }
}

char DIO::Mode(char mode){
  if(mode == '0'){
    return _mode;
  }
  else{
    //the pin still need to be validated
    _mode = mode;
  }
}

int DIO::Enabled(int enabled){
  if(enabled == -1){
    return _enabled;
  }
  else{
    //the state still need to be validated
    _enabled = enabled;
  }	
}

int DIO::Value(int value){

  if(value == -1){//-1 is default value = get

    if(_mode=='i'){
	  //DIO::Refresh();
      _value = digitalRead(_pin);
      return _value;
    }
    else if(_mode=='o'||_mode=='p'){
      return _value;
    }
  }
  else{// not -1 => set
    //the value still need to be validated
    if(_mode=='o'){
      _value = value;
      digitalWrite(_pin,_value);
    }
    else if(_mode=='p'){//pwm
      _value = value;
      analogWrite(_pin,_value);      
    }
  }	
}



