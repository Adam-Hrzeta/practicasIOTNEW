#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Configuración del LCD
Servo myservo;                      // Objeto para controlar el servo

int IR1 = 2;         // Pin del sensor IR
int Slot = 12;       // Número total de espacios de estacionamiento
int flag1 = 0;       // Bandera para detectar entrada/salida de vehículo

void setup() {
  Serial.begin(9600);

  // Inicializar la pantalla LCD
  lcd.init();
  lcd.backlight();

  // Configurar el pin del sensor IR
  pinMode(IR1, INPUT);

  // Configurar el servo
  myservo.attach(4);  // Pin del servo
  myservo.write(100); // Posición inicial (barrera cerrada)

  // Mensaje inicial en el LCD
  lcd.setCursor(0, 0);
  lcd.print("     ARDUINO    ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING TECH ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Detectar vehículo con IR1
  if (digitalRead(IR1) == LOW && flag1 == 0) {
    flag1 = 1; // Activar bandera

    if (Slot > 0) {
      // Reducir espacios disponibles si hay lugares
      myservo.write(0); // Abrir barrera
      Slot--;
      delay(2000);      // Tiempo para que pase el vehículo
      myservo.write(100); // Cerrar barrera
    } else {
      // Cuando el estacionamiento esté lleno, simular salida automática
      lcd.setCursor(0, 0);
      lcd.print("    SORRY :(    ");
      lcd.setCursor(0, 1);
      lcd.print("  Parking Full  ");
      delay(2000);
      lcd.clear();

      // Simular salida de un vehículo
      lcd.setCursor(0, 0);
      lcd.print("  SALIDA SIMULADA ");
      Slot++; // Incrementar espacios disponibles
      delay(2000);
      lcd.clear();
    }
  }

  if (digitalRead(IR1) == HIGH && flag1 == 1) {
    flag1 = 0; // Restablecer bandera
  }

  // Mostrar espacios restantes en el LCD
  lcd.setCursor(0, 0);
  lcd.print(" BIENVENIDO AMIGO! ");
  lcd.setCursor(0, 1);
  lcd.print("Slot Left: ");
  lcd.print(Slot);
  lcd.print(" "); // Limpiar caracteres sobrantes
  delay(500);
}

