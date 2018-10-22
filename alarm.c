#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"
int main(int argc, char *argv[])
{
 int i;
 wiringPiSetup () ;
 pinMode(0, INPUT);
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
 while(1) {
  printf("Waiting for reset\n");
  digitalWrite(1, LOW);
  digitalWrite(2,HIGH);
  while(digitalRead(0) == 1){
    digitalWrite(2, HIGH); delay(500);
    digitalWrite(2, LOW); delay(300);
  }
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  printf("Waiting for event\n");
  while(digitalRead(0) == 0){
    digitalWrite(1, HIGH); delay(500);
    digitalWrite(1, LOW); delay(300);
  }
  printf("Sending data to server\n");
  printf("Alarm\n");
  digitalWrite(2, HIGH);
  
  ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/radio", "alarm", "thom", "jonny");
 }
 /*NOTREACHED*/
 return 0 ;
}
