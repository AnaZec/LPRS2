#include <SPI.h>

#define CAN_2515

#if defined(SEEED_WIO_TERMINAL) && defined(CAN_2518FD)
const int SPI_CS_PIN  = BCM8;
const int CAN_INT_PIN = BCM25;
#else

const int SPI_CS_PIN = 9;
const int CAN_INT_PIN = 2;
#endif


#ifdef CAN_2518FD
#include "mcp2518fd_can.h"
mcp2518fd CAN(10); // Set CS pin
#endif

#ifdef CAN_2515
#include "mcp2515_can.h"
mcp2515_can CAN(10); // Set CS pin
#endif                           

void setup() {
    SERIAL_PORT_MONITOR.begin(115200);
    while (CAN_OK != CAN.begin(CAN_250KBPS)) {             // init can bus : baudrate = 500k
        SERIAL_PORT_MONITOR.println("CAN init fail, retry...");
        delay(1000);
    }
    SERIAL_PORT_MONITOR.println("CAN init ok!");
}

 
 unsigned char stmp[8] = {0, 0, 0, 0, 0, 0, 0, 4}; // choose bits

void loop() {

            for (int b7 = 0; b7 <= 255; b7++) {
                // Set stmp array with current combination
       
                stmp[7] = b7;

				unsigned char len = 0;
			    unsigned char buf[8];
			
			    if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
			        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
			
			        unsigned long canId = CAN.getCanId();
			
			        SERIAL_PORT_MONITOR.println("-----------------------------");
			        SERIAL_PORT_MONITOR.print("Get data from ID: 0x");
			        SERIAL_PORT_MONITOR.println(canId, HEX);
			
			        for (int i = 0; i < len; i++) { // print the data
			            SERIAL_PORT_MONITOR.print(buf[i], HEX);
			            SERIAL_PORT_MONITOR.print("\t");
			        }
			        SERIAL_PORT_MONITOR.println();
			    }
			    // send data:  id = 0x00 in Hex, extented frame = 1, data len = 8, stmp: data buf
			    CAN.sendMsgBuf(0x18FEDF00, 1, 8, stmp); 
			     delay(500);     // send data per 5s00ms
			     
			     								
				SERIAL_PORT_MONITOR.print("stmp: ");
			    for (int i = 0; i < 8; i++) {
			        SERIAL_PORT_MONITOR.print(stmp[i], HEX);
			        SERIAL_PORT_MONITOR.print("\t");
			    }
			    SERIAL_PORT_MONITOR.println();



                                    
	}

    
}
