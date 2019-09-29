#include <SD.h>
#include <TMRpcm.h>

#define SD_ChipSelectPin 4

TMRpcm tmrpcm;

void setup() {
  tmrpcm.speakerPin = 9;

  if (!SD.begin(SD_ChipSelectPin)) {

    return;
  }

  tmrpcm.setVolume(6);
  tmrpcm.play("1"); 
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
