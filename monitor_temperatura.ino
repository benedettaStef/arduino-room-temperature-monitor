#include <LiquidCrystal_I2C.h>
float temp, tempC, tempMV;

LiquidCrystal_I2C lcd(0x26, 16, 2);

void setup()
{
  Serial.begin(9600);
  lcd.init();					
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp. Stanza");
  
  //imposta a0 come ingresso per lettura sensore
  pinMode(A0, INPUT);
  //pin 13 configurato come uscita per pilotare led integrato arduino
  pinMode(13, OUTPUT); 
}
void loop()
{
  // Lettura Temperatura da sensore
    temp = analogRead(A0);
  //conversione in millivolt
    tempMV = temp * 5000.0 / 1023.0;
  // conversione in gradi celsius
    tempC = (tempMV / 10.0) - 50.0;
  
    Serial.println(tempC);

    // Mostra temperatura
    lcd.setCursor(0,1);
    lcd.print("T=");
    lcd.print(tempC);
    lcd.print("C   "); // cancellazione residui

    // Logica temperatura
    lcd.setCursor(10,1); // parte destra del display

    if(tempC > 25)
    {
        lcd.print("CALDO ");
        digitalWrite(13, HIGH);  // LED acceso se caldo
    }
    else if(tempC >= 20 && tempC <= 25)
    {
        lcd.print("OK    ");
        digitalWrite(13, LOW);   // LED spento
    }
    else  // tempC < 20
    {
        lcd.print("FREDDO");
        digitalWrite(13, LOW);
    }
  delay(300);
}
