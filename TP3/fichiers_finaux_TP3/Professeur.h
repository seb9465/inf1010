#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "Employe.h"
#include <iostream>

class Professeur : public Employe
{
public:
	Professeur(std::string nom, std::string prenom);

	virtual unsigned int getNiveauAcces() const;
	virtual std::string getClasseEmploye() const;

	friend std::ostream& operator<< (std::ostream& os, const Professeur& unProfesseur);

private:
	const unsigned int accesProfesseur_ = 10;
};

#endif //PROFESSEUR_H