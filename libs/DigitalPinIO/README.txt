To make an object:
	DIO objectName;

Initisialise it:
	objectName.Init(int pin, char mode ='i', int value = 0, int enabled = 0);
		pin: digital pin number
		mode:(default input)
			-'i'=INPUT
			-'o'=OUTPUT
			-'p'=PWM OUTPUT
		value:	(default=0)
			digital 0-1
			pwm	0-255
		enable:	(default = 0)
			is used in refresh()
			if true refresh() will return 1 if the input data is changed
Set a pin:
	objectName.Pin(pinNumber);
Get a pin:
	int pinNumber = objectName();
	
char Mode(char mode = '0');//see pin and initialise

int Enabled(int enabled = -1);//see pin and initialise

int Value(int value = -1);//see pin and initialise

bool refresh();
	checks if the input on the pin has changed
	if so it will update the .Value
	and the function will also return 1