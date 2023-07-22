//Using Pin number: 9,8 & 7 as OUTPUT pin for LEDs
#define led1 9
#define led2 8
#define led3 7
void setup() {
  //Setting 9,8 & 7 as OUTPUT pin
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  //Using a for loop to traverse from 0 to 7
  for(int i=0;i<8;i++)
  {
    //Using bit manipulation to find the set bit in the counter: "i"
     digitalWrite(led1,(i>>2)%2==1);
     digitalWrite(led2,(i>>1)%2==1);
     digitalWrite(led3,(i>>0)%2==1);
     //Adding delay so that we can observe the LEDs
     delay(1500);
  }
}