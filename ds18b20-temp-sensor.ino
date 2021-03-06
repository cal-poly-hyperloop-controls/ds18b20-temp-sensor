#include <OneWire.h>
#include <DallasTemperature.h>

// Pin of white/grey/data wire. Change this as needed
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement
}


void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  // Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  // Serial.println("DONE");
  
  // Temperature reading in C
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  float temp_c = sensors.getTempCByIndex(0);
  float temp_f = (temp_c * 9.0/5.0) + 32;

  Serial.print((String)temp_c + "C   "); 
  Serial.print((String)temp_f + "F"); 

  
  Serial.println("");
}