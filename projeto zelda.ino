#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA
 //  sudo chmod a+rw /dev/ttyACM0 erro o linux 
const int pinoServo = 6; //PINO DIGITAL UTILIZADO PELO SERVO  
 
Servo s; //OBJETO DO TIPO SERVO
int pos; //POSIÇÃO DO SERVO
 
void setup (){
  s.attach(pinoServo); //ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO
  s.write(0); //INICIA O MOTOR NA POSIÇÃO 0º
}
void loop(){
  for(pos = 0; pos < 80; pos++){ //PARA "pos" IGUAL A 0, ENQUANTO "pos" MENOR QUE 80, INCREMENTA "pos"
    s.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
    delay(25); //INTERVALO DE 15 MILISSEGUNDOS
  }
  delay(9000); //INTERVALO DE 1 SEGUNDO
  for(pos = 80; pos >= 0; pos--){ //PARA "pos" IGUAL A 80, ENQUANTO "pos" MAIOR OU IGUAL QUE 0, DECREMENTA "pos"
    s.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
    delay(15); //INTERVALO DE 15 MILISSEGUNDOS
  }
}