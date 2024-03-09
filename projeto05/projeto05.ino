#include <LiquidCrystal.h>  // Inclusão da biblioteca
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);  // Instância da biblioteca e as portas conectadas aos pinos do LCD (RS, E, DB4, DB5, DB6, DB7)

byte cedilha[8]={B00000,B00000,B01111,B10000,B10000,B01111,B00100,B01000};
/* Esse é um parâmetro para criar um caractere especial que chamei de "cedilha",
 para isso utilizei um site que compõe caracteres para display
 */
byte grau[8]={B00010,B00101,B00010,B00000,B00000,B00000,B00000,B00000};
// Parâmetro para criar um caractere que chamei de "grau"

#define TMP A0  // Porta para o sensor (TMP 36)
#define Botton 10 // Porta para o botão
#define backL 9  // Porta para o backlight

void setup() {
  lcd.begin(16, 2);  // Inicialização do display
  lcd.createChar(1, cedilha); // Cria o caractere "cedilha"
  lcd.createChar(2, grau); // Cria o caractere "grau"
  lcd.clear();  // Função para limpar o display e garantir que não tenha nada na tela ao iniciar o programa
  pinMode(Botton, INPUT_PULLUP);  // Configura Botton com o modo INPUT_PULLUP
  pinMode(backL, OUTPUT);  // Configura backL como saída
  digitalWrite(backL, LOW); // Garante que o programa é iniciado com o backlight desligado
}

void loop() {
  float temp = (analogRead(TMP) * (5.0/1023) - 0.53)/0.0093;
  /* Função matemática que associa a cada valor de tensão elétrica,
    oriunda do sensor (TMP 36), uma temperatura */
  
  if(digitalRead(Botton) == LOW){  // Se o botão for pressionado
    digitalWrite(backL, !digitalRead(backL));  //o backlight muda de estado
  }
     
  lcd.setCursor(1, 0);  // Estabelece em que quadrícula a escrita deve iniciar no display (coluna, linha)
  lcd.print("Esperan"); // Mostra o nome da cidade no display. Por conveniência, escolhi Esperança.
  lcd.setCursor(8, 0);
  lcd.write(1); // Escreve o "ç" do nome Esperança
  lcd.setCursor(9, 0);
  lcd.print("a - PB");
  lcd.setCursor(4, 1);
  lcd.print(temp); // Mostra a temperatura ambiente no display
  lcd.setCursor(10, 1);
  lcd.write(2); // Mostra o caractere "grau" (º)
  lcd.setCursor(11, 1);
  lcd.print("C");  // Celsius
}
