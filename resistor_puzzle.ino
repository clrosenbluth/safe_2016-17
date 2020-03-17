#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3,POSITIVE);
int pot = A0;
int therm = A1;
int resistor = A2;
int button = 2;
int led_1 = 10;
int led_2 = 5;
int led_3 = 11;

void setup() {
lcd.begin(16,2);
lcd.backlight();
pinMode(button, INPUT);
pinMode(pot, INPUT);//possibly irrelevant
pinMode(therm, INPUT);//possibly irrelevant
pinMode(resistor, INPUT);//possibly irrelevant
Serial.begin(9600);
}

void loop() {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Land spaceship");
lcd.setCursor(0,1);
lcd.print("fix dashboard");
int val_1=0;
int val_2=0;
int val_3=0;
int pot_num = analogRead(pot);//purely for reading values
int therm_num = analogRead(therm);//purely for reading values
int resistor_num = analogRead(resistor);//purely for reading values
  Serial.println("pot");
  Serial.println(pot_num);
  Serial.println("therm");
  Serial.println(therm_num);
  Serial.println("resistor");
  Serial.println(resistor_num);
  delay(500);
  int reset = 1;

while (reset ==1){
  Serial.println("We're in");

   if (analogRead(pot)>800 && analogRead(pot)<850){//Arbitrary threshold numbers
     val_1=1;
     digitalWrite(led_1, HIGH);//will it stay onthroughout code?
     Serial.println("gate 1");
     delay(500);
   }
   if (analogRead(therm)>230){//Arbitrary threshold numbers
     val_2=1;
     digitalWrite(led_2, HIGH);
     Serial.println("gate 2");
     delay(500);
    }
   if (analogRead(resistor)>580 && analogRead(resistor)<600){//Arbitrary threshold numbers
     val_3=1;
     digitalWrite(led_3, HIGH);
     Serial.println("gate 3");
     delay(500);
    }
    if (val_1+val_2+val_3==3){
      Serial.println("passed");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Landing Code:");
      lcd.setCursor(0,1);
      lcd.print("613");
      //reset++;
    }
    if (digitalRead(button)==HIGH){
      digitalWrite(led_1, LOW);
      digitalWrite(led_2, LOW);
      digitalWrite(led_3, LOW);
      lcd.clear();
      Serial.println("Reset");
      lcd.print("");
      lcd.setCursor(0,0);
      lcd.print("");
      reset++;
   }
  }
}
