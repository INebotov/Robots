#include <SPI.h>
#include "Arduino.h"

#include <nRF24L01.h> 
#include <RF24.h>

// Код в загловочных файлах ибо Я художник и так вижу
#include "Constants.h"
#include "DataFunctions.h"
#include "RadioWave.h"

void setup() {
    Serial.begin(SERIAL_BOD); 
    initRadio(); 
    Serial.println("Working on: ");
    Serial.print("Freq: "); Serial.println(FREQUENCY); 
    Serial.print("Pipe: "); Serial.println(PIPE); 
}


SensorData motor;
void loop() {
    motor.P1 = 64;
    motor.P2 = 64;
    motor.D11 = true;
    motor.D21 = true;

    bool result = sendRadio(motor);
    Serial.print(result);
    Serial.println(" Radio Sended");
    
    delay(1000);
}
