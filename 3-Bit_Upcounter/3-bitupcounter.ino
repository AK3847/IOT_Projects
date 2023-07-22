#define led1 9
#define led2 8
#define led3 7
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {

  for(int i=0;i<8;i++)
  {
     digitalWrite(led1,(i>>2)%2==1);
     digitalWrite(led2,(i>>1)%2==1);
     digitalWrite(led3,(i>>0)%2==1);
    delay(1500);
  }
}