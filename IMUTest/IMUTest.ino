#define M5STACK_MPU6886
 #include <M5Stack.h>
 
 void setup(){
     M5.begin();
     M5.Power.begin();
     M5.IMU.Init();
     M5.Lcd.setTextSize(2);
 }
 
 float accX = 0, accY = 0, accZ = 0;
 float gyroX = 0, gyroY = 0, gyroZ = 0;
 float pitch = 0, roll = 0, yaw = 0;
 
 
 void loop(){
     M5.IMU.getAccelData(&accX, &accY, &accZ);
     M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
     M5.IMU.getAhrsData(&pitch, &roll, &yaw);
 
     M5.Lcd.fillScreen(BLACK);
   
     M5.Lcd.setCursor(0, 65);
     
     M5.Lcd.printf("acc (%5.2lf,%5.2lf,%5.2lf)\n\n", accX, accY, accZ);
     M5.Lcd.printf("gyro(%5.2lf,%5.2lf,%5.2lf)\n\n", gyroX, gyroY, gyroZ);
     M5.Lcd.printf("Ahrs(%5.2lf,%5.2lf,%5.2lf)\n\n", pitch, roll, yaw);
 
     delay(1);
 }
