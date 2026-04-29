#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Funny2";
const char* password = "mamyissues";



String apiKey = "KI8EGPCHY1H0N2B0";

const int sensorPin = D4;  // GPIO2

const char* server = "api.thingspeak.com";

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
}

void loop() {
  int val = digitalRead(sensorPin);

  int fieldValue;
  if (val == LOW) {
    fieldValue = 1;   // Have IV
    Serial.println("Have IV");
  } else {
    fieldValue = 0;   // Low IV
    Serial.println("Low IV");
  }

  WiFiClient client;

  if (client.connect(server, 80)) {
    String url = "/update?api_key=" + apiKey + "&field1=" + String(fieldValue);

    Serial.println(url);  // DEBUG

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: api.thingspeak.com\r\n" +
                 "Connection: close\r\n\r\n");
  }

  delay(15000);  // VERY IMPORTANT (ThingSpeak limit)
}
