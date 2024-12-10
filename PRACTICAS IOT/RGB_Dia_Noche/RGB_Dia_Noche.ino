int ldr = 8;
int rojo = 2;
int verde = 3;
int azul = 4;
int valor;
int limite = 220;
int dt = 500;

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT); 
  pinMode(azul, OUTPUT);
}

void loop() {
  valor = analogRead(ldr);  
  Serial.println(valor);
  delay(dt);
  
  if (valor >= limite) {
    Serial.println("Es de noche");  
    
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(azul, HIGH); 
    delay(1000);
  } else {
    Serial.println("Es de día"); 
    
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(azul, HIGH); 
    delay(2000);
    
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(azul, LOW); 
    delay(2000);
  }
}



