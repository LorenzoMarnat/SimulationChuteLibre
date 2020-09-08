#pragma once
#include "Vector3.h"

// 
class Point
{
protected:
	float m;
	float g;
	float Cd;
	float deltaT;
	Vector3 speed;
	Vector3 pos;
	Vector3 acc;
	Vector3 vent;

public:


	Point(float _m, float _g, float _Cd, Vector3* _V0, Vector3* _P0, float _deltaT)
	{
		m = _m;
		g = _g;
		Cd = _Cd;
		deltaT = _deltaT;
		speed.SetVector3(_V0->GetX(), _V0->GetY(), _V0->GetZ());
		pos.SetVector3(_P0->GetX(), _P0->GetY(), _P0->GetZ());
	};

	float Getm() { return m; };
	float Getg() { return g; };
	float GetCd() { return Cd; };
	float GetdeltaT() { return deltaT; };

	Vector3 GetSpeed() { return speed; };
	Vector3 GetPos() { return pos; };
	Vector3 GetAcc() { return acc; };
	Vector3 GetVent() { return vent; };

	void SetVent(float x, float y, float z) { vent.SetVector3(x, y, z); };
	// Calcule l'accélération au temps t
	void NouvelleAcceleration();
	
	// Calcule la vitesse au temps t
	void NouvelleVitesse();

	// Calcule la position au temps t
	void NouvellePosition();

	// Calcule la position en prenant en compte le vent 
	void NouvellePositionVent();

	// Affiche la position, la vitesse et l'accélération
	void Afficher();

	// Renvoit la position, la vitesse et l'accélération sous forme de string
	std::string ToString();
};

