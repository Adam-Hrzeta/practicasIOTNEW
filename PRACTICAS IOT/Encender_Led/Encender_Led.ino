void setup()
{
  for (int i=1;i<=6;i++){
    pinMode(i, OUTPUT);
 }

}

void loop()
{
  for (int i=6;i>=1;i--){
    digitalWrite(i, HIGH); // enciende el led de posicion i
    delay(500); // n segundos de demora
  }
  for (int i=1;i<=6;i++){
    digitalWrite(i, LOW); //apaga el led de posicion i
    delay(500); // n segundos de demora
  }
}
