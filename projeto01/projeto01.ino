#define GreenLED 11
#define RedLED 9
#define botao 2

void setup() {
    Serial.begin(9600);
    pinMode(GreenLED, OUTPUT); //estabelece o pino GreenLED como porta de saída
    pinMode(RedLED, OUTPUT); //estabelece o pino RedLED como porta de saída
    pinMode(botao, INPUT_PULLUP);
}

void loop() {
  float m1 = 0; //declaração da variável "m1"
  float m2 = 0; //declaração da variável "m2"
  float m3 = 0; 
  float m4 = 0; 
  float mediaFinal = 0; //declaração da variável "mediaFinal"

  Serial.print("Digite sua primeira media: "); //printa a mensagem na tela do usuário
  while(Serial.available() == 0);
  
  if(Serial.available() > 0){
    m1 = Serial.read(); //atribui o valor dado pelo usuário à variável "m1"
    Serial.println(m1);
  }
  
  delay(100);

  Serial.print("\nDigite sua segunda media: ");  //printa a mensagem na tela do usuário
  while(Serial.available() == 0);
  
  if(Serial.available() > 0){
    m2 = Serial.read();  //atribui o valor dado pelo usuário à variável "m2"
    Serial.println(m2);
  }
  
  delay(100);

  Serial.print("\nDigite sua terceira media: ");  //printa a mensagem na tela do usuário
  while(Serial.available() == 0);

  if(Serial.available() > 0){
    m3 = Serial.read();  //atribui o valor dado pelo usuário à variável "m3"
    Serial.println(m3);
  }
  
  delay(100);

  Serial.print("\nDigite sua quarta media: ");  //printa a mensagem na tela do usuário
  while(Serial.available() == 0);

  if(Serial.available() > 0){
    m4 = Serial.read();  //atribui o valor dado pelo usuário à variável "m4"
    Serial.println(m4);
  }
  
  delay(100);

  mediaFinal = (m1 + m2 + m3 + m4) / 4; //cálculo da  entre as quatro médias
  
  if(mediaFinal >= 55){ //se média maior ou igual a 28
    digitalWrite(GreenLED, HIGH); //GreenLED é aceso
    Serial.println("Estudante aprovado.\n"); //printa "Estudante aprovado" na tela
  } else{
      digitalWrite(GreenLED, LOW); //GreenLED se mantém desligado
    }
    
  if(mediaFinal < 55){ //se media menor que 28
    digitalWrite(RedLED, HIGH); //RedLED é aceso
    Serial.println("Estudante reprovado.\n"); //printa "Estudante reprovado" na tela
    } else{
      digitalWrite(RedLED, LOW); //RedLED se mantém desligado
    }

  while(digitalRead(botao) == HIGH);
  
  digitalWrite(GreenLED, LOW);
  digitalWrite(RedLED, LOW);
  
}