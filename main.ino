#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "DHT.h"
#include <WiFi.h>

const char* ssid     = "STP-WiFi (2.4G)";       // <-- เปลี่ยนตรงนี้
const char* password = "petcharik217";   // <-- เปลี่ยนตรงนี้


#define DHTPIN 23    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT21

DHT dht(DHTPIN, DHTTYPE);

int _moisture,sensor_analog;
const int sensor_pin = 36; //analog moiture pin

int led[] = { 3, 4, 5, 26 };  //กำหนด pin led //26 -> buzzer
int sw[] = { 34, 35 };
int swp[] = {};
int sizePin = sizeof(led) / sizeof(led[0]);
int sizesw = sizeof(sw) / sizeof(sw[0]);
int sizeswp = sizeof(swp) / sizeof(swp[0]);

const int pingPin = 12;  //trig
int inPin = 13;          //echo

const int potPin = 14; // for  potentiometer
int potValue = 0;

LiquidCrystal_I2C lcd(0x27, 20, 4);  //LCD start


void setup() {
  Serial.begin(115200);

  // กำหนด pinMode เเบบ OUTPUT
  for (int i = 0; i < sizePin; i++) {
    pinMode(led[i], OUTPUT);
  }
  // กำหนด pinMode เเบบ INPUT
  for (int j = 0; j < sizesw; j++) {
    pinMode(sw[j], INPUT);
  }
  // กำหนด pinMode เเบบ INPUT_PULLUP
  for (int k = 0; k < sizeswp; k++) {
    pinMode(swp[k], INPUT_PULLUP);
  }
  lcdStart();
  if (digitalRead(34) == LOW) {
    maintain();
  }

  welcome();
  dht.begin();
  delay(1000);

  // Serial.println("📡 Connecting to WiFi...");
  // WiFi.begin(ssid, password);

  // // รอจนกว่าจะเชื่อมต่อสำเร็จ
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   digitalWrite(3, HIGH);
  //   delay(200);
  //   digitalWrite(3, LOW);
  //   delay(200);
  //   Serial.print(".");
  // }

  // Serial.println("\n✅ WiFi Connected!");
  // digitalWrite(3, HIGH);
  // Serial.print("📡 IP Address: ");
  // Serial.println(WiFi.localIP());
  scan_i2c();
}

void loop() {
  // lcd1602();
  // ultra("cm");
  // autoOffLcd();
  // buzzerON2(4, 500, 2000);
  // delay(5000);
  // Serial.print("time: ");
  // Serial.println(t);
  // moisture();
  // Dht();

  potValue = analogRead(potPin);
  int mapPlot = map(potValue, 0, 4095, 0, 100);
  // Serial.println(mapPlot);
  analogWrite(3, mapPlot);
  delay(500);
}

void maintain() {
  lc("Maintainance", 2, 0);
  lc("Mode", 6, 1);
  delay(3000);
  lcd.clear();
  delay(1000);
  buzzerON();
  delay(1000);
  lc("LED Test", 4, 0);
  ledRL(led, 'r', 500, 3);
  ledRL(led, 'l', 500, 3);
  lcd.clear();
  delay(1000);
  buzzerON();
  delay(1000);
  lc("Switch1 Test", 2, 0);
  while (digitalRead(34) == HIGH) {
    if (digitalRead(34) == LOW) {
      delay(1000);
      buzzerON();
      delay(1000);
      lc("Switch1 Tested", 2, 0);
      break;
    }
  }
  lcd.clear();
  lc("Switch2 Test", 2, 0);
  while (digitalRead(35) == HIGH) {
    if (digitalRead(35) == LOW) {
      delay(1000);
      buzzerON();
      delay(1000);
      lc("Switch2 Tested", 2, 0);
      break;
    }
  }
  lcd.clear();
  delay(1000);
  buzzerON();
  delay(1000);
  lc("LCD Test", 4, 0);
  for (int i=0; i<3; i++){
    lcd.backlight();
    delay(500);
    lcd.noBacklight();
    delay(500);
  }
  lcd.backlight();
  delay(1000);
  buzzerON();
  delay(1000);
  lcd.clear();
  while (true){
    lc("FINISH!", 4, 0);
  }
}
