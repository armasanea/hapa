/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * Version update Nov, 2014
 * Mitsubishi HVAC protocol added by Vincent Cruvellier.
 *  delaymicrosecond() modified to avoid limit.
 * Version update Dec, 2014
 * Panasonic HVAC protocol added by Mathieu Thomas. 
 * Version update Dec, 2015
 * Mitsubishi HVAC protocol enhancement by Vincent Cruvellier.
 *   added    void sendHvacMitsubishiFD(
      HvacMode                  HVAC_Mode,           // Example HVAC_HOT  HvacMitsubishiMode
      int                       HVAC_Temp,           // Example 21  (°c)
      HvacFanMode               HVAC_FanMode,        // Example FAN_SPEED_AUTO  HvacMitsubishiFanMode
      HvacVanneMode             HVAC_VanneMode,      // Example VANNE_AUTO_MOVE  HvacMitsubishiVanneMode
      HvacAreaMode              HVAC_AreaMode,       // Example AREA_AUTO
      HvacWideVanneMode         HVAC_WideMode,       // Example WIDE_MIDDLE
      int                       HVAC_PLASMA,          // Example true to Turn ON PLASMA Function
      int                       HVAC_CLEAN_MODE,      // Example false 
      int                       HVAC_ISEE,            // Example False
      int                       OFF                   // Example false to Turn ON HVAC / true to request to turn off
    );
 * sendHvacMitsubishiFD Not tested, i don't have this material -- if someone can confirm then please push a note.
 */

#include "IRremote2.h"
#include <stdio.h>
#include <unistd.h>

void delay(int ms)
{
 usleep(ms);
}

int main() {
	IRsend irsend;

       printf("Switch OFF and Wait 15 Seconds to send ON command.");
      irsend.sendHvacMitsubishi(HVAC_HOT, 21, FAN_SPEED_AUTO, VANNE_AUTO_MOVE, true);
      delay(15000);
       printf("Turn ON\nCommand 'HVAC_HOT, 21, FAN_SPEED_AUTO, VANNE_AUTO_MOVE'  Next Command in 10 sec.");
      irsend.sendHvacMitsubishi(HVAC_HOT, 23, FAN_SPEED_1, VANNE_AUTO_MOVE, false);
      delay(10000);
       printf("Command 'HVAC_HOT, 23, FAN_SPEED_1, VANNE_AUTO_MOVE' sent.\n Waiting 60 Seconds to switch to FAN_SPEED_4.");
      delay(60000);
      irsend.sendHvacMitsubishi(HVAC_HOT, 25, FAN_SPEED_4, VANNE_H1, false);
       printf("Command 'HVAC_HOT, 25, FAN_SPEED_4, VANNE_H1' sent. \n Waiting 30 Seconds to Send FAN_SPEED_SILENT, VANNE_H1.");
      delay(30000);
      irsend.sendHvacMitsubishi(HVAC_HOT, 22, FAN_SPEED_SILENT, VANNE_AUTO_MOVE, false);
       printf("Command 'HVAC_HOT, 22, FAN_SPEED_SILENT, VANNE_AUTO_MOVE' sent.\n Waiting 30 Seconds to send OFF.");
      delay(30000);
      irsend.sendHvacMitsubishi(HVAC_HOT, 21, FAN_SPEED_AUTO, VANNE_AUTO_MOVE, true);
       printf("Turn OFF\nCommand sent. End Of Sketch");
      delay(15000); // Let HVAC sleeping

	return 0;
}
