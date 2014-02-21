#include <EEPROM.h>
byte addres[5];
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  //  SplashScreen();

  if(ReadAddres()){
    //print the addres
    Serial.print("Addres ");
    printAddres();
  }
  else{
    //ask for addres
    Serial.println("Geen addres");
    GetAddres();
    SaveAddres();
  }


}

// the loop routine runs over and over again forever:
void loop() {

}


int ReadAddres(){//reads addres from eeprom if all zero it means there is no addres it wil return -1 otherwise 1
  int i,t=0;
  for(i=0;i<5;i++){
    addres[i] = EEPROM.read(i);
    t+= addres[i];
  }
  if(t>0){
    return 1;
  }//there is an addres
  else{
    return -1;
  }
}
void GetAddres(){
  Serial.println("Voer de 5 addres bytes hexadecimaal in en maak gebruik van 2 digits per byte:");
  for(int i=0; i<5;i++){//voor elke van de 5 bytes
    addres[i]= askVar() * 16 + askVar();//de eerste hex digit * 16, de 2de gewoon optellen
  }
}
void SaveAddres(){
  for(int a = 0;a<5;a++){
    EEPROM.write(a, addres[a]);
    Serial.print("Het addres: ");
    Serial.print("0x");
    Serial.println(" is opgeslagen in het EEPROM geheugen.");
  }
  for(int i = 0; i<5;i++){
      if(addres[i]<0x10) Serial.print("0");
      Serial.print(addres[i],HEX);
      if (i<4) Serial.print(" ");
    }

}
void printAddres(){

  Serial.print("0x");
  for(int i = 0; i<5;i++){
    if(addres[i]<0x10) Serial.print("0");
    Serial.print(addres[i],HEX);
    if (i<4) Serial.print(" ");
  }
  Serial.print("    ");
  for(int i = 0; i<5;i++){
    Serial.print(addres[i],DEC);
    if (i<4) Serial.print(" - ");
  }
  Serial.println();
}
void SplashScreen(){//vet gaaf logo printen
  Serial.print("\n"
    "__/\\\\\\\\\\\\\\\\\\\\\\\\\\______/\\\\\\\\\\\\\\\\\\______/\\\\\\\\\\\\\\\\\\\\\\\\_____/\\\\\\\\\\\\\\\\\\\\\\\\________/\\\\\\\\\\\\\\\\\\\\\\___        \n"
    " _\\/\\\\\\/////////\\\\\\__/\\\\\\///////\\\\\\___\\/\\\\\\////////\\\\\\__\\/\\\\\\////////\\\\\\____/\\\\\\/////////\\\\\\_       \n"
    "  _\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_____\\/\\\\\\___\\/\\\\\\______\\//\\\\\\_\\/\\\\\\______\\//\\\\\\__\\//\\\\\\______\\///__      \n"
    "   _\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\__\\/\\\\\\\\\\\\\\\\\\\\\\/____\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\___\\////\\\\\\_________     \n"
    "    _\\/\\\\\\/////////\\\\\\_\\/\\\\\\//////\\\\\\____\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\______\\////\\\\\\______    \n"
    "     _\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\____\\//\\\\\\___\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_________\\////\\\\\\___   \n"
    "      _\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_____\\//\\\\\\__\\/\\\\\\_______/\\\\\\__\\/\\\\\\_______/\\\\\\___/\\\\\\______\\//\\\\\\__  \n"
    "       _\\/\\\\\\\\\\\\\\\\\\\\\\\\\\/__\\/\\\\\\______\\//\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\\\/___\\/\\\\\\\\\\\\\\\\\\\\\\\\/___\\///\\\\\\\\\\\\\\\\\\\\\\/___ \n"
    "        _\\/////////////____\\///________\\///__\\////////////_____\\////////////_______\\///////////_____\n\n\n\n"
    );
}
int askVar(){//blijft gaan tot hij een hex waarde kan returnen

  while(Serial.available()<=0){//wacht totdat er data is voor deze ongeduldige jongen
  }
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    char inByte = Serial.read();
    /*
    0-9 ascii 48-57 => ascii-48 = dec waarde
     A-F ascii 65-70 => ascii-55 = dec waarde
     a-f ascii 97-102=> ascii-87 = dec waarde
     */
    if(inRange(inByte,'0','9')){
      //Serial.print(inByte-'0');
      return(inByte-'0');
    }
    else
      if(inRange(inByte,'a','f')){
        //Serial.print(inByte-'a'+10);
        return(inByte-'a'+10);
      }
      else 
        if(inRange(inByte,'A','F')){
        //Serial.print(inByte-'A'+10);
        return(inByte-'A'+10);
      }
    else{//als het geen HEX digit is van 0-F of 0-f dan opnieuw oproepen om spaties eruit te filteren
      askVar();
    }
  }
}
boolean inRange(int waarde, int laagste, int hoogste){
  if((waarde>=laagste)&&(waarde<=hoogste)) return 1;
  return 0;
}

