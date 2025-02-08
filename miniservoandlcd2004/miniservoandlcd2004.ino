/* Buu Lam - move servo and display the position */

#include <Servo.h>
#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header

hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

// LCD geometry
const int LCD_COLS = 20;
const int LCD_ROWS = 4;

int brightness = 250;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  lcd.print("Servo movement: ");
  lcd.print(pos);
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Servo movement: ");
  lcd.print(pos);
  delay(1000);
}
