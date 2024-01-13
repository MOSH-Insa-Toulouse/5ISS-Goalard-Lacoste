#include <TheThingsMessage.h>
#include <TheThingsNetwork.h>
#include <SoftwareSerial.h>


#define debugSerial Serial
#define rxPin 11 //Broche 11 en tant que RX, � raccorder sur TX du HC-05
#define txPin 10 //Broche 10 en tant que RX, � raccorder sur TX du HC-05
#define baudrate 9600
#define debugSerial Serial
SoftwareSerial loraSerial(rxPin ,txPin); //D�finition du software serial

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868
int sensorPin=A0;
int sensorData;
float sensor_volt;
// Set your AppEUI and AppKey
const char *appEui = "55a29f7951e7e5f2";
const char *appKey = "2c54a1184d04b40c094292683369bf16";



TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

//devicedata_t data = api_DeviceData_init_default;
int gazData;

void setup()
{
  loraSerial.begin(57600);
  debugSerial.begin(9600);

  // Wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000)
    ;

  debugSerial.println("-- STATUS");
  ttn.showStatus();

  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);

  // Select what fields to include in the encoded message
  /*data.has_motion = true;
  data.has_water = false;
  data.has_temperature_celcius = true;
  data.has_temperature_fahrenheit = true;
  data.has_humidity = true;
*/
  pinMode(sensorPin,INPUT);


}

void loop()
{
  debugSerial.println("-- LOOP");

  // Read the sensors
  /* data.motion = true;
  data.water = 682;
  data.temperature_celcius = 30;
  data.temperature_fahrenheit = 86;
  data.humidity = 97;
*/
  // Encode the selected fields of the struct as bytes
  byte buffer[2];
  size_t size;
  int gazData;
  sensorData = analogRead(sensorPin);       
 
  Serial.print("Sensor Data:");
  Serial.print(sensorData);
  sensor_volt = sensorData/1024*5.0;
  gazData = sensorData;
//  Serial.print(sensor_volt);
//  Serial.println("V");
//  Serial.print("sensor_volt = ");  
//  Serial.print(byte(gazData));
//  Serial.print("Sizeof GazData"); 
//  Serial.print(sizeof(gazData));
  buffer[0] = gazData & 0xFF;
  buffer[1] = (gazData >> 8) & 0xFF;

  //TheThingsMessage::encodeDeviceData(&gazData, &buffer, &size);
  //TheThingsNetwork::sendBytes(&gazData,&buffer, &size);
  ttn.sendBytes(buffer, 2);
  
  delay(10000);
}



