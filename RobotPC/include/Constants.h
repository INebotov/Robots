#define DEBUG

#define FREQUENCY       0x6f
#define PIPE            0xF0F0F0F0A1LL

#define SERVO_SPUSK     0 
#define SERVO_VSVOD     120
#define SERVO_READY     30


#define PIN_ENA 3 
#define PIN_ENB 6
#define PIN_IN1 2
#define PIN_IN2 4
#define PIN_IN3 5
#define PIN_IN4 7
#define PIN_SERVO 12


#define PIN_CE  9  
#define PIN_CSN 10 


#ifdef DEBUG 
#define DP(x) Serial.println(x)
#else 
#define DP(x)
#endif
