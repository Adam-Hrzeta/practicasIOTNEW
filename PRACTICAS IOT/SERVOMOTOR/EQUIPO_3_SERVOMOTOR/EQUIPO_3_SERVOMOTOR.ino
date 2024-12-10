#include <Servo.h>
Servo ioe;

int trig = 2;
int echo = 3;
int tiempo;
int distancia;

void setup () {
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  ioe.attach (4);
}

void loop () {
  digitalWrite (trig, HIGH);
  delay (500);
  digitalWrite (trig, LOW);
  tiempo=pulseIn(echo, HIGH);
  distancia=tiempo/58.2;
  delay(500);
  {
    if (distancia <= 10)
    (ioe.write(120));
    delay(2000);
  }
  {
    if (distancia >10);
    ioe.write(45);
  }
}
