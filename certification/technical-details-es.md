# Tiny Trainable Instruments - Detalles técnicos

Para construir los instrumentos, los participantes reciben un kit de materiales que consiste en materiales disponibles comercialmente en tiendas, cada uno en su paquete original directo desde el fabricante o distribuidor.

Los instrumentos son construidos con el microcontrolador Arduino que se conecta al protoboard electrónico, y haciendo conexiones con cables a otros componentes de bajo voltaje para hacer respuestas multimedia, en particular un zumbador piezoelectrónico para emitir sonido, y un micro motor servo para emitir movimiento.

![User guide output buzzer](../certification/images/user-guide-output-buzzer.jpg "User guide output buzzer")

![User guide output servo](../certification/images/user-guide-output-servo.jpg "User guide output servo")

Todas las conexiones realizadas y todas las partes están siendo usadas tal como es recomendado y enseñado por sus fabricantes. Todos los productos están disponibles en el comercio y no estamos haciendo ninguna modificación.

## Origen de los materiales

Los microcontroladores Arduino son fabricados en Italia y son enviados desde su distribuidor en Estados Unidos, y adquiridos directamente desde su tienda web en Estados Unidos, disponible en [https://store.arduino.cc/usa/](https://store.arduino.cc/usa/). Todos los otros materiales son adquiridos en Adafruit, una popular tienda en lína para principiantes, estudiantes y artistas, y son enviados desde su bodega en New York City Estados Unidos, y disponibles en [https://www.adafruit.com/](https://www.adafruit.com/).

## Fuente de poder

Los participantes usan como fuente de poder el cable USB conectado a sus computadores, el que opera a 5 Volts. El microcontrolador Arduino convierte esta fuente de poder a 3.3 Volts para su operación interna, y provee ese voltaje al resto del instrumento.

Usamos las luces LED en el microcontrolador Arduino como una confirmación visual para confirmar que el instrumento está encendido y funcionando.

![User guide usb on](../certification/images/user-guide-usb-on.jpg "User guide usb on")

Con esto, estamos usando una fuente de poder muy segura, donde el flujo de poder empieza en la fuente de poder de nuestro computador, pasa a través del computador, luego el cable USB, y finalemnte nuestro instrumento. Cada una de estas etapas limita el voltage y la corriente a niveles seguros, y también proveen mecanismos de seguro ante subidas súbitas que se apagan cuando hacemos un uso incorrecto de nuestro instrumento, por lo que el riesgo es mínimo.

Todas las conexiones que estamos haciendo son realizadas con cables seguros y aislados, en un protoboard electrónico estable, y siguiendo procedimientos populares hechos por estudiantes y principiantes en contextos educacionales simialres, así que no existen riesgos de electrocución ni de incendios.

El protoboard electrónico y todos los componentes que stamos usando son tolerantes a conexiones equivocadas, y no funcionarán o se apagarán cuando se haga una mala conexión, sin dañar al usuario, su computador, su instrumento, o su entorno.
