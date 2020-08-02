#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,3,2,1,0);
void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  lcd.begin(16,2);
}

void loop() {
  int x;
  int a=analogRead(A0);
  float c=a*(5.0/1023)*2.5;
  lcd.setCursor(0,0);
  lcd.print('V');
  lcd.setCursor(1,0);
  lcd.print('-');
  lcd.setCursor(2,0);
  lcd.print(c);
  float val=analogRead(A1);
  float mv=(val/1024.0)*5000;
  float cel=mv/10;
  /*float farh=(cel*9)/5 + 32;*/
  lcd.setCursor(8,0);
  lcd.print('T');
   lcd.setCursor(9,0);
  lcd.print('-');
  lcd.setCursor(10,0);
  lcd.print(cel);
  float currentRead=analogRead(A2);
  float current1_Read=(currentRead / 1024.0) *5;
  float current_Read= (((current1_Read -2.5) /0.066)+0.03 );
  lcd.setCursor(0,1);
  lcd.print('I');
  lcd.setCursor(1,1);
  lcd.print('-');
  lcd.setCursor(2,1);
  lcd.print(current_Read,2);
  if(c>12.5 && c<=12.6)
      x=100;
  else if(c>12.42 && c<=12.5)
      x=90;
  else if(c>12.32&&c<=12.42)
      x=80;
  else if(c>12.20&&c<=12.32)
      x=70;
  else if(c>12.06&&c<=12.20)
      x=60;
  else if(c>11.9&&c<=12.06)
      x=50;
  else if(c>11.75&&c<=11.9)
      x=40;
  else if(c>11.58&&c<=11.75)
      x=30;
  else if(c>11.31&&c<=11.58)
      x=20;
  else if(c>10.5&&c<=11.31)
      x=10;
  else if(c<=10.5)
      x=00;
  lcd.setCursor(7,1);
  lcd.print('S');
  lcd.setCursor(8,1);
  lcd.print('0');
  lcd.setCursor(9,1);
  lcd.print('C');
  lcd.setCursor(10,1);
  lcd.print('-');
  lcd.setCursor(11,1);
  lcd.print(x);
  lcd.setCursor(14,1);
  lcd.print('%');
}
