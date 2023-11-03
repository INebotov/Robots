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
}

SensorData motor;
void loop() {
    if (receiveData(motor)) {
        sendRadio(motor);
    }
}
