#include <DHT.h>

DHT dht(D6,DHT11);
float t4[4]={0,0,0,0};
float h4[4]={0,0,0,0};
int c=0;
void setup() {
  // put your setup code here, to run once:
 pinMode(A0,INPUT);
 pinMode(D5,OUTPUT);
 Serial.begin(9600);
 dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println(analogRead(A0));
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float ta=0;
  float ha=0;
  t4[c]=t;
  h4[c]=h;
  for(int i=0;i<4;i++)
  {
    ta+=t4[i];
    ha+=h4[i];
  }
  ta = ta/4;
  ha = ha/4;
  Serial.print("Temperature: ");
  Serial.println(t);
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("4h Average Temperature: ");
  Serial.println(ta);
  Serial.print("4h Average Humidity: ");
  Serial.println(ha);  
  if(c==3)
  {
    c=0;
  }
  else
  {
    c++;
  }
  if (h>90)
  {
    Serial.println("Possibility of rain");
  }
  if (analogRead(A0)<950)
  {
    digitalWrite(D5,HIGH);
    Serial.println("Day Time!");
  }
  else
  {
    digitalWrite(D5,LOW);
    Serial.println("Night Time!");
  }
  delay(1000);
}
