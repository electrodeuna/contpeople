# Contador de Personas

Proyecto contador de personas con Arduino Nano y dos sensores ultrasónico, sumando cuando pasa una persona y restando cuando vuelve.

Video tutorial: https://www.youtube.com/watch?v=vZ2aniZn2JI

## Componentes

- Arduino Nano
- 2 Sensores Ultrasonicos Hc-sr04
- Pantalla Oled 1.3"
- Cables
- Protoboard

## Librerias

Las librerias utilizadas para este proyecto son "Adafruit_GFX" y "Adafruit_SH1106", se instalan desde el gestor de libreria del Arduino IDE.
Tambien se pueden descargar directamente e instalarlas en Arduino IDE desde Programa -> Incluir Librería -> Añadir biblioteca .ZIP

![image](https://user-images.githubusercontent.com/85527788/169146179-f601ad1e-b4b3-4a4c-ab23-7f3107fc234f.png)

- Adafruit_GFX: https://github.com/adafruit/Adafruit-GFX-Library
- Adafruit_SH1106: https://github.com/wonho-maker/Adafruit_SH1106

Una vez descargadas las librerias hay que renombrarlas antes de añadirlas al Arduino IDE, de la siguiente manera:

Adafruit-GFX-Library-master -> Adafruit-GFX
Adafruit_SH1106-master -> Adafruit_SH1106

## Observaciones

El código se puede utilizar en otro Arduino (por ejemplo, Arduino Uno). También se puede reemplazar la pantalla oled por otra similar, por ejemplo, Pantalla oled 0.96", en este caso hay que incluir otra libreria para que funcione (Adafruit_SD1306).
