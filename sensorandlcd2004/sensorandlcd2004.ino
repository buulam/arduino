#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header

hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip

// LCD geometry
const int LCD_COLS = 20;
const int LCD_ROWS = 4;

const int trigPin = 5;
const int echoPin = 6;

int led = 12;
int led2 = 4;
int led3 = 3;
int brightness = 250;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

long duration;
int distanceCm, distanceInch;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  analogWrite(led, 0);
  analogWrite(led2, 0);
  analogWrite(led3, 0);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;
  
  lcd.begin(LCD_COLS, LCD_ROWS);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distanceCm);
  lcd.print("cm");
  if (distanceCm < 5) {
    lcd.setCursor(0, 3);
    lcd.print("Hello Stella");
    analogWrite(led, brightness);
    }
    else if (distanceCm < 10) {
        analogWrite(led2, brightness);
    }
    else if (distanceCm < 20) {
      analogWrite(led3, brightness);
  }
  delay(100);
  }
