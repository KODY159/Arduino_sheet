#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "DHT.h"
#include <ESP32Servo.h>

//bluetooth
// #include "BluetoothSerial.h"
// BluetoothSerial SerialBT;

//For bylnk wifi
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
// Enter your Auth token
char auth[] = "Ltfsio7aRTu5JDooFTPm_w2am6knk8GI";
//Enter your WIFI SSID and password
char ssid[] = "Free wifi for my nigga";
char pass[] = "k12345678";

//DHT
#define DHTPIN 23  // Digital pin connected to the DHT sensor
#define DHTTYPE DHT21
DHT dht(DHTPIN, DHTTYPE);

//gas sensor
#define AO_GAS 33

//buzzer
#define buzzer 26

//Motion sensor
#define Motion 18
int val = 0;  // for Motion

//relay
#define relay 23

//servo
Servo myservo;
#define servoPin 19

//mositure
int _moisture, sensor_analog;
const int sensor_pin = 36;  //analog moiture pin

int led[] = { 3, 4, 5 };  //กำหนด pin led
int sw[] = { 34, 35 };
int swp[] = {};  //INPUT_PULLBACK switch
//sizeof
int sizePin = sizeof(led) / sizeof(led[0]);
int sizesw = sizeof(sw) / sizeof(sw[0]);
int sizeswp = sizeof(swp) / sizeof(swp[0]);

//Ultrasonic sensor
const int pingPin = 12;  //trig
int inPin = 13;          //echo

const int potPin = 14;  // for  potentiometer
int potValue = 0;


LiquidCrystal_I2C lcd(0x27, 16, 2);  //LCD start

//----------------------------------------------------------------------------------
//setup
void setup() {
  Serial.begin(115200);

  //Blynk connect
  // Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  // กำหนด pinMode เเบบ OUTPUT
  for (int i = 0; i < sizePin; i++) {
    pinMode(led[i], OUTPUT);
  }
  pinMode(26, OUTPUT);  // for buzzer
  pinMode(23, OUTPUT);
  // กำหนด pinMode เเบบ INPUT
  for (int j = 0; j < sizesw; j++) {
    pinMode(sw[j], INPUT);
  }
  pinMode(33, INPUT);  // for gas
  pinMode(18, INPUT);  // for Motion
  // กำหนด pinMode เเบบ INPUT_PULLUP
  for (int k = 0; k < sizeswp; k++) {
    pinMode(swp[k], INPUT_PULLUP);
  }

  //maintainance Mode
  if (digitalRead(34) == LOW) {
    maintain();
  }

  // myservo.attach(servoPin); //servo
  //lcd setup
  lcdStart();
  welcome();
  // dht.begin();
  delay(1000);

  // delay(20000);
  // scan_i2c();

  //bluetooth setup
  // SerialBT.begin("ESP32_BT_Device");  // Bluetooth device name
  // Serial.println("Bluetooth started! Pair with 'ESP32_BT_Device'");
}

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

//timer
// const int tt = 5;
// int ttt = tt;

void loop() {
  //distance using ultrasonic
  // lcd.clear();
  // lcd.setCursor(4, 0);
  // lcd.print("Distance :");
  // int disT = ultra("cm");
  // lcd.setCursor(6, 1);
  // lcd.print(disT);
  //blync analog for altrasonic
  // Blynk.virtualWrite(V0, disT);

  // Serial.print(disT);
  // Serial.print("cm");
  // Serial.println();
  // delay(100);
  // Blynk.run();

  // timer.run();
  // lcd1602();
  // ultra("cm");
  // autoOffLcd();
  // buzzerON2(4, 500, 2000);
  // delay(5000);
  // Serial.print("time: ");
  // Serial.println(t);

  // moisture();
  // Dht();
  // gas();
  // MotionFunc();

  //relay
  // delay(4000);
  // relayForward();
  // delay(4000);
  // relayReverse();

  //servo
  // for (int i=0; i<=179; i+=90){
  //   myservo.write(i);
  //   delay(200);
  // }
  // for (int i=179; i>=0; i-=90){
  //   myservo.write(i);
  //   delay(200);
  // }

  //timer auto off _
  // int cm = ultra("cm");
  // if (cm > 10) {
  //   if (ttt <= 0) {
  //     lcd.noBacklight();
  //     ttt = tt;
  //   } else {
  //     delay(1000);
  //     ttt--;
  //   }
  // } else {
  //   lcd.backlight();
  //   ttt = tt;
  // }
}

//relay func
void relayON() {
  digitalWrite(23, HIGH);
}
void relayOFF() {
  digitalWrite(23, LOW);
}
void relayReverse() {
  digitalWrite(23, HIGH);
  digitalWrite(22, LOW);
}
void relayForward() {
  digitalWrite(22, HIGH);
  digitalWrite(23, LOW);
}

//maintainance mode
void maintain() {
  lcdStart();
  lcd.clear();
  lc("Maintainance", 2, 0);
  lc("Mode", 6, 1);
  delay(3000);
  lcd.clear();
  delay(1000);
  buzzerON2(1, 200, 500);
  delay(1000);
  lc("LED Test", 4, 0);
  ledRL(led, 'r', 500, 3);
  ledRL(led, 'l', 500, 3);
  lcd.clear();
  delay(1000);
  buzzerON2(1, 200, 500);
  delay(1000);
  lc("Switch1 Test", 2, 0);
  while (digitalRead(34) == HIGH) {
    if (digitalRead(34) == LOW) {
      delay(1000);
      buzzerON2(1, 200, 500);
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
      buzzerON2(1, 200, 500);
      delay(1000);
      lc("Switch2 Tested", 2, 0);
      break;
    }
  }
  lcd.clear();
  delay(1000);
  buzzerON2(1, 200, 500);
  delay(1000);
  lc("LCD Test", 4, 0);
  for (int i = 0; i < 3; i++) {
    lcd.backlight();
    delay(500);
    lcd.noBacklight();
    delay(500);
  }
  lcd.backlight();
  delay(1000);
  buzzerON2(1, 200, 500);
  delay(1000);
  lcd.clear();
  while (true) {
    lc("FINISH!", 4, 0);
  }
}
