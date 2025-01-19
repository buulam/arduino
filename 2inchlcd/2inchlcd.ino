/*
Buu Lam
Simple demo program using multiple sensors and outputs with Arduino Uno R3 based boards
*/

#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h"
#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header

hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip

// LCD geometry
const int LCD_COLS = 20;
const int LCD_ROWS = 4;

const int trigPin = 5;
const int echoPin = 6;

long duration;
int distanceCm, distanceInch;
String strDistanceCm;
char charDistanceCm;
double doubleDistanceCm;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Config_Init();
  LCD_Init();
  LCD_Clear(0xffff);
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
}
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;
  doubleDistanceCm = double(distanceCm);

  Paint_DrawString_EN(30, 10, "Distance: ", &Font20, YELLOW, RED);
  Paint_DrawNum(30, 34, doubleDistanceCm, &Font20, BLUE, CYAN);
  Paint_DrawString_EN(60, 34, "cm", &Font20, YELLOW, RED);

  delay(100);
}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/