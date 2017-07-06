#define WIRE_PIN 0
#define ONEWIRE_CRC 1
#define ONEWIRE_CRC8_TABLE 1

#include <iostream>
#include <wiringPi.h>
#include <stdio.h>
#include "OneWire.h"

using namespace std;

int main() {
  uint8_t addr[8];

  wiringPiSetup();
  OneWire iButton(WIRE_PIN);
  pinMode(WIRE_PIN, OUTPUT);

  delay(1000);

  cout << "Start reading..." << endl;

  while(true){

    while( ! iButton.search(addr)){
      iButton.reset_search();
    }

    cout << "Key readed: ";
    for(int i = 0; i < 8; i++) {
      printf("%02X ", addr[i]);
    }
    cout << endl;

    uint8_t crc = OneWire::crc8(addr, 7);
    if(crc != addr[7]){
      printf("CRC: %02X != %02X\n", crc, addr[7]);
    }

    delay(2000);
  }
}
