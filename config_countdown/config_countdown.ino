
void setup(){
  Serial.begin(9600);
  Serial.println("Press any key to get in config mode");
  int teller = 0;
  unsigned long tijd = millis();
  while((millis()-tijd)<10000){
    //check for serial data
    if((millis()-tijd)>=(teller*1000)){
      Serial.write(7);// system beeeeep!!!
      Serial.print(10-teller);
      Serial.print("..");
      teller++;
    }
    if(Serial.available()){
      Serial.println();
      Serial.println("You pressed a key");
      editSettings();

    }
  }
  Serial.println();
  Serial.println("Starting rf");

}

void loop(){
}

void editSettings(){
  Serial.println();
    Serial.println("Druk op de bijhorende key van de optie die je wilt:");
  Serial.println("key\tOptie");
  String optie[] = {
    "a\tVerander het addres","e\tVerlaat de instellingen"  };
  for(int i = 0;i<2;i++){
    Serial.println(optie[i]);
  }
  handleKeuze();
}
void handleKeuze(){
while(!Serial.available()){} //wacht op input
  switch (Serial.read()) {
  case 'a':
    Serial.println("Bravo!! je koos voor het addres aan te passen");
    while(true){}
    break;
  case 'e':
    Serial.println("Aaah zit da zo wil je al weg misschien?");
    break;
  default: 
    Serial.println("Verkeerde toets");
    handleKeuze();//probeer nog maar eens hopelijk ist deze keer beter
}
  
  
}


