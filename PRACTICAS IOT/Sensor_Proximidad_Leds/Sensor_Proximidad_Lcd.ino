#include <LiquidCrystal.h>

int trig = 10;  // Pin del trig del sensor ultrasónico
int eco = 9;    // Pin del echo del sensor ultrasónico
int distancia;  // Distancia medida por el sensor
int duracion;
int led3 = 8;  
int led4 = 11;  
int led5 = 12;  
int led6 = 13;   

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);

  // Configuración de pines
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);

  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  // Configuración del LCD
  lcd.begin(16, 2);
}

void loop() {
  // Medir la distancia con el sensor ultrasónico
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duracion = pulseIn(eco, HIGH);
  distancia = duracion / 58.2;

  // Mostrar distancia en el LCD
  lcd.setCursor(0, 0);
  lcd.print("Distancia: ");
  lcd.print(distancia);
  lcd.print(" cm ");
  Serial.println(distancia);

  // Control del LED según la distancia
  control_Led(distancia);

  delay(100);
}

void control_Led(int led_encender_distancia) {
  // Si la distancia es mayor a 50 cm, apagar todos los LEDs
  if (led_encender_distancia > 50) {
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
  } else {
    // Encender LEDs acumulativamente según la distancia
    if (led_encender_distancia <= 35) 
    digitalWrite(led3, HIGH);
    delay(100);
    if (led_encender_distancia <= 25) 
    digitalWrite(led4, HIGH);
        delay(100);
    if (led_encender_distancia <= 15) 
    digitalWrite(led5, HIGH);
        delay(100);
    if (led_encender_distancia <= 5)  
    digitalWrite(led6, HIGH);
        delay(100);
  }
}



