#include "Arduino.h"
#include "DIO.h"
DIO::DIO(int pin)
{
	pinMode(pin,INPUT);
	_pin =pin;
    _value = 0;
	_enabled =0;
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
  }else{
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
	}else{
		//the pin still need to be validated
		_pin = pin;
	}
}

char DIO::Mode(char mode){
	if(mode == '0'){
		return _mode;
	}else{
		//the pin still need to be validated
		_mode = mode;
	}
}

int DIO::Enabled(int enabled){
	if(enabled == -1){
		return _enabled;
	}else{
		//the state still need to be validated
		_enabled = enabled;
	}	
}

int DIO::Value(int value){
	if(value == -1){
		return _value;
	}else{
		//the value still need to be validated
		_value = value;
	}	
}