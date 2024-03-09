//O display está configurado em cátodo comum

#define lamp 2 // Define a porta 2 como "lamp"
#define A 3  // Define a porta 3 como A
#define B 4  // Define a porta 4 como B
#define F 5  // Define a porta 5 como F
#define G 6  // Define a porta 6 como G
#define C 7  // Define a porta 7 como C
#define D 8  // Define a porta 8 como D
#define E 9  // Define a porta 9 como E

void setup(){
  pinMode(lamp, OUTPUT);  // Configura lamp como saída
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  // Configura as portas de A a G como saída
}

void loop(){
  digitalWrite(lamp, HIGH);  // Liga lamp
  if(digitalRead(lamp) == HIGH){  // Se lamp estiver ligada
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);  // Os segmentos B e C são ligados
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW); 
    digitalWrite(F, LOW);
  }
  delay(1500); // Espera 1 segundo e meio
  
  digitalWrite(lamp, LOW); // Desliga lam
  if(digitalRead(lamp) == LOW){  // Se lamp estiver desligada
    digitalWrite(A, HIGH); 
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);  //Os segmentos de A a F são ligados
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
  }
  delay(1500); // Espera 1 segundo e meio
}
