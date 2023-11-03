RF24 radio(PIN_CE, PIN_CSN); 

void initRadio(){
    radio.begin();  
    radio.setChannel(FREQUENCY); 
    radio.setDataRate (RF24_1MBPS); 
    radio.setPALevel(RF24_PA_HIGH);
    radio.openWritingPipe(PIPE); 
}

void sendRadio(const SensorData &data) {
  radio.write((uint8_t*)&data, sizeof(data));
}
