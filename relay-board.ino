#include "Particle.h"
#define relay1 D1
#define relay2 D2
#define relay3 D3
#define relay4 D4
#define relay5 D5
#define relay6 D6
#define relay7 D7
#define relay8 D8
#define string "on"

Servo bedroomServo;
Servo bathroomServo;

void setup(){
    pinMode(A0, OUTPUT);
    pinMode(D14, OUTPUT);
    
    bedroomServo.attach(A0);
    bathroomServo.attach(D14);
    
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    pinMode(relay5, OUTPUT);
    pinMode(relay6, OUTPUT);
    pinMode(relay7, OUTPUT);
    pinMode(relay8, OUTPUT);
    
    //written high means theyre off, and low means on
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
    digitalWrite(relay5, HIGH);
    digitalWrite(relay6, HIGH);
    digitalWrite(relay7, HIGH);
    digitalWrite(relay8, HIGH);
    
    //subscribe to events from IFTTT relay only
    Particle.subscribe("relay_off", relayOff);
    Particle.subscribe("relay_on", relayOn);
    Particle.subscribe("christmas", christmas);
    Particle.subscribe("lights", switchLights);
}

void loop(){
    
}

void switchLights(const char *event, const char *data){
    if(strcmp(data, "bothOn")){
        pinMode(A0, OUTPUT);
        pinMode(D14, OUTPUT);
    
        bathroomServo.write(0);
        bedroomServo.write(0);
    }
    if(strcmp(data, "bothOff")){
        pinMode(A0, OUTPUT);
        pinMode(D14, OUTPUT);
    
        bathroomServo.write(40);
        bedroomServo.write(40);
    }
}

void christmas(const char *event, const char *data){
    if(strcmp(data, "turnOn") == 0){
        digitalWrite(relay4, LOW);
        digitalWrite(relay5, LOW);
    } 
    else{
        digitalWrite(relay4, HIGH);
        digitalWrite(relay5, HIGH);
    }
    
}

void relayOn(const char *event, const char *data){
    if(strcmp(data,"relay4")==0)  digitalWrite(relay4, LOW);
    if(strcmp(data,"relay5")==0)  digitalWrite(relay5, LOW);
    if(strcmp(data,"relay6")==0)  digitalWrite(relay6, LOW);
    if(strcmp(data,"relay7")==0)  digitalWrite(relay7, LOW);
    if(strcmp(data,"relay8")==0)  digitalWrite(relay8, LOW);
}

void relayOff(const char *event, const char *data){
    if(strcmp(data,"relay4")==0)  digitalWrite(relay4, HIGH);
    if(strcmp(data,"relay5")==0)  digitalWrite(relay5, HIGH);
    if(strcmp(data,"relay6")==0)  digitalWrite(relay6, HIGH);
    if(strcmp(data,"relay7")==0)  digitalWrite(relay7, HIGH);
    if(strcmp(data,"relay8")==0)  digitalWrite(relay8, HIGH);
}