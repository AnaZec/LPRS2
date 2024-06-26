// demo: CAN-BUS Shield, receive data with check mode
// send data coming to fast, such as less than 10ms, you can use this way
// loovee, 2014-6-13


#include <SPI.h>
#include "mcp_can.h"


// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 9;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin



 
void setup()
{
    Serial.begin(9600);

START_INIT:

    if(CAN_OK == CAN.begin(CAN_250KBPS))                   // init can bus : baudrate = 250k
    {
        Serial.println("CAN BUS Shield init ok!");
    }
    else
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        delay(100);
        goto START_INIT;
    }
}

     unsigned char stmp[8] = {0, 0, 0, 0, 0, 0, 0, 4}; // choose bits

void loop()
{
    unsigned char len = 0;
    unsigned char buf[8];

    if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        unsigned long canId = CAN.getCanId();
       
        Serial.println("-----------------------------");
        Serial.print("get data from ID: ");
        Serial.println(canId, HEX); // in Hex

        for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(buf[i]);
            Serial.print("\t");
        }
        Serial.println();
    }
// send data:  id = 0x00 in Hex, extented frame = 1, data len = 8, stmp: data buf
    CAN.sendMsgBuf(0x18FEDF00, 1, 8, stmp); 
      delay(500);                       // send data per 5s00ms
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
