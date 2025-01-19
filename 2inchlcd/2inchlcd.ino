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
  //strDistanceCm = String(distanceCm);
  //charDistanceCm = strDistanceCm[0];
  doubleDistanceCm = double(distanceCm);
  
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  //Paint_Clear(WHITE);
  Paint_DrawString_EN(30, 10, "Distance: ", &Font20, YELLOW, RED);
  Paint_DrawNum(30, 34, doubleDistanceCm, &Font20, BLUE, CYAN);
  Paint_DrawString_EN(60, 34, "cm", &Font20, YELLOW, RED);
  //Paint_DrawString_EN(30, 34, charDistanceCm, &Font24, BLUE, CYAN);
  
  // Paint_DrawString_CN(50,180, "微雪电子",  &Font24CN, WHITE, RED);
  
  //Paint_DrawRectangle(125, 10, 225, 58, RED,  DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
  //Paint_DrawLine(125, 10, 225, 58, MAGENTA,   DOT_PIXEL_2X2,LINE_STYLE_SOLID);
  //Paint_DrawLine(225, 10, 125, 58, MAGENTA,   DOT_PIXEL_2X2,LINE_STYLE_SOLID);
  
//  Paint_DrawCircle(150,100, 25, BLUE,   DOT_PIXEL_2X2,   DRAW_FILL_EMPTY);
//  Paint_DrawCircle(180,100, 25, BLACK,  DOT_PIXEL_2X2,   DRAW_FILL_EMPTY);
//  Paint_DrawCircle(210,100, 25, RED,    DOT_PIXEL_2X2,   DRAW_FILL_EMPTY);
//  Paint_DrawCircle(165,125, 25, YELLOW, DOT_PIXEL_2X2,   DRAW_FILL_EMPTY);
//  Paint_DrawCircle(195,125, 25, GREEN,  DOT_PIXEL_2X2,   DRAW_FILL_EMPTY);
//  
//  
//
//  Paint_DrawImage(gImage_70X70, 20, 80, 70, 70); 
  //Paint_DrawFloatNum (5, 150 ,987.654321,4,  &Font20,    WHITE,   LIGHTGREEN);
  delay(100);
}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/