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
    #endif

    initRadio(); DP("Radio Initialized!"); 
    InitMototrs(); DP("Motors Initialized!");
    InitServo(); DP("Servo Initialized!");
}

SensorData motor;
bool Shoot = false;
void loop() {
    if (receiveData(motor)) {
        DP("Data Recived");
        
        MotorsCommand(motor); DP("Motor Command Sended");
        if (motor.Shoot && ServoReady){
            DP("Shoot to true");
            Shoot = true;
        }
    }

    if (Shoot && ServoOnPosition(millis(), SERVO_SPUSK)){
        DP("Servo On SPUSK");
        Shoot = false;
        ServoReady = false;
    }

    if (!ServoReady){
        DP("Servo is not ready");
        if (!ServoVzveden && ServoOnPosition(millis(), SERVO_VSVOD))
            ServoVzveden = true;
        else if (ServoOnPosition(millis(), SERVO_READY)){
            ServoReady = true;
            ServoVzveden = false;
        }
    }
}
