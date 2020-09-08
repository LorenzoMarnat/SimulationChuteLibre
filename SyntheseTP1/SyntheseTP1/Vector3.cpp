#include "Vector3.h"

void Vector3::SetVector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
};

void Vector3::AdditionVector3(Vector3 V)
{
	x += V.GetX();
	y += V.GetY();
	z += V.GetZ();
}

void Vector3::SoustractionVector3(Vector3 V)
{
	x -= V.GetX();
	y -= V.GetY();
	z -= V.GetZ();
}

void Vector3::Multiplication(float c)
{
	x = x * c;
	y = y * c;
	z = z * c;
}

Vector3* Vector3::MultiplicationNew(float c)
{
	Vector3* m = new Vector3(x * c, y * c, z * c);

	return m;
}

float Vector3::Norme()
{
	// Racine carrée de (x^2 + ^y^2 + z^2)
	return sqrt(pow(GetX(), 2) + pow(GetY(), 2) + pow(GetZ(), 2));
}