#include"Professeur.h"

//Constructeur par défaut.
//Initialisation des attributs à une chaine de caractères vide.
Professeur::Professeur(){
	numeroEmploye_ = "";
	prenom_ = "";
	nom_ = "";
	departement_ = "";
}

//Constructeur par paramètres.
//Initialisation des attributs selon les paramètres.
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

//Méthode d'accès des attributs.
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

//Méthode de modifications des attributs.
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

//Méthode d'affichage des informations qui concernent un professeur.
void Professeur::afficher() const {
	cout << "Numero : " << numeroEmploye_ << endl
		<< "Prenom : " << prenom_ << endl
		<< "Nom : " << nom_ << endl
		<< "Departement : " << departement_ << endl;
}


