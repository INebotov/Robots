struct SensorData {
    char P1;
    char P2;
    bool D11;
    bool D12;
    bool D21;
    bool D22;
    bool Shoot;
};

RF24 radio(PIN_CE, PIN_CSN); 
void initRadio(){
    if (!radio.begin()) {
        while (1) {
            DP("radio hardware not responding!");
        } // hold program in infinite loop to prevent subsequent errors
    }

    radio.setChannel(FREQUENCY); 
    radio.setDataRate (RF24_1MBPS); 
    radio.setPALevel(RF24_PA_HIGH);
    radio.openReadingPipe(1, PIPE); 
    radio.startListening();
}

bool receiveData(SensorData &data) {
    if (radio.available()) {
        uint8_t bytes = radio.getPayloadSize();
        if (bytes >= sizeof(data)){
            radio.read((char*)&data, sizeof(data));
            return true;
        }
    }
  return false;
}
