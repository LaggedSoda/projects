#include <TMRpcm.h>
#include <SD.h>

TMRpcm audio;

void setup() {
  Serial.begin(9600);
  delay(200);

  if (!SD.begin(10)) {
  Serial.println("SD FAIL");
} else {
  Serial.println("SD OK");
}

  audio.speakerPin = 9;   // must be pin 9 on Uno

  if(!SD.begin(10)) {     // CS pin
    return;
  }

  audio.setVolume(5);     // 0 to 7
  audio.play("ESTHER.wav");
}

void loop() {}