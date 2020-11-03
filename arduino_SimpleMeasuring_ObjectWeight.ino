//this is arduino simple project measuring object based on their weight
#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE=7;
const int PIN_LCD_DATA=6;
const int PIN_LCD_CLOCK=5;

LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,PIN_LCD_CLOCK,PIN_LCD_STROBE);

Servo myServo; // motor servo1
Servo myservo2; // motor servo2

HX711 scale(3, 2); //HX711 scale(DT, SCK);

float calibration_factor1 = 200; // calibration for Weight Sensor
float hasil1;


void setup()
{
  myServo.attach(9);
  myservo2.attach(10);
  Serial.begin(9600);
  Serial.println("HX711 weighing");
  scale.set_scale(calibration_factor1);
  scale.tare(); // when no weight to scale, the calibration turn to 0 
  Serial.println("Readings:");
  
    lcd.begin(16,2);
    lcd.print("Alat Penyortir");
    lcd.setCursor(0,1);
    lcd.print("Tomat");
}
void loop(){ 
  
  if(calibration_factor1){
  Serial.print("Reading:");
  hasil1 = scale.get_units(10);
  if (hasil1 < 0)
  {
    hasil1 = 0.00;
    myservo2.write(20); // when no weight to scale, the motor servo on the 20degree
  }
  Serial.print(hasil1);
  Serial.println(" grams");
  }
 
  if(hasil1 > 50.80 && hasil1 < 51.10){

    myservo2.write(90); // when sensor complete scale 50-51 grams, the motor servo on the 90degree
    delay(3000);
  
      lcd.setCursor(0,0);
     
      lcd.println("hasil ukuran :");
      lcd.setCursor(0,1);
//      lcd.println("gram :")// complete scaling
      lcd.print(hasil1);
  }

 if(hasil1 > 31.80 && hasil1 < 32.10){
    
    myservo2.write(135); // when sensor complete scale 31-32 grams, the motor servo on the 135degree
    delay(3000);
    
      lcd.setCursor(0,0);
     
      lcd.println("hasil ukuran :");
      lcd.setCursor(0,1);
      lcd.println("gram :");// complete scaling
      lcd.print(hasil1);
  }
  }

//  check the implementation on these video https://www.youtube.com/watch?v=UyoyEwUpNEI
