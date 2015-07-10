/**
	SimpleRobots - Simple Robot es una libreria Arduino que engloba alguna
	de las funciones más comunes para controlar robots

	https://github.com/tito21/SimpleRobot

	Created by Alberto Di Biase
*/

#include "SimpleRobot.h"

SimpleRobot::SimpleRobot() {
	setMotorDer(1, 2, 3);
	setMotorIzq(4, 5, 6);
	setSensorTacto(10);
	setSensorDistancia(0);

}

/**
	Pins
*/
void SimpleRobot::setMotorIzq(byte ePin, byte i1, byte i2) {

	mIzq = ePin;
	mIzq1 = i1;
	mIzq2 = i2;

	pinMode(mIzq, OUTPUT);
	pinMode(mIzq1, OUTPUT);
	pinMode(mIzq2, OUTPUT);


}
void SimpleRobot::setMotorDer(byte ePin, byte i1, byte i2) {

	mDer = ePin;
	mDer1 = i1;
	mDer2 = i2;

	pinMode(mDer, OUTPUT);
	pinMode(mDer1, OUTPUT);
	pinMode(mDer2, OUTPUT);

}

void SimpleRobot::setSensorTacto(byte pin) {
	
	sTacto = pin;

	pinMode(sTacto, INPUT);

}
void SimpleRobot::setSensorDistancia(byte pin){
	
	sDistancia = pin;

}

/**
	Movimiento
*/
void SimpleRobot::avanzar(int potencia) {
	
	analogWrite(mDer, potencia);
	analogWrite(mIzq, potencia);

	digitalWrite(mDer1, HIGH);
	digitalWrite(mDer2, LOW);

	digitalWrite(mIzq1, HIGH);
	digitalWrite(mIzq2, LOW);

}

void SimpleRobot::retroceder(int potencia) {

	analogWrite(mDer, potencia);
	analogWrite(mIzq, potencia);

	digitalWrite(mDer1, LOW);
	digitalWrite(mDer2, HIGH);

	digitalWrite(mIzq1, LOW);
	digitalWrite(mIzq2, HIGH);

}

void SimpleRobot::detener() {

	digitalWrite(mDer, LOW);
	digitalWrite(mIzq, LOW);

}

void SimpleRobot::girarAdelante(int potenciaIzq, int potenciaDer) {

	analogWrite(mDer, potenciaDer);
	analogWrite(mIzq, potenciaIzq);

	digitalWrite(mDer1, HIGH);
	digitalWrite(mDer2, LOW);

	digitalWrite(mIzq1, HIGH);
	digitalWrite(mIzq2, LOW);
}

void SimpleRobot::girarAtras(int potenciaIzq, int potenciaDer) {

	analogWrite(mDer, potenciaDer);
	analogWrite(mIzq, potenciaIzq);

	digitalWrite(mDer1, LOW);
	digitalWrite(mDer2, HIGH);

	digitalWrite(mIzq1, LOW);
	digitalWrite(mIzq2, HIGH);


}

/**
	Lectura de Sensores
*/

int SimpleRobot::medirDistancia() {
	delay(200);
	return analogRead(sDistancia);
}

int SimpleRobot::estadoTacto() {
	delay(200);
	return digitalRead(sTacto);
}

/**
	Esperar Sensores
*/
void SimpleRobot::esperarDistanciaMayor(int distancia){
	int d = medirDistancia();
	while (d > distancia) {
		d = medirDistancia();
	}
}

void SimpleRobot::esperarDistanciaMenor(int distancia) {
	int d = medirDistancia();
	while (d < distancia) {
		d = medirDistancia();
	}
}

void SimpleRobot::esperarTactoPresionado() {
	int t = estadoTacto();
	while (t > 0) {
		t = estadoTacto();
	}
}
void SimpleRobot::esperarTactoSoltado() {
	int t = estadoTacto();
	while (t < 1) {
		t = estadoTacto();
	}
}