#include <SimpleRobot.h>

SimpleRobot bot;

void setup() {
  bot.setMotorIzq(10, 7, 6);
  bot.setMotorDer(9, 4, 3);

}

void loop() {
  bot.avanzar(255);
  delay(1000);
  bot.girarAdelante(255, 0); // girar hacia la derecha
  delay(1000);
  bot.girarAdelante(0, 255); // girar hacia la izquierda
  delay(1000);
  bot.retroceder(255);
  delay(1000);
  bot.detener();
  delay(1000);
}
