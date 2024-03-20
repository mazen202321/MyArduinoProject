 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27 ,16 ,2);
int readPin=A0;
int readValue;
void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
pinMode(readPin ,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
readValue=analogRead(readPin);
Serial.println(readValue);
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print("Water Level : ");
  lcd.setCursor(0,1);//print on lcd in row 0 column 1
  if(readValue <=100){
    lcd.print("no water");
  }
 else if(readValue <= 300 ){
  lcd.print("LOW");  
}else if(readValue < 600){
  lcd.print("Meduim");
}else{
   //readValue >500
lcd.print("HIGH");
}
delay(1000);
}
// 
