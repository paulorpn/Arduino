#define pinLED1 13 
#define pinLED2 12
#define pinLED3 11

void setup() {
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
}

void loop() {
  unsigned int intervalo = 250; //Crindo a variável "intervalo" com o valor 250.
  
  static unsigned long instante1 = 0; // Criando a variável "instante" com o valor 0.
 
  if((millis() - instante1) < (2 * intervalo)){  //Se millis() menor que 500ms
    digitalWrite(pinLED1, HIGH);
  } else{
    digitalWrite(pinLED1, LOW);
  }
  if((millis() - instante1) >= (3 * intervalo)){  //Se millis() maior ou igual a 750ms
    instante1 = millis();  //a função millis() reinicia a contagem do tempo de execussão  
  }
  
  static unsigned long instante2 = 0;

  if((millis() - instante2) < (2 * intervalo)){  //Se millis() menor que 500ms
    digitalWrite(pinLED2, HIGH);  
  } else{
    digitalWrite(pinLED2, LOW);
  }
  if((millis() - instante2) >= (4 * intervalo)){  //Se millis() maior ou igual a 1000ms
    instante2 = millis();  //a função millis() reinicia a contagem do tempo de execussão                
  }

  static unsigned long instante3 = 0;
  
  if((millis() - instante3) < (4 * intervalo)){  //Se millis() maior ou igual a 1000ms
    digitalWrite(pinLED3, HIGH);
  } else{
    digitalWrite(pinLED3, LOW);
  }
  if((millis() - instante3) >= (7 * intervalo)){  //Se millis() maior ou igual a 1750ms
    instante3 = millis();  //a função millis() reinicia a contagem do tempo de execussão                  
  }

}
