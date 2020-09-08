#pragma once
#include <iostream>
#include <math.h>
#include <string>


// Vecteur 3D aux coordonnées (x,y,z)
class Vector3
{
protected: 
	float x, y, z;

public:
	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	

	float GetX() { return x; };

	float GetY() { return y; };

	float GetZ() { return z; };

	void SetVector3(float _x, float _y, float _z);

	// Additionne un vecteur V à ce vecteur
	void AdditionVector3(Vector3 v);

	// Soustrait un vecteur V à ce vecteur
	void SoustractionVector3(Vector3 v);

	// Multiplie les coordonnées de ce vecteur par un float
	void Multiplication(float c);

	// Multiplie les coordonnées de ce vecteur par un float dans un nouveau vecteur 
	Vector3* MultiplicationNew(float c);

	// Calcule la norme du vecteur
	float Norme();
};

