# Contador de Personas

Proyecto contador de personas con Arduino Nano y dos sensores ultrasónicos, sumando cuando pasa una persona y restando cuando vuelve.

Video tutorial: https://www.youtube.com/watch?v=vZ2aniZn2JI

![IMG_20211128_195424_398](https://user-images.githubusercontent.com/85527788/169410917-14e17a98-3726-4c27-b31e-bc5906e55c61.jpg) 

![20211128_194632](https://user-images.githubusercontent.com/85527788/169410933-4de0460c-da84-4a18-bc91-fe9e937ad866.jpg)


## Componentes

- Arduino Nano
- 2 Sensores Ultrasónicos Hc-sr04
- Pantalla Oled 1.3"
- Cables
- Protoboard

## Librerías

Las librerías utilizadas para este proyecto son "Adafruit_GFX" y "Adafruit_SH1106", se instalan desde el gestor de librería del Arduino IDE.
También se pueden descargar directamente e instalarlas en Arduino IDE desde Programa -> Incluir Librería -> Añadir biblioteca .ZIP

![image](https://user-images.githubusercontent.com/85527788/169146179-f601ad1e-b4b3-4a4c-ab23-7f3107fc234f.png)

- Adafruit_GFX: https://github.com/adafruit/Adafruit-GFX-Library
- Adafruit_SH1106: https://github.com/wonho-maker/Adafruit_SH1106

Una vez descargadas las librerías hay que renombrarlas antes de añadirlas al Arduino IDE, de la siguiente manera:

- Adafruit-GFX-Library-master -> Adafruit-GFX
- Adafruit_SH1106-master -> Adafruit_SH1106

## Observaciones

El código se puede utilizar en otro Arduino (por ejemplo, Arduino Uno). También se puede reemplazar la pantalla oled por otra similar, por ejemplo, Pantalla oled 0.96", en este caso hay que incluir otra libreria para que funcione (Adafruit_SSD1306).
