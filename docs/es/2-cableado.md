# Cableado

## Convenciones

Cables:

* Rojo = Poder 3.3 V desde Arduino
* Verde = Tierra desde Arduino

## Protoboard

Las protoboards están construidas para que en cada fila, los 5 puntos en las columnas con la etiqueta `a-e` están conectados eléctricamente dentro de la placa como un solo nodo eléctrico, y lo mismo ocurre con `f-j`. 

Adicionalmente, hay 2 columnas a cada lado de la protoboard; donde cada columna está interconectada entre sí. Convencionalmente, conectamos el voltaje positivo a la columna `+`, y tierra a la columna `-`.

Una guía completa está disponible en [https://learn.adafruit.com/breadboards-for-beginners/breadboards](https://learn.adafruit.com/breadboards-for-beginners/breadboards).

## Microcontrolador Arduino

El Arduino Nano 33 BLE sense que usamos tiene 30 pins en total, 15 por cada lado. La guía oficial de cada pin está disponible en [https://content.arduino.cc/assets/Pinout-NANOsense_latest.pdf](https://content.arduino.cc/assets/Pinout-NANOsense_latest.pdf).

Recomendamos ubicar el microcontrolador en la parte superior de la protoboard (C1 a C15 y G1 a G15), con el puerto USB micro hacia arriba.

![Arduino placement](../../docs/images/2-arduino-placement.jpg "Arduino on breadboard")

Nota que el microcontrolador debe estar rasante con la protoboard, ninguno de los pines headers debería estar visible.

![Arduino sideview](../../docs/images/2-arduino-sideview.jpg "Arduino sideview")

## Tu primer ejemplo

Conecta tu microcontrolador Arduino a tu computador con el cable USB y abre el software Arduino IDE.

En la sección para elegir la placa (board), selecciona `Arduino Nano 33 BLE`.

![Select board](../../docs/images/2-select-board.jpg "Select board")

Luego asegúrate que tu puerto seleccionado es tu Arduino, el número es irrelevante, y el texto cambia entre computadores.

![Select port](../../docs/images/2-select-port.jpg "Select port")

Ahora abramos el ejemplo `check_serial`, incluido con la biblioteca TinyTrainable.

![Open example](../../docs/images/2-open-example.jpg "Open example")

Haz click en la flecha de la derecha para subir tu código (upload), lo que mostrará en la parte inferior de la ventana de la Arduino IDE, un mensaje de compilando bosquejo `Compiling sketch`.

![Compiling sketch](../../docs/images/2-compiling-sketch.jpg "Compiling sketch")

La compilación puede tomar algunos minutos, y luego de terminar, el mensaje cambiará a subiendo `Uploading...`

![Uploading example](../../docs/images/2-uploading-example.jpg "Uploading example")

Este proceso es más corto, y después de terminar anunciará que la subida fue realizada `Done uploading`.

![Done uploading](../../docs/images/2-done-uploading.jpg "Done uploading")

En la esquina superior derecha de la ventana, haz click en el ícono de lupa para abrir el monitor serial `Serial monitor`. Asegúrate que la configuración de la parte inferior de la ventana sea la misma en tu computador, y eso es todo!

![check_serial output](../../docs/images/2-check-serial-output.jpg "check_serial output")

Acabas de subir tu primer ejemplo a tu Arduino, que ahora está ocupado enviando los mensajes que ves en la pantalla, y también mostrando todas las luces que tiene :)

## Outputs

### Buzzer

For the next example, check_buzzer, we'll need to install a piezo buzzer. First, notice that the 14th pin on the left side and the 12th pin on the right side are labelled with white paint; this marks ground, also identified on the pinout. Take a wire (preferably green by convention for ground) and connect it from I12 to anywhere on the top righthand negative rail (the upper 25 pins), like this:

![Connecting the ground wire](../../docs/images/2-ground-wire.jpg "Ground wire")

Next, connect one of the legs of the piezo buzzer to the node labelled D8 on the pinout (which should be row 5 on the breadboard). Connect the other leg to the ground rail. Your wiring should look like this:

![Installing the piezo buzzer](../../docs/images/2-piezo-buzzer-placement.jpg "Piezo buzzer on breadboard")

Now you're good to go! Upload ```check_buzzer``` to the microcontroller, open the serial monitor (top right button in the Arduino IDE), and follow the instructions from there!

### LED

### MIDI

MIDI Din jack

5 pins, only 3 are used.

### Printer

We are using a thermal printer from Adafruit.

https://www.adafruit.com/product/2753

It has 5 cables:

VH - red - connect to the power supply 5V - 9V
DTR - yellow - connect to GND on the Arduino
TX - green - data out of the printer
RX - blue - data in to the printer
GND - black - connect to GND on the Arduino

We use a power supply, whose ground  is connected to the one on the Arduino.

The power supply is 9V, center positive.
Here is one available:
https://www.adafruit.com/product/276

### Serial

With a serial cable into a computer.
