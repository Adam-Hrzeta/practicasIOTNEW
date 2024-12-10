#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

int led = 3;               // Pin del LED
int SENSOR = 11;           // Pin del sensor DHT11
int FOTORESISTENCIA = A0;  // Pin de la fotoresistencia (analógico)
float temperaturaC;
float temperaturaF;
int humedad;
DHT dht(SENSOR, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();            // Inicializar el sensor DHT
  pinMode(led, OUTPUT);   // Configurar el pin LED como salida
}

void loop() {
  // Leer la temperatura en Celsius y la humedad
  temperaturaC = dht.readTemperature();
  humedad = dht.readHumidity();

  // Leer el valor de la fotoresistencia
  int luz = analogRead(FOTORESISTENCIA);

  // Convertir la temperatura a Fahrenheit
  temperaturaF = (temperaturaC * 9.0 / 5.0) + 32;

  // Verificar si hubo errores en la lectura del sensor
  if (isnan(temperaturaC) || isnan(humedad)) {
    Serial.println("Error al leer el sensor DHT.");
    return;
  }

  // Mostrar las temperaturas, humedad y nivel de luz en formato JSON
  Serial.println("{ \"tempC\": " + String(temperaturaC) + 
                 ", \"tempF\": " + String(temperaturaF) +  
                 ", \"humedad\": " + String(humedad) + 
                 ", \"luz\": " + String(luz) + " }");

  // Encender el LED si la temperatura es mayor o igual a 28 °C
  if (temperaturaC >= 28) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW); // Apagar el LED si la temperatura es menor a 28 °C
  }

  delay(500); // Esperar 500 ms antes de la siguiente lectura
}
