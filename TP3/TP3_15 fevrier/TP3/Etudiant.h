#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "Employe.h"
#include <iostream>

class Etudiant : Employe
{
public:
	Etudiant(std::string nom, std::string prenom);
	virtual unsigned int getNiveauAcces() const;
	virtual std::string getClasseEmploye() const;

	friend  std::ostream& operator<< (std::ostream& os, const Etudiant& unEtudiant);
private:
	const unsigned int accesEtudiant_ = 1;
};

#endif //ETUDIANT_H