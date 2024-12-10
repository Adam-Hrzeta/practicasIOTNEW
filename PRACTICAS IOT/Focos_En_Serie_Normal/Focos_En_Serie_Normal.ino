//declaramos los pines a usar con el foco led
int led = 1;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;

void setup() {
  //apagamos todos los focos
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
//encendemos el foco verde con una duración de 4000 milisegundos y despues lo apagamos y asi con los demas
digitalWrite(led, HIGH);
delay(2000);
digitalWrite(led, LOW);
digitalWrite(led1, HIGH);
delay(2000);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
delay(2000);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
delay(2000);
digitalWrite(led3, LOW);
digitalWrite(led4, HIGH);
delay(2000);
digitalWrite(led4, LOW);
digitalWrite(led5, HIGH);
delay(2000);
digitalWrite(led5, LOW);

digitalWrite(led5, HIGH);
delay(2000);
digitalWrite(led5, LOW);
digitalWrite(led4, HIGH);
delay(2000);
digitalWrite(led4, LOW);
digitalWrite(led3, HIGH);
delay(2000);
digitalWrite(led3, LOW);
digitalWrite(led2, HIGH);
delay(2000);
digitalWrite(led2, LOW);
digitalWrite(led1, HIGH);
delay(2000);
digitalWrite(led1, LOW);
digitalWrite(led, HIGH);
delay(2000);
digitalWrite(led, LOW);

}
