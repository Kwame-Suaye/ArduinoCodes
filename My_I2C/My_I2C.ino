#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int en =2, rw = 1, rs = 0, d4 = 4, d5 = 5,  d6 = 6,  d7 = 7, bl = 3;

const int i2c_addr = 0x3F;

LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);
void setup()
{
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("Hello world");

   delay(5000);

lcd.setCursor(0,1);
lcd.print("TechLeadsGh");

   delay(1000);

  
}

void loop(){
for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(500);
}
 for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);}}
