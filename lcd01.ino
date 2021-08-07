#include <LiquidCrystal.h>

#define fanpin 9

const int pin=A1;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup()
{
  lcd.begin(16,2);
  }

void loop()
{ int temp_val=analogRead(pin);
  float temp=temp_val*0.488; 
 delay(100);
  if (temp<25)
  {lcd.setCursor(0,0);
    lcd.print("Temperature:");

  lcd.print(temp);
  lcd.setCursor(0,1);
lcd.print("");
  analogWrite(6,0);
  
  
  }

else if(temp>=25 && temp<50)
{lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print(temp);
  lcd.setCursor(0,1);
lcd.print(" ");
 analogWrite(fanpin,51);
 analogWrite(6,0);
   
  }
else if(temp>=50 && temp<75)
{lcd.setCursor(0,0);
  lcd.print("Temperature:");
lcd.print(temp);
lcd.setCursor(0,1);
lcd.print("");
analogWrite(fanpin,128);
analogWrite(6,0);
}

else if(temp>=75)
{lcd.setCursor(0,0);
  lcd.print("Temperature:");
lcd.print(temp);
lcd.setCursor(0,1);
lcd.print("Overheating");
analogWrite(fanpin,255);
analogWrite(6,255);


}

else
;
}
