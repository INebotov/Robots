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

    #ifdef DEBUG 
        Serial.begin(9600);
        delay(1000);
        Serial.println("Begining Initialization");
    #endif
    
    InitServo(); DP("Servo Initialized!");
    
    initRadio(); DP("Radio Initialized!"); 
    InitMototrs(); DP("Motors Initialized!");
}

SensorData motor;
bool Shoot = false;
long int LastShooted = 0;
void loop() {
    long int NowTime = millis();

    if (receiveData(motor)) {
        DP("Data Recived");

        MotorsCommand(motor); DP("Motor Command Sended");
        if (motor.Shoot && ServoReady && ((NowTime - LastShooted) > 1000)){
            DP("Shoot to true");
            Shoot = true;
            LastShooted = NowTime;
        }
    }

    if (Shoot && ServoOnPosition(NowTime, SERVO_SPUSK)){
        DP("Servo On SPUSK");
        Shoot = false;
        ServoReady = false;
    }

    if (!ServoReady){
        DP("Servo is not ready");
        if (!ServoVzveden && ServoOnPosition(NowTime, SERVO_VSVOD))
            ServoVzveden = true;
        
        if (ServoVzveden && ServoOnPosition(NowTime, SERVO_READY)){
            ServoReady = true;
            ServoVzveden = false;
        }
    }
}
