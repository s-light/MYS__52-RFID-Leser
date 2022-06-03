/*
  RDM6300-125KHz-RFID

  based on www.mschoeffler.de Arduino Examples

  modified on 20 Jan 2020
  by Amir Mohammad Shojaee @ Electropeak
  https://electropeak.com/learn/interfacing-rdm6300-125khz-rfid-reader-module-with-arduino/

  20220531 s-light.eu stefan krüger
    extracted RFID code into extra file.
*/
#include <SoftwareSerial.h>

SoftwareSerial ssrfid = SoftwareSerial(2, 3);


void setup() {
  Serial.begin(115200);

  ssrfid.begin(9600);
  ssrfid.listen();

  Serial.println("RFID_125kHz_RDM6300__withIdDecoding.ino");
  Serial.println("INIT DONE");
}

void loop() {
  int32_t tag = RFID_update();
  if (tag > -1) {
      tag_found(tag);
  }
}


void tag_found(int32_t tag) {
  Serial.print("Found Tag: ");
  Serial.print(tag);
  Serial.println();
}
