#include <DIO.h>

DIO led;
void setup(){
  Serial.begin(9600);
  led.Init(13, 'o');//pin 13, 'o'= output, value 0
}

void loop(){
  led.Value(0);
  delay(900);
  led.Value(1);
  delay(100);

}

