#include <Servo.h> //INCLUSÃO DA BIBLIOTECA DO SERVO MOTOR
#include <Ultrasonic.h> //INCLUSÃO DA BIBLIOTECA PARA O SENSOR SONICO
 //  sudo chmod a+rw /dev/ttyACM0 erro o linux de permissão para upar os codigos no arduino
const int pinoServo = 6; //PINO DIGITAL UTILIZADO PELO SERVO  
const int echoPin = 7; //PINO DIGITAL UTILIZADO PELO SENSOR SONICO
const int trigPin = 5;
const int ledVermelho = 3;
const int ledVerde = 2;

Ultrasonic ultrasonic(trigPin, echoPin);
Servo s; //OBJETO DO TIPO SERVO
int pos; //POSIÇÃO DO SERVO
int distancia; //REGISTRO DA DISTANCIA
String result; // TRANSFORMA EM STRING A DISTANCIA

void setup (){
  s.attach(pinoServo); //ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO
  s.write(0); //INICIA O MOTOR NA POSIÇÃO 0º
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}
  //MÉTODO RESPONSÁVEL POR CALCULAR A DISTÂNCIA
void hcsr04() {
    digitalWrite(trigPin, LOW); //SETA O PINO 5 COM UM PULSO BAIXO "LOW"
    delayMicroseconds(2); //INTERVALO DE 2 MICROSSEGUNDOS
    digitalWrite(trigPin, HIGH); //SETA O PINO 5 COM PULSO ALTO "HIGH"
    delayMicroseconds(1); //INTERVALO DE 10 MICROSSEGUNDOS
    digitalWrite(trigPin, LOW); //SETA O PINO 5 COM PULSO BAIXO "LOW" NOVAMENTE
    //FUNÇÃO RANGING, FAZ A CONVERSÃO DO TEMPO DE
    //RESPOSTA DO ECHO EM CENTIMETROS, E ARMAZENA
    //NA VARIAVEL "distancia"
    distancia = (ultrasonic.Ranging(CM)); //VARIÁVEL GLOBAL RECEBE O VALOR DA DISTÂNCIA MEDIDA
    result = String(distancia); //VARIÁVEL GLOBAL DO TIPO STRING RECEBE A DISTÂNCIA(CONVERTIDO DE INTEIRO PARA STRING)
    delay(500); //INTERVALO DE 500 MILISSEGUNDOS
}

void controle() {

  for(pos = 0; pos < 80; pos++){ 
    s.write(pos); 
    delay(3); //valor de 3 milisegundos foi o suficiente para a garrafa de saida maior
  }
  delay(19000); //intervalo para teste sem o sensor
  for(pos = 80; pos >= 0; pos--){ 
    s.write(pos); 
    delay(3); //valor de 3 segundos foi o suficiente para a garrafa de saida maior
  }
  
}

void loop() {
  hcsr04(); // FAZ A CHAMADA DO MÉTODO "hcsr04()"
  //Serial.print("Distancia "); //IMPRIME O TEXTO NO MONITOR SERIAL
  //Serial.print(result); //IMPRIME NO MONITOR SERIAL A DISTÂNCIA MEDIDA
  //Serial.println("cm"); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println(distancia);
 
  if (distancia == 5){
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);
    controle();
    Serial.println("Condição atingida, ativando...");
  }else{
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
    Serial.println("Condição nao atingida");

  }

}
