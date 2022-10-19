#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
String ssid="Nokia 6";
String passowrd="ea187a81858b";
ESP8266WebServer.server(80);

void setup() {
    Serial.begin(115200);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("...");
    delay(200);
  }
  Serial.print("Connected to:");
  Serial.println(WiFi.localIP());
  server.on("/forward",forward);
  server.on("/break",break);
  server.on("/left",left);
  server.on("/right",right);
  pinMode(D4,OUTPUT);//D4 enable m1
  pinMode(D2,OUTPUT);//D2 input1 m1
  pinMode(D3,OUTPUT);//D3 input2 m1

  pinMode(D7,OUTPUT);//D7 enable m2
  pinMode(D5,OUTPUT);//D5 input1 m2
  pinMode(D6,OUTPUT);//D6 input2 m2


  Serial.begin(115200);
}

void loop() {
  server.handleClient();
}


void forward()
{
  server.send(200);
  analogWrite(D4,800);
  analogWrite(D7,800);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,LOW);
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW);

  Serial.println("Moving forward");
}


void left()
{
  server.send(200);
  analogWrite(D4,800);
  digitalWrite(D7,LOW);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,LOW);

  Serial.println("Moving left");
}

void right()
{
  server.send(200);
  digitalWrite(D4,LOW);
  analogWrite(D7,800);
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW);

  Serial.println("Moving right");
}

void break()
{
  server.send(200);
  digitalWrite(D4,LOW);
  digitalWrite(D7,LOW);

  Serial.println("Reached....");
}
