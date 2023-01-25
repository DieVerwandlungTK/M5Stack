#include <M5Stack.h>
#include <wire.h>

void setup(){

  M5.begin();  //初期化

  M5.Lcd.setTextColor(GREEN, WHITE);  //第1引数で文字色 第2引数で背景色

  M5.Lcd.setTextSize(5); //1~7でサイズ指定

  M5.Lcd.println("Hello World !");
}

void loop(){
}