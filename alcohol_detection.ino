#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// I2C LCD address might be 0x27 or 0x3F — adjust if needed
LiquidCrystal_I2C lcd(0x27, 16, 2);

// GSM module TX to pin 10, RX to pin 11
SoftwareSerial gsm(10, 11);

// MQ3 analog pin
const int alcoholPin = A0;

// Relay control pin
const int relayPin = 8;

// Alcohol threshold
const int threshold = 400;

void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  gsm.begin(9600);

  pinMode(alcoholPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Engine ON by default

  lcd.setCursor(0, 0);
  lcd.print("Alcohol Detector");
  delay(2000);
  lcd.clear();
}

void loop() {
  int alcoholLevel = analogRead(alcoholPin);
  lcd.setCursor(0, 0);
  lcd.print("Alcohol: ");
  lcd.print(alcoholLevel);
  Serial.println(alcoholLevel); // For debugging

  if (alcoholLevel > threshold) {
    lcd.setCursor(0, 1);
    lcd.print("Alcohol Detected!");
    digitalWrite(relayPin, LOW); // Engine OFF
    sendSMS();
    delay(10000); // Avoid repeated SMS
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Safe to Drive    ");
    digitalWrite(relayPin, HIGH); // Engine ON
  }

  delay(1000);
}

void sendSMS() {
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+911234567890\""); // Replace with your number
  delay(1000);
  gsm.println("Alert! Driver is drunk. Engine has been stopped.");
  gsm.write(26); // ASCII code for CTRL+Z
  delay(5000);
}
