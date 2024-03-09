/*
  //Função utilizada para descobrir o valor referente à tempC de 30ºC lido pela entrada analógica 3
  
  int tempC = 0;  //A variável inteira "tempC" é declarada e é atribuido o valor 0 a ela
  int pinSensor = A3;  //Atribuindo a porta analógica 3 à variável inteira "pinSensor"
  
  void setup(){
    Serial.begin(9600);  //Inicialização da função serial
  }

  void loop(){
    tempC = analogRead(pinSensor);  //O valor lido pela porta pinSensor é atribuído à variável tempC
    Serial.println(tempC);  //O valor de tempC é mostrado no monitor serial
  }
  
 */

#define GreenLED 12  //Definindo a porta 12 como GreenLED
#define RedLED 2  //Definindo a porta 2 como RedLED

int tempC = 0; //A variável inteira "tempC" é declarada e é atribuido o valor 0 a ela
int pinSensor = A3;  //Atribuindo a porta analógica 3 à variável inteira "pinSensor"

void setup(){
 pinMode(GreenLED, OUTPUT); //Estabelecendo GreenLED como porta de saída
 pinMode(RedLED, OUTPUT);  //Estabelecendo RedLED como porta de saída
}

void loop(){
  tempC = analogRead(pinSensor);  //O valor lido pela porta pinSensor é atribuído à variável tempC
  
  if(tempC <= 166){ 
    digitalWrite(GreenLED, HIGH);  //Se tempC for menor ou igual a 166 (valor referente a 30ºC), GreenLED é ligado
  } else{
    digitalWrite(GreenLED, LOW);  //Se tempC não for menor ou igual a 166, GreenLED é/continua ligado
  }

  if(tempC > 166){
    digitalWrite(RedLED, HIGH);  //Se tempC for maior que 166, GreenLED é ligado
  } else{
    digitalWrite(RedLED, LOW);  //Se tempC não for maior que 166, GreenLED é/continua desligado
  }

}
