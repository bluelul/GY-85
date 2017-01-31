#include "GY_85.h"
#include <Wire.h>

GY_85 GY85;     //create the object
int fax = 0;
int fay = 0;
int faz = 0;
float alpha = 0.9; //low pass filter, alpha increase -> filter effect increase

void setup()
{
  //    Wire.begin(10,9);
  Wire.setModule(0);
  delay(10);
  Serial.begin(9600);
  delay(10);
  GY85.init();
  delay(10);
  pinMode(30, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  digitalWrite(30, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
}


void loop()
{
  int ax = GY85.accelerometer_x( GY85.readFromAccelerometer() );
  int ay = GY85.accelerometer_y( GY85.readFromAccelerometer() );
  int az = GY85.accelerometer_z( GY85.readFromAccelerometer() );

  int cx = GY85.compass_x( GY85.readFromCompass() );
  int cy = GY85.compass_y( GY85.readFromCompass() );
  int cz = GY85.compass_z( GY85.readFromCompass() );

  int gx = GY85.gyro_x( GY85.readGyro() );
  int gy = GY85.gyro_y( GY85.readGyro() );
  int gz = GY85.gyro_z( GY85.readGyro() );
  int gt = GY85.temp  ( GY85.readGyro() );

  // gt = 35+(gt+13200)/280;

  fax = fax * alpha + ax * (1 - alpha);
  fay = fay * alpha + ay * (1 - alpha);
  faz = faz * alpha + az * (1 - alpha);
  //  Serial.print  ( "accelerometer" );
  //  Serial.print  ( " x:" );

  Serial.print  ( fax );
  //  Serial.print  ( " y:" );
  Serial.print  (" ");
  Serial.print  ( fay );
  //  Serial.print  ( " z:" );
  Serial.print  (" ");
  Serial.print  ( faz );
  //
  //  Serial.print  ( "  compass" );
  //  Serial.print  ( " x:" );
  //  Serial.print  ( cx );
  //  Serial.print  ( " y:" );
  //  Serial.print  ( cy );
  //  Serial.print  (" z:");
  //  Serial.print  ( cz );
  //
  //  Serial.print  ( "  gyro" );
  Serial.print  (" ");
    //Serial.print  ( " x:" );
  //    Serial.print  (" ");
     Serial.print  ( gx );
  //  Serial.print  ( " y:" );
  Serial.print  (" ");
    Serial.print  ( gy );
  //  Serial.print  ( " z:" );
  Serial.print  (" ");
    Serial.print  ( gz );
  //  Serial.print  ( " gyro temp:" );
  Serial.print  (" ");
  Serial.println( gt );
  //
  //    delay(500);             // only read every 0,5 seconds, 10ms for 100Hz, 20ms for 50Hz
}
