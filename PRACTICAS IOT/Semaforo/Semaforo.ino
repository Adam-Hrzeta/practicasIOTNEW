//declaramos los pines a usar con el foco led
int rojo = 8;
int amarillo = 13;
int verde = 6;

void setup() {
  //apagamos todos los focos
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop() {
//encendemos el foco verde con una duración de 4000 milisegundos y despues lo apagamos y asi con los demas
digitalWrite(verde, HIGH);
delay(4000);
digitalWrite(verde, LOW);

digitalWrite(amarillo, HIGH);
delay(2000);
digitalWrite(amarillo, LOW);
delay(250);

digitalWrite(amarillo, HIGH);
delay(500);
digitalWrite(amarillo, LOW);
delay(250);

digitalWrite(amarillo, HIGH);
delay(500);
digitalWrite(amarillo, LOW);
delay(250);

digitalWrite(rojo, HIGH);
delay(4000);
digitalWrite(rojo, LOW);

}
