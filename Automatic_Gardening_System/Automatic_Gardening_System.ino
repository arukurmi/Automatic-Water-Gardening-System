
// AUTOMATIC IRRIGATION SYSTEM.

#include <LiquidCrystal.h> //LCD Library.
int temp;
int T_Sensor = A1;
int M_Sensor = A0;
int val; 
int cel; //Temprature values conversion to celsius scale.

//these are the port pins to be connected to the lcd panel
LiquidCrystal lcd(8, 7, 4, 3, 2, 1);

//setting up the ports and circuit
void setup()
 {
    lcd.begin(16, 2);
    lcd.clear(); 
    pinMode(13,OUTPUT);
    pinMode(A4,INPUT);
    Serial.begin(9600);

    lcd.setCursor(0,0);
    lcd.print("AUTOMATIC");
    lcd.setCursor(0,1);
    lcd.print("WATER GARDENING SYSTEM");
    delay(2500);
    lcd.clear(); 
}

void loop()
{
   lcd.clear();
    /*If you want to show temprature as well, just uncomment the lines below*/
    /*val = analogRead(T_Sensor); //Read Temperature sensor value 
    Serial.println(val);
    int mv = ( val/1024.0)*5000; 
     cel = mv/10;
     lcd.setCursor(0,0);
     lcd.print("TEMP:");
     lcd.setCursor(5,0);
     lcd.print(cel);
     lcd.setCursor(7,0);
     lcd.print("*C");
 */

   int Moisture = analogRead(M_Sensor); //Read Moisture Sensor Value.
   Serial.println(Moisture);
 if (Moisture> 200)   // for dry soil.
  { 
        lcd.setCursor(0,0);
        lcd.print("DRY SOIL");
       if (digitalRead(11)==1) //test the availability of water in storage USING WATER LEVELL INDICATOR.
       {
        digitalWrite(12, HIGH);//Relay is on and pump gets on
        lcd.setCursor(0,1);
        lcd.print("PUMP:ON");
       }
       else
       {
        digitalWrite(12, LOW);//WATER WILL NOT PUMP OUT OF NO WATER IS IN SUPPLY CONTAINER.
        lcd.setCursor(0,1);
        lcd.print("PUMP:OFF");
        lcd.setCursor(11,0);
        lcd.print("WATER");
        lcd.setCursor(11,1);
        lcd.print("LOW");
       }
    }
 
if (Moisture>= 70 && Moisture<=200) //for Moist Soil.
    { 
      lcd.setCursor(0,0);
     lcd.print("MOIST SOIL");
     //lcd.setCursor(11,1);
     //lcd.print("SOIL");
     digitalWrite(12,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");    
    }
 
if (Moisture < 70)  // For Soggy soil.
  { 
    lcd.setCursor(0,0);
     lcd.print("SOGGY SOIL");
     //lcd.setCursor(11,1);
     //lcd.print("SOIL");
     digitalWrite(12,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");
  }
 delay(2000);    
}  
