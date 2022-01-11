//
//    FILE: DHT20.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: Demo for DHT20 I2C humidity & temperature sensor
//


#include "DHT20.h"

DHT20 DHT(&Wire);


void setup()
{
  DHT.begin();

  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("DHT20 LIBRARY VERSION: ");
  Serial.println(DHT20_LIB_VERSION);
  Serial.println();

  delay(2000);

  Serial.println("Type,\tStatus,\tHumidity (%),\tTemperature (C)");
}


void loop()
{
  if (millis() - DHT.lastRead() >= 1000)
  {
    // READ DATA
    Serial.print("DHT20, \t");
    int status = DHT.read();
    switch (status)
    {
    case DHT20_OK:
      Serial.print("OK,\t");
      break;
    case DHT20_ERROR_CHECKSUM:
      Serial.print("Checksum error,\t");
      break;
    case DHT20_ERROR_CONNECT:
      Serial.print("Connect error,\t");
      break;
    case DHT20_MISSING_BYTES:
      Serial.print("Missing bytes,\t");
      break;
    default:
      Serial.print("Unknown error,\t");
      break;
    }
    // DISPLAY DATA, sensor has only one decimal.
    Serial.print(DHT.getHumidity(), 1);
    Serial.print(",\t");
    Serial.println(DHT.getTemperature(), 1);
  }
}


// -- END OF FILE --
