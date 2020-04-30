int led = D6;
int boardLed = D7;

 

void setup() {

    pinMode(led,OUTPUT);
    pinMode(boardLed,OUTPUT);
    
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy",lightUp);

}

void loop() {

}


void lightUp(const char *event, const char *data)
{
    if (strcmp(data,"wave")==0) 
    {
        Particle.publish(String::format(event));
        flasher();
    }
    else if (strcmp(data, "pat")==0)
    {
        Particle.publish(String::format(event));
        digitalWrite(led, HIGH);
        digitalWrite(boardLed, HIGH);
        delay(3000);
        digitalWrite(led, LOW);
        digitalWrite(boardLed, LOW);
    }

}


void flasher()
{
    digitalWrite(led,HIGH);
    digitalWrite(boardLed,HIGH);
    delay(1000);
    digitalWrite(led,LOW);   
    digitalWrite(boardLed,LOW);
    delay(1000);
    digitalWrite(led,HIGH);
    digitalWrite(boardLed,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    digitalWrite(boardLed,LOW);
    delay(1000);
    digitalWrite(led,HIGH);
    digitalWrite(boardLed,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    digitalWrite(boardLed,LOW);
    delay(1000);
}