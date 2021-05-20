#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int j=0;
int prev=0;
int pres=0;
void setup() 
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print(" Soil Moisture  ");
  Serial.begin(9600);
}

void loop() 
{
  j=analogRead(A0);
  j=map(j,0,982,148,0);
  pres=j;
  if(j>100)
  j=100;
  else if(j<0)
  j=0;
  lcd.setCursor(6,1);
  lcd.print(j);
  lcd.print("%  ");
  prev=j;
  delay(500);
}
