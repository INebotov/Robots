#include "SPI.h"
#include "Arduino.h"

#include <nRF24L01.h> 
#include <RF24.h>
#include <Servo.h>

// Код в загловочных файлах ибо Я художник и так вижу
#include "Constants.h"
#include "RadioWave.h"
#include "MotorFunctions.h"

void setup() {
    Serial.begin(9600);
    delay(1000);
    Serial.println("Begining Initialization");


    initRadio(); DP("Radio Initialized!"); 
//    InitMototrs(); DP("Motors Initialized!");
//    InitServo(); DP("Servo Initialized!");
 //   shooter.attach(PIN_SERVO);
}

//int turn = 0;

SensorData motor;
void loop() {
    receiveData(motor); 
}
