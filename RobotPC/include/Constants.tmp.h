#define DEBUG

#define FREQUENCY       ${FREQUENCY}
#define PIPE            ${PIPE}

#define SERVO_SPUSK     ${SERVO_SPUSK} 
#define SERVO_VSVOD     ${SERVO_VSVOD}
#define SERVO_READY     ${SERVO_READY}


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
