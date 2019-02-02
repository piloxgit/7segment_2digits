
#include <Arduino.h> 
int leds[]={2,3,4,5,6,7,8};
int digits[]={9,10};
int pause=10;
int number[11][7]={
{1,1,1,1,1,1,1},  
{0,0,0,0,0,0,1},
{1,0,0,1,1,1,1},
{0,0,1,0,0,1,0},
{0,0,0,0,1,1,0},
{1,0,0,1,1,0,0},
{0,1,0,0,1,0,0},
{0,1,0,0,0,0,0},
{0,0,0,1,1,1,1},
{0,0,0,0,0,0,0},
{0,0,0,1,1,0,0}
};



void setnumber(int num){
 //  int p=(String(num)[0]).toInt();
//  char x=p[0];

  for(int i=0;i<7;i++){
    digitalWrite(leds[i],number[(num%10)+1][i]);
    }
  digitalWrite(digits[0],HIGH);
  delay(pause);
  digitalWrite(digits[0],LOW);

  for(int i=0;i<7;i++){
    digitalWrite(leds[i],number[((num-(num%10))/10)+1][i]);
    }
  digitalWrite(digits[1],HIGH);
  delay(pause);
  digitalWrite(digits[1],LOW);
}

void setup() {

  for(int i=0;i<7;i++){
	  pinMode(leds[i],OUTPUT);
	  digitalWrite(leds[i],HIGH);
	}

  for(int i = 0; i < 2; i++){
    pinMode(digits[i],OUTPUT);
    digitalWrite(digits[i],LOW);
  }
}

void loop() {
for(int i = 0; i < 100; i++)
{
  setnumber(i);
 
}


}

