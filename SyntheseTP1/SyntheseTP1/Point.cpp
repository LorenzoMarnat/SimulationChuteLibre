#include "Point.h"

void Point::Afficher()
{
	std::cout << "Position:" << std::endl;
	std::cout << "X: " << pos.GetX() << "  Y: " << pos.GetY() << "  Z: " << pos.GetZ() << std::endl;
	std::cout << "Vitesse:" << std::endl;
	std::cout << "X: " << speed.GetX() << "  Y: " << speed.GetY() << "  Z: " << speed.GetZ() << std::endl;
	std::cout << "Acceleration:" << std::endl;
	std::cout << "X: " << acc.GetX() << "  Y: " << acc.GetY() << "  Z: " << acc.GetZ() << std::endl;
	std::cout << std::endl;
}

std::string Point::ToString()
{
	return std::to_string(pos.GetX()) + " " + std::to_string(pos.GetY()) + " " + std::to_string(pos.GetZ()) + " " + std::to_string(speed.GetX()) + " " + std::to_string(speed.GetY()) + " " + std::to_string(speed.GetZ()) + " " + std::to_string(acc.GetX()) + " " + std::to_string(acc.GetY()) + " " + std::to_string(acc.GetZ());
}
void Point::NouvelleAcceleration()
{
	// a(t) = (-mgz - V(t) x Cd x ||V(t)||) / m               a -> accélération, m -> masse, g -> gravité, Cd -> coefficient, V -> vitesse
	acc.SetVector3(0, 0, -m * g);
	Vector3* vitesse = speed.MultiplicationNew(Cd * speed.Norme());
	acc.SoustractionVector3(*vitesse);
	acc.Multiplication(1 / m);
}

void Point::NouvelleVitesse()
{
	// V(t+deltaTime) = V(t) + a(t)*deltaTime
	Vector3* acceleration = acc.MultiplicationNew(deltaT);
	speed.AdditionVector3(*acceleration);
}

void Point::NouvellePosition()
{
	// P(t+deltaTime) = P(t) + V(t)*deltaTime
	Vector3* vitesse = speed.MultiplicationNew(deltaT);
	pos.AdditionVector3(*vitesse);
}

void Point::NouvellePositionVent()
{
	// P(t+deltaTime) = P(t) + V(t)*deltaTime + Vent
	Vector3* vitesse = speed.MultiplicationNew(deltaT);
	pos.AdditionVector3(*vitesse);
	pos.AdditionVector3(vent);
}