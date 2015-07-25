#include <SimpleRobot.h>

SimpleRobot bot;

void setup() {
  delay(1000);
  bot.setMotorDer(10, 11, 10); 
  bot.setMotorIzq(3, 5, 6);

}

void loop() {
  bot.avanzar(255);
  delay(500);
  /*bot.girarIzquierda(128); // girar hacia la izquierda
  delay(500);
  bot.girarDerecha(128); // girar hacia la derecha
  delay(500);*/
  bot.retroceder(128);
  delay(500);
  bot.detener();
  delay(1000);
}