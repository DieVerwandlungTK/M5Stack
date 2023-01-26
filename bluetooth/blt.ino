#include <M5Stack.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup(){
    M5.begin();
    SerialBT.begin();
}

void loop(){
    if(M5.BtnA.wasPressed()){
        SerialBT.printf("ButtonA was pressed !\n");
    }
}