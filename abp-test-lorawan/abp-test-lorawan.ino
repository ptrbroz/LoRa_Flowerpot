/* Simple ABP join for a LoRaWAN network
 *  
 *  In setup() below please replace the argument to LoRaWAN.begin()
 *  with your appropriate region specific band:
 *
 *  AS923
 *  AU915
 *  EU868
 *  IN865
 *  KR920
 *  US915
 *
 *  AU915/US915 networks have 64+8 channels. Typical gateways support only
 *  8 (9) channels. Hence it's a good idea to pick the proper channel
 *  subset via select via LoRaWAN.setSubBand(),
 *    
 *  EU868/IN865 have duty cycle restrictions. For debugging it makes sense
 *  to disable those via setDutyCycle(false);
 *    
 *  For an external antenna one should set the proper antenna gain
 *  (default is 2.0) via setAntennaGain().
 *    
 *  Please edit the keys below as they are just debugging samples.
 *    
 *    
 * This example code is in the public domain.
 */
// #define REGION_AS923_920_923 /* Japan, Malaysia, Singapore */
// #define REGION_AS923_923_925 /* Brunei, Cambodia, Hong Kong, Indonesia, Laos, Taiwan, Thailand, Vietnam */
// #define REGION_AU915
 #define REGION_EU868
// #define REGION_IN865
// #define REGION_KR920
// #define REGION_US915


#include "LoRaWAN.h"
#include "STM32L0.h"
#include "CayenneLPP.h"

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"



CayenneLPP myLPP(64);

Adafruit_SHT31 sht31 = Adafruit_SHT31();


const char *devAddr = "260B3E8F";
const char *nwkSKey = "2B7E151628AED2A6ABF7158809CF4F3C";
const char *appSKey = "2B7E151628AED2A6ABF7158809CF4F3C";

//void setup( void )
//{
//    Serial.begin(115200);
//    
//    while (!Serial) { }
//
//    LoRaWAN.begin(EU868);
//    // LoRaWAN.setSubBand(2);
//    // LoRaWAN.setDutyCycle(false);
//    // LoRaWAN.setAntennaGain(2.0);
//    LoRaWAN.joinABP(devAddr, nwkSKey, appSKey);
//
//    Serial.println("JOIN( )");
//}

void setup( void )
{
#if defined(REGION_AS923_920_923)
    LoRaWAN.begin(AS923);
    LoRaWAN.addChannel(2, 922200000, 0, 5);
    LoRaWAN.addChannel(3, 922400000, 0, 5);
    LoRaWAN.addChannel(4, 922600000, 0, 5);
    LoRaWAN.addChannel(5, 922800000, 0, 5);
    LoRaWAN.addChannel(6, 923000000, 0, 5);
    LoRaWAN.addChannel(7, 922000000, 0, 5);
    LoRaWAN.addChannel(8, 922100000, 6, 6);
    LoRaWAN.addChannel(9, 921800000, 7, 7);
#endif

#if defined(REGION_AS923_923_925)
    LoRaWAN.begin(AS923);
    LoRaWAN.addChannel(2, 923200000, 0, 5);
    LoRaWAN.addChannel(3, 923400000, 0, 5);
    LoRaWAN.addChannel(4, 923600000, 0, 5);
    LoRaWAN.addChannel(5, 923800000, 0, 5);
    LoRaWAN.addChannel(6, 924200000, 0, 5);
    LoRaWAN.addChannel(7, 924400000, 0, 5);
    LoRaWAN.addChannel(8, 924600000, 0, 5);
#endif

#if defined(REGION_AU915)
    LoRaWAN.begin(AU915);
    LoRaWAN.setSubBand(2);
#endif

#if defined(REGION_EU868)
    LoRaWAN.begin(EU868);
    LoRaWAN.addChannel(1, 868300000, 0, 6);
    LoRaWAN.addChannel(3, 867100000, 0, 5);
    LoRaWAN.addChannel(4, 867300000, 0, 5);
    LoRaWAN.addChannel(5, 867500000, 0, 5);
    LoRaWAN.addChannel(6, 867700000, 0, 5);
    LoRaWAN.addChannel(7, 867900000, 0, 5);
    LoRaWAN.addChannel(8, 868800000, 7, 7);
    LoRaWAN.setRX2Channel(869525000, 3);
#endif

#if defined(REGION_IN865)
    LoRaWAN.begin(IN865);
#endif

#if defined(REGION_KR920)
    LoRaWAN.begin(KR920);
    LoRaWAN.addChannel(3, 922700000, 0, 5);
    LoRaWAN.addChannel(4, 922900000, 0, 5);
    LoRaWAN.addChannel(5, 923100000, 0, 5);
    LoRaWAN.addChannel(6, 923300000, 0, 5);
#endif

#if defined(REGION_US915)
    LoRaWAN.begin(US915);
    LoRaWAN.setSubBand(2);
#endif
    Serial.begin(115200);
      
    // LoRaWAN.setDutyCycle(false);     
    // LoRaWAN.setAntennaGain(2.0);
    LoRaWAN.joinABP(devAddr, nwkSKey, appSKey);

    LoRaWAN.onReceive(callback_onReceive);

    Serial.println("JOIN( )");

    if (! sht31.begin(0x44)) {   // Set to 0x45 for alternate i2c addr
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }

  Serial.print("Heater Enabled State: ");
  if (sht31.isHeaterEnabled())
    Serial.println("ENABLED");
  else
    Serial.println("DISABLED");

    
    pinMode(2, OUTPUT); //multiplexer

    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    
    pinMode(A0, INPUT); //adc in
    pinMode(A4, INPUT);  //does not work...

    pinMode(9, INPUT_PULLUP); 
    pinMode(8, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
}

volatile uint16_t dirtTarget = 0;

void loop( void )
{

    float t = sht31.readTemperature();
    float h = sht31.readHumidity();

    static int ctrVal = 0;
    ctrVal = !ctrVal;

    
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    
    

    //while(1){
    digitalWrite(2, LOW); 
    delay(1000);
    int adcRead1 = analogRead(0);
    
    digitalWrite(2, HIGH); 
    delay(1000);
    int adcRead2 = analogRead(0);
    
    int dval1 = digitalRead(9); //miska low
    int dval2 = digitalRead(8); //miska high
    int dval3 = digitalRead(11); //reservoir low
    int dval4 = digitalRead(12); //reservoir high
 
    Serial.print("ADC1 = "); Serial.print(adcRead1); Serial.print(" ADC2 = "); Serial.print(adcRead2); Serial.print("\n\r");
    Serial.print("Temp *C = "); Serial.print(t); Serial.print("\t\t");
    Serial.print("Hum. % = "); Serial.println(h);
    Serial.print("Digitals: "); Serial.print(dval1); Serial.print(" "); Serial.print(dval2); Serial.print(" "); Serial.print(dval3); Serial.print(" "); Serial.print(dval4); Serial.print("\n\r");
    
    int dataArrayLen = 9;
    uint8_t dataArray[dataArrayLen];

    uint16_t adc1 = (uint16_t) adcRead1;
    uint16_t adc2 = (uint16_t) adcRead2;
    uint16_t temp10 = (uint16_t) round(10.0*t);
    uint16_t hum10  = (uint16_t) round(10.0*h);
    uint8_t mask = 0x01;
    uint8_t digitals  = (dval1 << 0) + (dval2 << 1) + (dval3 <<2) + (dval4 << 3);
    Serial.print("digitals byte = "); Serial.print(digitals);
    
    *( (uint16_t *) (dataArray + 0)) = adc1;
    *( (uint16_t *) (dataArray + 2)) = adc2;
    *( (uint16_t *) (dataArray + 4)) = temp10;
    *( (uint16_t *) (dataArray + 6)) = hum10;
    *( (uint8_t  *) (dataArray + 8)) = digitals;
    
    

  
    if (LoRaWAN.joined() && !LoRaWAN.busy())
    {
        if (STM32L0.getVBUS()) 
        {
            LoRaWAN.setBatteryLevel(LORAWAN_BATTERY_LEVEL_EXTERNAL);
        }
        else
        {
            LoRaWAN.setBatteryLevel(LORAWAN_BATTERY_LEVEL_UNKNOWN);
        }

        Serial.print("TRANSMIT( ");
        Serial.print("TimeOnAir: ");
        Serial.print(LoRaWAN.getTimeOnAir());
        Serial.print(", NextTxTime: ");
        Serial.print(LoRaWAN.getNextTxTime());
        Serial.print(", MaxPayloadSize: ");
        Serial.print(LoRaWAN.getMaxPayloadSize());
        Serial.print(", DR: ");
        Serial.print(LoRaWAN.getDataRate());
        Serial.print(", TxPower: ");
        Serial.print(LoRaWAN.getTxPower(), 1);
        Serial.print("dbm, UpLinkCounter: ");
        Serial.print(LoRaWAN.getUpLinkCounter());
        Serial.print(", DownLinkCounter: ");
        Serial.print(LoRaWAN.getDownLinkCounter());
        Serial.println(" )");

        Serial.print("Lora packet data:\n\r");
        
        LoRaWAN.beginPacket();
        int i;
        for(i = 0; i < dataArrayLen; i++){
            LoRaWAN.write(dataArray[i]);
            Serial.print(dataArray[i]);
            Serial.print(" ");
        }
        LoRaWAN.endPacket();
        Serial.print("\n\r");

            //myLPP.reset();
            //myLPP.addTemperature(0, 27);
            //myLPP.addRelativeHumidity(0, 30);

            //int buff[] = {1 ,2, 3, 15};
            //LoRaWAN.sendPacket(buff, 4);
            //LoRaWAN.sendPacket(myLPP.getBuffer(), myLPP.getSize());
            //LoRaWAN.sendPacket(myLPP.getBuffer(), 1);

        
    }

 


 delay(5000);


}

void callback_onReceive(){
  Serial.print("ON RECEIVE CALLBACK\n");
  if (LoRaWAN.parsePacket()){
      uint32_t size;
      uint8_t data[50];
      size = LoRaWAN.read(&data[0], sizeof(data));
      if(!size){
        Serial.print("no data in packet\n");
      }
      else{
        for(int i=0;i<size;i++){
          Serial.print(data[i],HEX);
        }
        Serial.println();
      }
  }
  else{
    Serial.print("can't parse :(\n");
  }
}
