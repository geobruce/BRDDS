struct pin
{
  boolean enabled; // 
  char mode; /// d = digitalOutput, i = digital input, p = analog output (pwm)(0-255), a = analog input(0-1023)
  int value;
};

pin aansluiting[14];

void setup() {
  for(int pin = 0; pin<14; pin++){
    aansluiting[pin].mode=1;
    aansluiting[pin].value=0;       
  }
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Pin\tMode\tWaarde");
  for(int pin = 0; pin<14; pin++){
    Serial.print(pin);
    Serial.print("\t");
    Serial.print(aansluiting[pin].mode=1);
    Serial.print("\t");
    Serial.println(aansluiting[pin].value=0);    
  }
}
void sendChange(byte pin, int value){
  Serial.print("Pin: ");
  Serial.print(pin);
  Serial.print("\tWaarde: ");
  Serial.println(value);
}
void checkPinnen(){
  for(int pin = 0; pin<14; pin++){
    if(aansluiting[pin].mode==1){//if input pin => refresh value
      if(aansluiting[pin].value!=digitalRead(pin)){
        aansluiting[pin].value=digitalRead(pin);
        //roep dat de waarde is veranderd
        sendChange(pin,aansluiting[pin].value);
      }
    }
  }
}

// the loop routine runs over and over again forever:
void loop() {
  checkPinnen();
  delay(1000);
  //Serial.println();
}
