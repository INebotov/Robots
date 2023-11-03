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
    radio.begin();  
    radio.setChannel(FREQUENCY); 
    radio.setDataRate (RF24_1MBPS); 
    radio.setPALevel(RF24_PA_HIGH);
    radio.openWritingPipe(PIPE); 
}

bool receiveData(SensorData &data) {
  if (radio.available() >= sizeof(data)) {
    radio.read((char*)&data, sizeof(data));
    return true;
  }
  return false;
}
