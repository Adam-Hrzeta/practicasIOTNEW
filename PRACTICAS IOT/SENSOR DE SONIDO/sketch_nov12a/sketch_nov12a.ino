const int pinSensorSonido = A0;  
const int numLEDs = 6;           
int leds[numLEDs] = {2, 3, 4, 5, 6, 7};  

void setup() {
  // Configura los pines de los LEDs como salida
  for (int i = 0; i < numLEDs; i++) {
    pinMode(leds[i], OUTPUT);
  }
  
  Serial.begin(9600); // Inicia la comunicación serial
}

void loop() {
  int nivelRuido = analogRead(pinSensorSonido); // Lee el valor analógico del sensor de sonido
  Serial.print("Valor crudo del sensor: ");
  Serial.println(nivelRuido); // Imprime el valor crudo para ver si está cambiando
  
  // Mapea el valor de 0-1023 (que es el rango del sensor analógico) a un rango de 0 a 28
  int ruidoMapeado = map(nivelRuido, 0, 1023, 0, 200);
  Serial.print("Nivel de ruido mapeado: ");
  Serial.println(ruidoMapeado); // Muestra el valor mapeado en el monitor serial
  
  // Decide cuántos LEDs encender según el nivel de ruido mapeado
  for (int i = 0; i < numLEDs; i++) {
    // Enciende el LED correspondiente si el valor de ruido mapeado es mayor que el umbral
    if (ruidoMapeado > (i * (38 / numLEDs))) {
      digitalWrite(leds[i], HIGH);  // Enciende el LED
    } else {
      digitalWrite(leds[i], LOW);   // Apaga el LED
    }
  }

  delay(100); // Retardo para estabilidad y lectura continua
}


