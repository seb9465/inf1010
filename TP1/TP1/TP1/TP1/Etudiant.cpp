
#include "Etudiant.h"

using namespace std;

//Constructeur par d�faut.
//Initialisation des attributs � des chaines de caract�res vides.
Etudiant::Etudiant(){
	matricule_ = "";
	prenom_ = "";
	nom_ = "";
}

//Constructeur par param�tres.
//Initialisation des attributs selon les param�tres.
Etudiant::Etudiant(const string& matricule, const string& prenom, const string& nom){
	matricule_ = matricule;
	prenom_ = prenom;
	nom_ = nom;
}

//Destructeur.
Etudiant::~Etudiant(){
}

//M�thodes d'acc�s.
string Etudiant::getMatricule() const {
	return matricule_;
}
string Etudiant::getPrenom() const {
	return prenom_;
}
string Etudiant::getNom() const {
	return nom_;
}

//M�thode de modification des attributs.
void Etudiant::setMatricule(string matricule){
	matricule_ = matricule;
}
void Etudiant::setPrenom(string prenom){
	prenom_ = prenom;
}
void Etudiant::setNom(string nom){
	nom_ = nom;
}

//M�thode d'affiche des informations qui concernent un �tudiant.
void Etudiant::afficher() const {
	cout << "Matricule : " << matricule_ << endl
		<< "Prenom : " << prenom_ << endl
		<< "Nom : " << nom_ << endl;
}