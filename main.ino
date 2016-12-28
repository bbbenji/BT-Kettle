#include <SoftSerial.h>
#include <TinyPinChange.h>

SoftSerial bluetooth(3, 4); // RX, TX
int Power = 1;
String receivedBluetoothString = "";

void setup() {
  Serial.begin(9600);
  pinMode(Power,OUTPUT);
  bluetooth.begin(57600); //??
}

void loop() {
  while (bluetooth.available() > 0) {

    char receivedBluetoothChar = bluetooth.read();
    receivedBluetoothString += receivedBluetoothChar;

    if (receivedBluetoothChar == '\n') {

      if (receivedBluetoothString.toInt() == 576965) {
        digitalWrite(Power, HIGH);
        delay(5000);
        digitalWrite(Power, LOW);
      }

      receivedBluetoothString = "";
    }
  }
}