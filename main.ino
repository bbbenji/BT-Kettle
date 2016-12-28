#include <SoftwareSerial.h>;
 
SoftwareSerial bluetooth(10, 11); // RX, TX
int Power = 2;
int Up = 3;
int Down = 4;
int Hold = 5;
int Temp = 6;
String receivedBluetoothString = "";
 
void setup() {
  bluetooth.begin(9600);
  pinMode(Power, OUTPUT);
  pinMode(Up, OUTPUT);
  pinMode(Down, OUTPUT);
  pinMode(Hold, OUTPUT);
  pinMode(Temp, OUTPUT);
}
 
void loop() {
  while (bluetooth.available() > 0) {
 
    char receivedBluetoothChar = bluetooth.read();
    receivedBluetoothString += receivedBluetoothChar;
 
    if (receivedBluetoothChar == '\n') {
 
      if (receivedBluetoothString.toInt() == 576965) {
        digitalWrite(Power, HIGH);
        delay(200);
        digitalWrite(Power, LOW);
      }
 
      if (receivedBluetoothString.toInt() == 488230) {
        digitalWrite(Up, HIGH);
        delay(200);
        digitalWrite(Up, LOW);
      }
 
      if (receivedBluetoothString.toInt() == 887425) {
        digitalWrite(Down, HIGH);
        delay(200);
        digitalWrite(Down, LOW);
      }
 
      if (receivedBluetoothString.toInt() == 999888) {
        digitalWrite(Hold, HIGH);
        delay(200);
        digitalWrite(Hold, LOW);
      }
 
      if (receivedBluetoothString.endsWith("Slider\n")) {
        analogWrite(Temp, receivedBluetoothString.toInt());
      }
 
      receivedBluetoothString = "";
    }
  }
}