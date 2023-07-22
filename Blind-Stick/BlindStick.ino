/*
    This is an IOT project demonstrating the use of Arduino-UNO board along with Ultrasonic sensor,
    buzzer and LED light. This is a guiding stick for blind people which notifies them of any obstacle
    in their way by using ultrasonic waves.
    The code is tested and implemented in Arduino IDE
    Code author- Abdul Kadir
    Github Profile- https://github.com/AK3847
*/

//defining pins and their roles
int trigpin=9;
int echopin=10;
int buzzer=11;
int ledpin=13;

void setup()
{
    //Setting the pins as INPUT or OUTPUT
    pinMode(trigpin,OUTPUT);
    pinMode(echopin,INPUT);
    pinMode(buzzer,OUTPUT);
    pinMode(ledpin,OUTPUT);
    Serial.begin(9600)
}
void loop()
{
    //declaring variables
    long duration;
    int distance;
    int safetydist;

    //Setting the trigpin as high
    digitalWrite(trigpin, 1);
    delayMicroseconds(100);
    digitalWrite(trigpin, 0);

    //Getting the duration from the echopin into our 'duration variable'
    duration=pulseIn(echopin,1);

    /*Calculating distance
        Here distance=speed*time
        for speed--> speed of soundwaves in air = 343m/s
        the echopin returns the duration for the whole trip of a soundwave from ultrasonic sensor to object
        and then object to ultrasonic sensor i.e 2 times so we divided it by 2
        also we are measuring the distance in cm so divided by 100
    */
    distance=duration*0.034/2;

    safetydist=distance;
    /*
        Here I have taken the safety distance as 50 cm which can be further modified as the need arises.
    */
    if(safetydist<=50)
    {
        /*
            If the object is closer than 50cm we trigger the buzzer and led light so as to notify the person.
        */
        digitalWrite(buzzer,1);
        delayMicroseconds(100);
        digitalWrite(ledpin,1);
    }
    else
    {
        /*
            If there is no object in a distance of 50 cm we don't trigger the buzzer and led light
        */
        digitalWrite(buzzer,0);
        digitalWrite(ledpin,0);
    }
}