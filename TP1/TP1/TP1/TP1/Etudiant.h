#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <iostream>
#include <string>


class Etudiant {
public:
	Etudiant();
	Etudiant(const std::string& matricule, const std::string& prenom, 
		const std::string& nom);
	~Etudiant();

	std::string getMatricule() const; 
	std::string getPrenom() const;
	std::string getNom() const;

	void setMatricule(std::string matricule);
	void setPrenom(std::string prenom);
	void setNom(std::string nom);

	void afficher() const;

private:
	std::string matricule_;
	std::string prenom_;
	std::string nom_;
};

#endif