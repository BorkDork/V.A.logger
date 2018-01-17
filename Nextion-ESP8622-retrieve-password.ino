/* this sketch takes a string from Nextion and compares it to a set string, returns Correct if
 *  the received string matches the set string, or Incorrect if it doesn't
 
 */
#include <Nextion.h>
#include <ESP8266WiFi.h>

//const char* ssid     = "cucu";

char buffer[100] = {0};

NexButton b5 = NexButton(0, 42, "b5");
NexText t1 = NexText(0, 50, "t1");
NexText t0 = NexText(0, 11, "t0");


NexTouch *nex_listen_list[] = 
{
    &t1,
    &t0,
    &b5,
    NULL
};

void b5PopCallback(void *ptr)
{
    String buf = "";
    int c = 0;
    memset(buffer, 0, sizeof(buffer)); //reset the buffer to be read
    t0.getText(buffer, sizeof(buffer)); // get the buffer from t0
    //str = String(buffer); //make the buffer into a string and give the value to str
   WiFi.mode(WIFI_OFF);//turn wi fi off - to reset the existing Password 
    for (int i = 0 ; i < sizeof(buffer) ; i++) 
     {
      if (buffer[i]!= NULL) 
      {
       buf+=buffer[i];
      }
     }
     c=buf.length();
     t1.setText(String(c).c_str());
     delay(1000);
   t1.setText(buf.c_str());
   delay(1000);
   WiFi.mode(WIFI_STA);
   WiFi.begin("cucu", buf.c_str());  

   if (WiFi.status() != WL_CONNECTED) 
   {
    //delay(500);
     t1.setText("NOT CONNECTED");
   }
   else
   {
    //delay(500);
     t1.setText("CONNECTED");
   }
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

