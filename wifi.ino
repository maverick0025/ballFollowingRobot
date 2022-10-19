
#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
String ssid="Redminote4";
String passowrd="ea187a81858b";
ESP8266WebServer.server(80);
#define led D4

void setup() {

  pinMode(D4,OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("...");
    delay(200);
  }
  Serial.print("Connected to:");
  Serial.println(WiFi.localIP());
  server.on("/on",ON);
  server.on("/off",OFF);
  

}

void loop() {
  server.handleclient();

}

void ON()
{
  digitalWrite(D2,HIGH);
  delay(1000);
  Serial.println("ON");
}

void OFF()
{
  digitalWrite(D2,LOW);
  delay(1000);
  Serial.println("OFF");
}
