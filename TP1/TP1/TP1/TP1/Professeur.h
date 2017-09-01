#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <iostream>
#include <string>

using namespace std;

class Professeur{
public:
	Professeur();
	Professeur(const string& numero, const string& prenom, 
		const string& nom, const string& departement);
	~Professeur();

	string getNumero() const;
	string getPrenom() const;
	string getNom() const;
	string getDepartement() const;

	void setNumero(string numero);
	void setPrenom(string prenom);
	void setNom(string nom);
	void setDepartement(string departement);

	void afficher() const;

private:
	string numeroEmploye_;
	string prenom_;
	string nom_;
	string departement_;
};

#endif