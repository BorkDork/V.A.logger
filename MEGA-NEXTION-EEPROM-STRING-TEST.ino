/**
 * @example CompButton.ino
 * 
 * @par How to Use
 * Show how to use API of class NexButton.  
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/7/10
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "Nextion.h"
#include "EEPROM.h"
#include "Arduino.h"

NexButton b5 = NexButton(0, 42, "b5");
NexText t1 = NexText(0, 50, "t1");
NexText t0 = NexText(0, 11, "t0");
char buffer[100] = {0};
String str = "";
int i=0;
int j=0;

NexTouch *nex_listen_list[] = 
{
    &b5,
    &t0,
    &t1,
    NULL
};

void b5PopCallback(void *ptr)
{
  char buf;
  byte b;
  String buffer2="";
  String Password = "";
   Serial.println("getting buffer from t0");
   memset(buffer, 0, sizeof(buffer));
   t0.getText(buffer, sizeof(buffer));
   for (int i = 0 ; i < sizeof(buffer) ; i++) 
     {

      if (buffer[i]!= NULL) 
      {
//       Serial.print("buffer2= ");
//       Serial.print(buffer2);
//       Serial.print(" buffer[");
//       Serial.print(i);
//       Serial.print("]= ");
//       Serial.print(buffer[i]);
//       Serial.println("!");
       buffer2+=buffer[i];
      }
     }
 
   
    Serial.print("buffer2 length = ");
    Serial.println(buffer2.length());
    
//    for (int i = 0 ; i < sizeof(buffer2) ; i++) 
//     {
//       EEPROM.write(i, 0);
//     }
//    
//    
//    Serial.println("writing to EEPROM");
//   
//    for (i=0; i< sizeof(buffer2); i++)
//    {
//      EEPROM.update(i,buffer2[i]);
//    }
//    Serial.println("reading from EEPROM");
//     for (i=0;i<sizeof(buffer2);i++)
//      {
//        b=EEPROM.read(i); //read the byte from EEPROM
//    
//        buf=char(b); //convert the byte to character
//        Serial.print("buf=");
//        Serial.println(buf);
//        Password += buf;//add the characters to the Password variable     
//        
//      }
//     Serial.print("Password = ");
//     Serial.println(Password);
//     Serial.print("length = ");
//     Serial.println(Password.length());
     t1.setText(buffer);
    }

void setup(void)
{   
    nexInit();
    b5.attachPop(b5PopCallback);
}

void loop(void)
{   
    nexLoop(nex_listen_list); 
}
