char inByte;      // a variable to read incoming serial data into
int buffer[5];// buffer voor 5 bytes te onthouden
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  Serial.println("Voer de 5 addres bytes hexadecimaal in en maak gebruik van 2 digits per byte:");
  for(int i=0; i<5;i++){//voor elke van de 5 bytes
    buffer[i]= askVar() * 16 + askVar();//de eerste hex digit * 16, de 2de gewoon optellen
  }
  Serial.print("0x ");//buffer hex uitprinten
  for(int j=0;j<5;j++){
    Serial.print(buffer[j],HEX);
    if(j<4)Serial.print(" - ");
  }
  Serial.println();//buffer dec uitprinten
  Serial.print("DEC: ");
  for(int j=0;j<5;j++){
    Serial.print(buffer[j],DEC);
    if(j<4)Serial.print(" - ");
  }
  Serial.println();
}
int askVar(){//blijft gaan tot hij een hex waarde kan returnen

  while(Serial.available()<=0){//wacht totdat er data is voor deze ongeduldige jongen
  }
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    inByte = Serial.read();
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
