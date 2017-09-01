
#include "Etudiant.h"

using namespace std;

//Constructeur par défaut.
//Initialisation des attributs à des chaines de caractères vides.
Etudiant::Etudiant(){
	matricule_ = "";
	prenom_ = "";
	nom_ = "";
}

//Constructeur par paramètres.
//Initialisation des attributs selon les paramètres.
Etudiant::Etudiant(const string& matricule, const string& prenom, const string& nom){
	matricule_ = matricule;
	prenom_ = prenom;
	nom_ = nom;
}

//Destructeur.
Etudiant::~Etudiant(){
}

//Méthodes d'accès.
string Etudiant::getMatricule() const {
	return matricule_;
}
string Etudiant::getPrenom() const {
	return prenom_;
}
string Etudiant::getNom() const {
	return nom_;
}

//Méthode de modification des attributs.
void Etudiant::setMatricule(string matricule){
	matricule_ = matricule;
}
void Etudiant::setPrenom(string prenom){
	prenom_ = prenom;
}
void Etudiant::setNom(string nom){
	nom_ = nom;
}

//Méthode d'affiche des informations qui concernent un étudiant.
void Etudiant::afficher() const {
	cout << "Matricule : " << matricule_ << endl
		<< "Prenom : " << prenom_ << endl
		<< "Nom : " << nom_ << endl;
}