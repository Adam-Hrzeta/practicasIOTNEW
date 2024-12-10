#include <LiquidCrystal.h>

int trig = 10; // Pin del trig del sensor ultrasónico
int eco = 9;   // Pin del echo del sensor ultrasónico
int distancia; // Distancia medida por el sensor
int duracion;
//int limiteDistancia = 20; // Límite para la distancia

int led = 13;   // LED 


LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 

void setup() {
  Serial.begin(9600);

  // Configuración de pines
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(led, OUTPUT);

  // Configuración del LCD
  lcd.begin(16, 2);
}

void loop() {
  // Control del LED por el LDR

  // Medir la distancia con el sensor ultrasónico
  digitalWrite(trig, HIGH);
  delay(1);  
  digitalWrite(trig, LOW);
  int duracion = pulseIn(eco, HIGH);
  distancia = duracion / 58.2;

  // Mostrar distancia en el LCD
  lcd.setCursor(0, 1);
  lcd.print("Distancia:");
  lcd.print(distancia);
  lcd.print("cm ");
  Serial.println(distancia);

  //Control del LED por la distancia
  if (distancia <= 20) {
    digitalWrite(led, HIGH);
    delay (100);
  } else {
    digitalWrite(led, LOW);
    delay(100);
  }
}

