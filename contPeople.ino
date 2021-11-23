#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

const int trigPin = 7;
const int echoPin = 6;
const int trigPin2 = 9;
const int echoPin2 = 8;
long duration, duration2;
int distance1, distance2, initialDistance1, initialDistance2;
int personas = 0; 
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET); /* Object of class Adafruit_SSD1306 */

const unsigned char PROGMEM youtube [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00,
0x00, 0x00, 0x1C, 0x1C, 0x00, 0x00, 0x01, 0xC0, 0x03, 0xFF, 0x87, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x1C, 0x1E, 0x00, 0x00, 0x01, 0xC0, 0x03, 0xFF, 0x87, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x1E, 0x1C, 0x00, 0x00, 0x01, 0xC0, 0x03, 0xFF, 0x87, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x0E, 0x3C, 0x00, 0x00, 0x03, 0xFC, 0x3F, 0xFF, 0x87, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x0E, 0x38, 0x00, 0x00, 0x03, 0xFC, 0x3F, 0xFF, 0x87, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x0F, 0x78, 0x00, 0x00, 0x03, 0xFC, 0x3F, 0xFF, 0x86, 0xFF, 0xBF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x0F, 0x78, 0xFC, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x80, 0x7C, 0x07, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x07, 0x71, 0xFE, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x80, 0x38, 0x03, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x07, 0xF1, 0xFF, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x80, 0x38, 0x03, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x07, 0xF3, 0xCF, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x84, 0x30, 0xC3, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xE3, 0xC7, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x86, 0x10, 0xE1, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xE3, 0xC7, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x86, 0x10, 0xE1, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xE3, 0xC7, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x86, 0x10, 0xE1, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xE3, 0xC7, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x86, 0x10, 0x01, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xC3, 0xC7, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x86, 0x10, 0x01, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xC3, 0xC7, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x86, 0x10, 0x01, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xC3, 0xC7, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x86, 0x10, 0xFF, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xC3, 0xC7, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x86, 0x10, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xC3, 0xC7, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x86, 0x10, 0xE1, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xC3, 0xC7, 0x78, 0xE3, 0xFC, 0x38, 0x61, 0x86, 0x10, 0xE1, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xC3, 0xCF, 0x79, 0xE3, 0xFC, 0x38, 0x61, 0x84, 0x30, 0xE1, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xC1, 0xEF, 0x7B, 0xE3, 0xFC, 0x38, 0x01, 0x80, 0x38, 0x43, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xC0, 0xFC, 0x3E, 0xE1, 0xFC, 0x38, 0x21, 0x80, 0x3C, 0x07, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x38, 0x18, 0x01, 0xFC, 0x3C, 0x61, 0xC4, 0x7F, 0x1F, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0xE6, 0x0F, 0x1E, 0x7E, 0x7C, 0x78, 0xC9, 0x1E, 0x0C, 0x07, 0x8F, 0x04, 0x4C, 0x86, 0x00,
0x01, 0x06, 0x08, 0x31, 0x08, 0x44, 0xCC, 0xC9, 0x31, 0x0C, 0x04, 0x48, 0x04, 0x4C, 0x86, 0x00,
0x01, 0x06, 0x08, 0x20, 0x08, 0x44, 0x84, 0xC9, 0x20, 0x1C, 0x04, 0x48, 0x04, 0x4C, 0x8E, 0x00,
0x01, 0xE6, 0x0F, 0x20, 0x08, 0x44, 0x84, 0xE9, 0x20, 0x16, 0x04, 0x6F, 0x04, 0x4E, 0x8B, 0x00,
0x01, 0x06, 0x08, 0x20, 0x08, 0x78, 0x84, 0xB9, 0x20, 0x32, 0x04, 0x68, 0x04, 0x4B, 0x99, 0x00,
0x01, 0x06, 0x08, 0x20, 0x08, 0x48, 0x84, 0x99, 0x20, 0x3F, 0x04, 0x48, 0x04, 0x49, 0x9F, 0x80,
0x01, 0x06, 0x08, 0x31, 0x08, 0x44, 0xCC, 0x99, 0x31, 0x23, 0x04, 0x48, 0x06, 0xC9, 0x91, 0x80,
0x01, 0xE7, 0xCF, 0x1E, 0x08, 0x46, 0x78, 0x99, 0x1E, 0x61, 0x07, 0x8F, 0x03, 0x89, 0xB0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);//CONFIGURA LA DIRECCION DEL DISPLAY
  display.clearDisplay();//BORRAR DISPLAY
  display.setTextColor(WHITE);//TEXTO EN COLOR BLANCO
  display.setTextSize(2);//TAMAÑO DE LA LETRA (SE PUDE AJUSTRAR CON DECIMALES EJEMPLO (1.1, 1.2, 1.3...)
  display.setCursor(0,0);
  display.drawBitmap(0,0,youtube,128,64,WHITE);
  display.display();
  delay(3000);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  initialDistance1 = duration*0.034/2;
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  initialDistance2 = duration2*0.034/2;
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance1= duration*0.034/2;

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;
    
  if(distance1 < initialDistance1-30) {
    personas += 1;
    delay(700);//TIEMPO DE ESPERA
  }
  else if(distance2 < initialDistance2-30 && personas > 0) {
    personas = personas - 1;
    delay(700);//TIEMPO DE ESPERA
  }
 
  display.clearDisplay();//BORRAR DISPLAY
  display.setCursor(10,5);//POSICION DE INICIO DE ESCRITURA
  display.println("Personas");//TEXTO EN PANTALLA
  display.setCursor(50,30);
  display.println(personas);
  display.display();
}