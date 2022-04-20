//www.elegoo.com
//2016.12.9

#include <LiquidCrystal.h>
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 2;
int tempPin = 0;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup()
{
  lcd.begin(16, 2);
  Serial.begin( 9600);
}
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}

void loop()
{
  


  
  //temp in Celcius
  float temperature;
  float humidity;

    
  if( measure_environment( &temperature, &humidity ) == true )
  {
 
 
  //all these temps are from DHT11 
  float tempK = temperature + 273.15;            // Convert Kelvin to Celcius
  float tempF = (temperature * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
    // Display Temperature in C
  lcd.setCursor(0, 0);
//  lcd.print("Temp         C  ");
  // Display Temperature in F
  lcd.print("Temp =        F");
  lcd.setCursor(8, 0);
  // Display Temperature in C
  //lcd.print(tempC);
  // Display Temperature in F
  lcd.print(tempF);
  lcd.setCursor(0,1);
  lcd.print("Humidity = ");
  lcd.setCursor(11,1);
  lcd.print(humidity);
  lcd.setCursor(15,1);
  lcd.print("%");
  delay(500);
  }
}
