#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <iostream>

class Employe
{
public:
	Employe(std::string nom, std::string prenom);

	std::string getNom() const;
	std::string getPrenom() const;
	virtual unsigned int getNiveauAcces() const;
	virtual std::string getClasseEmploye() const;

	friend std::ostream& operator<< (std::ostream& os, const Employe& unEmploye);

protected:
	std::string nom_;
	std::string prenom_;

private:
	const unsigned int accesEmploye_ = 5;
};


#endif //EMPLOYE_H