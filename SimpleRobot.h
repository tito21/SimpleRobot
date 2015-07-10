/**
	SimpleRobots - Simple Robot es una libreria Arduino que engloba alguna
	de las funciones más comunes para controlar robots

	https://github.com/tito21/SimpleRobot

	Created by Alberto Di Biase
*/

#ifndef SimpleRobot_H
#define SimpleRobot_H

// Compatibility for Arduino 1.0

#if ARDUINO >= 100
    #include "Arduino.h"
#else    
    #include "WProgram.h"
#endif

class SimpleRobot {

public:
	SimpleRobot();

	// Set pins motores H-Bridge
	void setMotorIzq(byte ePin, byte i1, byte i2);
	void setMotorDer(byte ePin, byte i1, byte i2);

	// Set Pins Sensores
	void setSensorTacto(byte pin);
	void setSensorDistancia(byte pin);

	// Movimiento
	void avanzar(int potencia);
	void retroceder(int potencia);
	void detener();
	void girarAdelante(int poteciaIzq, int potenciaDer);
	void girarAtras(int poteciaIzq, int potenciaDer);

	// Leer sensores
	int medirDistancia();
	int estadoTacto();

	// Esperar Sensores
	void esperarDistanciaMayor(int distancia);
	void esperarDistanciaMenor(int distancia);

	void esperarTactoPresionado();
	void esperarTactoSoltado();

private:

	// Motor pins for H-Bridge
	byte mIzq;
	byte mIzq1;
	byte mIzq2;
	byte mDer;
	byte mDer1;
	byte mDer2;

	// Sensor Pins
	byte sTacto;
	byte sDistancia;



};

#endif