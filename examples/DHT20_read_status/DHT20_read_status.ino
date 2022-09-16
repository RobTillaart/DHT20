//
//    FILE: DHT20_read_status.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: Demo for DHT20 I2C humidity & temperature sensor
//

//  Always check datasheet - front view
//
//          +--------------+
//  VDD ----| 1            |
//  SDA ----| 2    DHT20   |
//  GND ----| 3            |
//  SCL ----| 4            |
//          +--------------+


#include "DHT20.h"

DHT20 DHT;

uint8_t count = 0;

void setup()
{
  DHT.begin();    //  ESP32 default pins 21 22

  Wire.setClock(400000);

  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("DHT20 LIBRARY VERSION: ");
  Serial.println(DHT20_LIB_VERSION);
  Serial.println();

  delay(2000);
}


void loop()
{
  int status = DHT.readStatus();
  Serial.println(status);
  delay(1000);
}


// -- END OF FILE --
