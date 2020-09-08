#include "Point.h"
#include <fstream>

using namespace std;

int main()
{
	// Gravité
	float g = 9.8;
	// Masse
	float m = 80;
	// Coefficient de frottement
	float Cd = 0.25;
	// Delta Time
	float deltaT = 1;
	// Position à T0
	Vector3* P0 = new Vector3(0,0,4000);
	// Vitesse à T0
	Vector3* V0 = new Vector3(50, 0, 0);

	Point* Bob = new Point(m, g, Cd, V0, P0, deltaT);

	string const results("results.csv");
	ofstream flux(results.c_str());

	if (flux)
	{
		Bob->SetVent(10, 0, 0);
		flux << "T posX posY posZ vitX vitY vitZ accX accY accZ" << endl;
		for (int i = 1; i <= 60; i++)
		{
			// Calcule l'acceleration, la vitesse et la position à Ti
			Bob->NouvelleAcceleration();
			Bob->NouvelleVitesse();
			Bob->NouvellePosition();
			//Bob->NouvellePositionVent();

			// Affiche l'acceleration, la vitesse et la position dans la console
			Bob->Afficher();

			flux << to_string(i) + " " + Bob->ToString() << endl;
		}
	}
	else
	{
		cout << "Erreur: impossible d'ouvrir le fichier" << endl;
	}

	return 0;
	
}