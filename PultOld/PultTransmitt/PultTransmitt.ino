// #include <SPI.h> 
//#include <nRF24L01.h> 
//#include <RF24.h> 

#define PIN_CE  9 
#define PIN_CSN 10

// RF24 radio(PIN_CE, PIN_CSN); 

void setup() {
    Serial.begin(9600); 
    Serial.setTimeout(1); 

   //radio.begin();   
   //radio.setChannel(20);  
   //radio.setDataRate (RF24_1MBPS);
   //radio.setPALevel(RF24_PA_HIGH);
   //radio.openWritingPipe(0x5858585858LL); 
}

// 0 - Первый потенцометр 
// 1 - Второй потенцометр
// 2 - Кнопка направления 1
// 3 - Кнопка направления 2
// 4 - Выстрел
// 5 - Медленный режим
// 6 - Быстрый режим
#define BUFF_SIZE 7
char buff[BUFF_SIZE];

void loop() {
    // radio.write(potValue, sizeof(potValue)); 
}

void serialEvent() {
    Serial.readBytes(buff, BUFF_SIZE);
    Serial.write(buff, BUFF_SIZE);
}
