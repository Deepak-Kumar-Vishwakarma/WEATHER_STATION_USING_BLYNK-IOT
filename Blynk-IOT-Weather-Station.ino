#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3K8MSt9_q"
#define BLYNK_TEMPLATE_NAME "weather station"
#define BLYNK_AUTH_TOKEN "Jne4EHcNoo9nuUjolcH1IoJFdy4Hf6F4"

#include <DHT.h>
#include <Wire.h>
#include <WiFiClient.h>
#include <Arduino.h>
#include <BlynkSimpleEsp32.h>


//Define the pin
int gas = 32;
int sensorThreshold = 100;
#define RAIN_ANALOG 34
#define RAIN_DIGITAL 16
#define DHTPIN 33
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

//Replace with your Blynk Auth Token
char auth[] ="YourAuthToken";

// Replace with your WiFi credentials
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

void sendSensor(){
        int analogSensor = analogRead(gas);
  Blynk.virtualWrite(V2, analogSensor);
  Serial.print("Gas Value: ");
    Serial.println(analogSensor);
}


void setup() {
   
   Serial.begin(115200);
   Serial.print("Connecting to WiFi.");
   dht.begin();
   
   WiFi.begin(ssid, pass , 6);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
   }
   Serial.println("WiFi connected");
   Blynk.begin(auth , ssid , pass);

   Wire.begin();
   Serial.begin(115200);
  
    // put your setup code here, to run once:like input output and pin
  
   pinMode(RAIN_ANALOG, INPUT);
   pinMode(RAIN_DIGITAL, INPUT);
   analogReadResolution(10);
   Serial.begin(115200);

   pinMode(gas, INPUT);       //Air Quality
   pinMode(35, INPUT);        //IR Radiation
   analogReadResolution(10);

}


void loop() {
  //Gas sensor 

  int gasValue = analogRead(gas);
  gasValue=map(gasValue , 0 , 1023 , 0 , 100);
 
  Serial.println("\nWEATHER STATION!\n");
  delay(200);
  
  //LDR sensor

  float LDR=analogRead(35);
  LDR=map(LDR , 0 , 1015 , 100 , 0);

  Serial.print("IR Radiation:");
  Serial.println(LDR);

  delay(200);
   

  //rain sensor

  float r_a=analogRead(RAIN_ANALOG);
  boolean r_d=digitalRead(RAIN_DIGITAL);
  
  r_a=map(r_a , 0 , 1023 , 100 ,0);

  Serial.print("Rain amount: ");
  Serial.println(r_a);
  if (r_d>=10)
    Serial.println("It's raining!");
  delay(200);

  // DHT22
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    
    Serial.print("\n");
    Serial.print("Temperature="+String(temperature)+"°C");
    Serial.print("\t");
    Serial.print("Humidity="+String(humidity)+"%");
    
    //Blynk iot

    Blynk.virtualWrite(V0, temperature);
    Blynk.virtualWrite(V1, humidity);
    Blynk.virtualWrite(V2, r_a);
    Blynk.virtualWrite(V4, LDR);
    Blynk.virtualWrite(V3, gasValue);
 
  }
  
  delay(200);
  
 Serial.print("\nGas Value:");
 Serial.print(gasValue);
  if(gasValue<15)
  {
    
    Serial.print("\nGas Value: ");
    Serial.print(gasValue);
    Serial.println("\t\tFresh Air");
    delay(1000);
 
  }
  else if(gasValue>15)
  {
  
    Serial.print("\nGas Value: ");
    Serial.print(gasValue);
   
    Serial.println("\t\tBad Air");
    delay(1000);

  }

   if(gasValue > 75){
    //Blynk.email("Your_emailaddress", "Alert", "Bad Air!");
    Blynk.logEvent("pollution_alert","Bad Air");
  }
}
   


