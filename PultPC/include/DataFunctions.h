struct SensorData {
  char P1;
  char P2;
  bool D11;
  bool D12;
  bool D21;
  bool D22;
  bool Shoot;
};

void sendData(const SensorData &data) {
  Serial.write((uint8_t*)&data, sizeof(data));
}

bool receiveData(SensorData &data) {
  if (Serial.available() >= sizeof(data)) {
    Serial.readBytes((char*)&data, sizeof(data));
    return true;
  }
  return false;
}
