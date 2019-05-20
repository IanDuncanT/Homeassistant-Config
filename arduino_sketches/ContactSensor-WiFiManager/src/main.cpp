#include <Arduino.h>
#include <FS.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>


char mqtt_server[40];
char mqtt_port[6] = "1883";
char mqtt_topic_1[40];
char mqtt_topic_2[40];
char static_ip[16] = "10.0.1.56";
char static_gw[16] = "10.0.1.1";
char static_sn[16] = "255.255.255.0";
bool shouldSaveConfig = true;
WiFiClient espClient;
PubSubClient client(espClient);

int state16 = 0;
int prevstate16 = 0;
char sstate16[1];
int state5 = 0;
int prevstate5 = 0;
char sstate5[1];

void saveConfigCallback () {
  Serial.println("Should save config");
  shouldSaveConfig = true;
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Mounting FS...");

  if (SPIFFS.begin()) {
    Serial.println("Mounted file system");
    if (SPIFFS.exists("/config.json")) {
      Serial.println("Reading config file");
      File configFile = SPIFFS.open("/config.json", "r");
      if (configFile) {
        Serial.println("Opened config file");
        DynamicJsonDocument jsonBuffer(1024);
        DeserializationError error = deserializeJson(jsonBuffer, configFile);
        if (!error) {
          Serial.println("\nParsed json");
          strcpy(mqtt_server, jsonBuffer["mqtt_server"]);
          strcpy(mqtt_port, jsonBuffer["mqtt_port"]);
          strcpy(mqtt_topic_1, jsonBuffer["mqtt_topic_1"]);
          strcpy(mqtt_topic_2, jsonBuffer["mqtt_topic_2"]);

          if(jsonBuffer["ip"]) {
            Serial.println("Setting custom ip from config");
            strcpy(static_ip, jsonBuffer["ip"]);
            strcpy(static_gw, jsonBuffer["gateway"]);
            strcpy(static_sn, jsonBuffer["subnet"]);
            Serial.println(static_ip);
          } else {
            Serial.println("No custom ip in config");
          }
        } else {
          Serial.println("Failed to load json config");
        }
      }
    }
  } else {
    Serial.println("Failed to mount FS");
  }

  Serial.println(static_ip);
  Serial.println(mqtt_server);
  Serial.println(mqtt_topic_1);
  Serial.println(mqtt_topic_2);

  WiFiManagerParameter custom_mqtt_server("server", "mqtt server", mqtt_server, 40);
  WiFiManagerParameter custom_mqtt_port("port", "mqtt port", mqtt_port, 5);
  WiFiManagerParameter custom_mqtt_topic_1("topic_1", "mqtt topic 1", mqtt_topic_1, 40);
  WiFiManagerParameter custom_mqtt_topic_2("topic_2", "mqtt topic 2", mqtt_topic_2, 40);

  WiFiManager wifiManager;
  wifiManager.setSaveConfigCallback(saveConfigCallback);

  // IPAddress _ip,_gw,_sn;
  // _ip.fromString(static_ip);
  // _gw.fromString(static_gw);
  // _sn.fromString(static_sn);
  //
  // wifiManager.setSTAStaticIPConfig(_ip, _gw, _sn);

  wifiManager.addParameter(&custom_mqtt_server);
  wifiManager.addParameter(&custom_mqtt_port);
  wifiManager.addParameter(&custom_mqtt_topic_1);
  wifiManager.addParameter(&custom_mqtt_topic_2);

  wifiManager.setMinimumSignalQuality();
  wifiManager.setTimeout(120);

  if (!wifiManager.autoConnect("Contact-Sensor-Setup", "default-password")) {
    Serial.println("Failed to connect and hit timeout");
    delay(3000);
    ESP.reset();
    delay(5000);
  }

  Serial.println("Connected to network");
  Serial.println(WiFi.localIP().toString());

  //read updated parameters
  strcpy(mqtt_server, custom_mqtt_server.getValue());
  strcpy(mqtt_port, custom_mqtt_port.getValue());
  strcpy(mqtt_topic_1, custom_mqtt_topic_1.getValue());
  strcpy(mqtt_topic_2, custom_mqtt_topic_2.getValue());

  //save the custom parameters to FS
  if (shouldSaveConfig) {
    Serial.println("Saving config");
    DynamicJsonDocument jsonBuffer(1024);

    jsonBuffer["mqtt_server"] = mqtt_server;
    jsonBuffer["mqtt_port"] = mqtt_port;
    jsonBuffer["mqtt_topic_1"] = mqtt_topic_1;
    jsonBuffer["mqtt_topic_2"] = mqtt_topic_2;
    jsonBuffer["ip"] = WiFi.localIP().toString();
    jsonBuffer["gateway"] = WiFi.gatewayIP().toString();
    jsonBuffer["subnet"] = WiFi.subnetMask().toString();

    File configFile = SPIFFS.open("/config.json", "w");
    if (!configFile) {
      Serial.println("Failed to open config file for writing");
    }
    serializeJson(jsonBuffer, configFile);
    configFile.close();
  }

  Serial.println("local ip");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.gatewayIP());
  Serial.println(WiFi.subnetMask());

  pinMode(16, INPUT);
  pinMode(5, INPUT);
  client.setServer(mqtt_server, atoi(mqtt_port));
}

void reconnect() {
  while(!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    if(client.connect(clientId.c_str())) {
      Serial.println("MQTT connected");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println("Try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  state16 = digitalRead(16);
  state5 = digitalRead(5);
  if (state16 != prevstate16) {
    prevstate16 = state16;
    Serial.println(state16);
    itoa(state16, sstate16, 10);
    client.publish(mqtt_topic_1, sstate16);
    Serial.println("Change deteted 16: " + String(sstate16));
  }
  if (state5 != prevstate5) {
    prevstate5 = state5;
    Serial.println(state5);
    itoa(state5, sstate5, 10);
    client.publish(mqtt_topic_2, sstate5);
    Serial.println("Change deteted 5: " + String(sstate5));
  }
}
