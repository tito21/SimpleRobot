#include <SimpleRobot.h>

SimpleRobot bot;

void setup() {

  bot.setSensorTacto(11);
  pinMode(13, OUTPUT);
  
}

void loop() {

  // Encender LED y esperar que el sensor este presionado
  digitalWrite(13, HIGH);
  bot.esperarTactoPresionado();

  // Apagar LED y esperar a que el sensor vuelva a estar liberado
  digitalWrite(13, LOW);
  bot.esperarTactoSoltado();
}
