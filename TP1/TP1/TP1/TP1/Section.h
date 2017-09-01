#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <string>
#include "Professeur.h"
#include "Etudiant.h"



const int NB_ETUDIANTS_MAX = 75;

class Section{
public:
	Section();
	Section(const string& sigle, const string& local, 
		const string& titre, Professeur* prof);
	~Section();

	string getSigle() const;
	string getLocal() const;
	string getTitre() const;
	Professeur* getProfesseur() const;
	unsigned int getNbEtudiants() const;

	void setSigle(string sigle);
	void setLocal(string local);
	void setTitre(string titre);
	void setProfesseur(Professeur* prof);

	bool ajouterEtudiant(Etudiant* un);

	void afficher() const;

private:
	string sigle_;
	string local_;
	string titre_;
	Professeur* professeur_;
	Etudiant* etudiants_[NB_ETUDIANTS_MAX];
	unsigned int nbEtudiants_;
};



#endif