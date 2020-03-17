#define newLED 3 // green LED 'new'
#define okLED 4 // yellow LED 'ok'
#define oldLED 6 // red LED 'old'
#include <Servo.h>
Servo myservo;
int servo = 9;
int ldr_1 = A0;
int ldr_2 = A1;
int ldr_3 = A2;
int button = 2;
int reset_led =12;
int analogValue = A4;
float voltage = 0;
int ledDelay = 2000;

void setup() {
  
Serial.begin(9600);
 pinMode(newLED, OUTPUT);
  pinMode(okLED, OUTPUT);
  pinMode(oldLED, OUTPUT);
pinMode(servo, OUTPUT);
pinMode(button, INPUT);
myservo.attach(9);
myservo.write(75);//closed
delay(500);
}

void loop() {
  analogValue = analogRead(A4);
    voltage = (0.004888*analogValue)/.63;
    Serial.println(voltage);
    
  if(voltage >= 6.0){
    digitalWrite(newLED, HIGH);
    //delay(ledDelay);
    //digitalWrite(newLED, LOW);

} if(voltage <6.0 && voltage > 5.8){
    digitalWrite(okLED, HIGH);
   // delay(ledDelay);
    //digitalWrite(okLED, LOW);

} if(voltage <= 5.8){
    digitalWrite(oldLED, HIGH);
    //delay(ledDelay);
    //digitalWrite(oldLED, LOW);

}
//myservo.write(75);//closed
digitalWrite(reset_led, LOW);
int ldr_num_1 = analogRead(ldr_1);
int ldr_num_2 = analogRead(ldr_2);
int ldr_num_3 = analogRead(ldr_3);
int val_1 = 0;
int val_2 = 0;
int val_3 = 0;
Serial.println("LDR 1");
Serial.println(ldr_num_1);
delay(250);
Serial.println("LDR 2");
Serial.println(ldr_num_2);
delay(250);
Serial.println("LDR 3");
Serial.println(ldr_num_3);
delay(250);
int reset=1;

while (reset==1){
  Serial.println("We're in");
  if (analogRead(ldr_1)<150){//Arbitrary threshold numbers
    val_1=1;
    Serial.println("Sense 1");
    delay(250);
  }
  if (analogRead(ldr_2)<1023){//Arbitrary threshold numbers
    val_2=1;
    Serial.println("Sense 2");
    delay(250);
  }
  if(analogRead(ldr_3)>550){//Arbitrary threshold numbers
    val_3=1;
    Serial.println("Sense 3");
    delay(250);
  }
  if(val_1+val_2+val_3==3){
    myservo.write(185);//open
    Serial.println("passed");
    digitalWrite(reset_led, HIGH);
    delay(500);
    reset++;
  }
  if (digitalRead(button)==HIGH){ 
     myservo.write(75);//close
     Serial.println("Reset");
     digitalWrite(reset_led, HIGH);
     delay(500);
     reset++;
 }
}
}
