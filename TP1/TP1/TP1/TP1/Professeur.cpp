#include"Professeur.h"

//Constructeur par d�faut.
//Initialisation des attributs � une chaine de caract�res vide.
Professeur::Professeur(){
	numeroEmploye_ = "";
	prenom_ = "";
	nom_ = "";
	departement_ = "";
}

//Constructeur par param�tres.
//Initialisation des attributs selon les param�tres.
Professeur::Professeur(const string& numero, const string& prenom,
	const string& nom, const string& departement){
	numeroEmploye_ = numero;
	prenom_ = prenom;
	nom_ = nom;
	departement_ = departement;
}

//Destructeur.
Professeur::~Professeur(){
}

//M�thode d'acc�s des attributs.
string Professeur::getNumero() const {
	return numeroEmploye_;
}
string Professeur::getPrenom() const {
	return prenom_;
}
string Professeur::getNom() const {
	return nom_;
}
string Professeur::getDepartement() const {
	return departement_;
}

//M�thode de modifications des attributs.
void Professeur::setNumero(string numero){
	numeroEmploye_ = numero;
}
void Professeur::setPrenom(string prenom){
	prenom_ = prenom;
}
void Professeur::setNom(string nom){
	nom_ = nom;
}
void Professeur::setDepartement(string departement){
	departement_ = departement;
}

//M�thode d'affichage des informations qui concernent un professeur.
void Professeur::afficher() const {
	cout << "Numero : " << numeroEmploye_ << endl
		<< "Prenom : " << prenom_ << endl
		<< "Nom : " << nom_ << endl
		<< "Departement : " << departement_ << endl;
}


