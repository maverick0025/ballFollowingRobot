char a;

void setup() {
  pinMode(D4,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);

  pinMode(D7,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);


  Serial.begin(115200);
}

void loop() {
  if(Serial.available()>0)
  {
    a=Serial.read();
    if(a=='f')
    {
      forward();
    }
    if(a=='l')
    {
      left();
    }
    if(a=='r')
    {
      right();
    }
    if(a=='b')
    {
      back();
    }
  }

}


void forward()
{
  digitalWrite(D4,HIGH);
  digitalWrite(D7,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,LOW);
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW);
}


void left()
{
  digitalWrite(D4,HIGH);
  digitalWrite(D7,LOW);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,LOW);
}

void right()
{
  digitalWrite(D4,LOW);
  digitalWrite(D7,HIGH);
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW);
}


void back()
{
  digitalWrite(D4,HIGH);
  digitalWrite(D7,HIGH);
  digitalWrite(D2,LOW);
  digitalWrite(D3,HIGH);
  digitalWrite(D5,LOW);
  digitalWrite(D6,HIGH);
}
