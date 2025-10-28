#include <SPI.h>
#include <SD.h>

int cs = 10;
File myFile;

void setup() {
  Serial.begin(9600);
  while(!Serial){;}

  if(!SD.begin(cs)) { Serial.println("initialization failed"); while(1);}
  Serial.println("initialization done");

  myFile = SD.open("test.txt", FILE_WRITE);

  if(myFile)
  {
    Serial.print("Writing to test.txt");
    myFile.println("testing");
    myFile.close();
    Serial.println("done.");
  } else {
    Serial.println("error opening file");
  }


  myFile = SD.open("test.txt");
  if(myFile){Serial.println("test.txt:");

  while(myFile.available()) {Serial.write(myFile.read());}
  myFile.close();
  }
  else {Serial.println("error opening the file");}
}
void loop() {

}
