#include <SimpleRobot.h>

SimpleRobot bot;

void setup() {
  
  Serial.begin(9600);
  
  // Configurar pins de los sensores
  bot.setSensorTacto(11);
  bot.setSensorDistancia(0);

}

void loop() {

  // Leer el valor de los sensores
  int tacto = bot.estadoTacto();
  int distancia = bot.medirDistancia();

  // Mostrar en pantalla el valor de los sensores  
  Serial.print("Tacto: ");
  Serial.print(tacto);
  Serial.print(" Distancia: ");
  Serial.println(distancia);

}