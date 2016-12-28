#include <SoftwareSerial.h>;
 
SoftwareSerial bluetooth(10, 11); // RX, TX int Power = 1; String receivedBluetoothString = 
""; void setup() {
  Serial.begin(9600);
  pinMode(Power,OUTPUT);
}
 
void loop() {
  while (bluetooth.available() > 0) {
 
    char receivedBluetoothChar = bluetooth.read();
    receivedBluetoothString += receivedBluetoothChar;
 
    if (receivedBluetoothChar == '\n') {
 
      if (receivedBluetoothString.toInt() == 576965) {
        digitalWrite(Power, HIGH);
        delay(100);
        digitalWrite(Power, LOW);
      }
 
      receivedBluetoothString = "";
    }
  }
}
