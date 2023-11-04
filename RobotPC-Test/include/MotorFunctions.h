#define BoolToHL(b) ((b == 1) ? HIGH : LOW)

Servo shooter;

void InitMototrs(){
    pinMode(PIN_ENA, OUTPUT); 
    pinMode(PIN_ENB, OUTPUT); 
    pinMode(PIN_IN1, OUTPUT); 
    pinMode(PIN_IN2, OUTPUT);
    pinMode(PIN_IN3, OUTPUT);
    pinMode(PIN_IN4, OUTPUT);
    
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, LOW);
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, LOW);
}

void MotorsCommand(const SensorData &data){
    analogWrite(PIN_ENA, data.P1);
    analogWrite(PIN_ENB, data.P2);

    digitalWrite(PIN_IN1, BoolToHL(data.D11));
    digitalWrite(PIN_IN2, BoolToHL(data.D12));

    digitalWrite(PIN_IN3, BoolToHL(data.D21));
    digitalWrite(PIN_IN4, BoolToHL(data.D22));
}


int currPos = SERVO_READY;
long int lastTime;

bool ServoOnPosition(long int time, int pos){
    Serial.print(time);
    Serial.print(' ');
    Serial.print(pos);
    Serial.print(' ');
    Serial.print(lastTime);
    Serial.print(' ');
    Serial.println(currPos);

    if (pos == currPos){
        return true;
    }

    if ((time - lastTime) >= 50){
        if (pos > currPos)
            shooter.write(++currPos);
        else
            shooter.write(--currPos);

        lastTime = time;
    }
    return false;
}

bool ServoReady = false;
bool ServoVzveden = false;
void InitServo(){
    shooter.attach(PIN_SERVO);

    while (!ServoOnPosition(millis(), SERVO_SPUSK));
    while (!ServoOnPosition(millis(), SERVO_VSVOD));
    while (!ServoOnPosition(millis(), SERVO_READY));
    ServoReady = true;
}
