#include "Ecole.h"

using namespace std;

//Constructeur par défaut.
//Initialisation des paramètres nom et adresse à la chaine de caractères vide.
//Initialisation de l'attribut nombre de sections à 0.
Ecole::Ecole(){
	nom_ = "";
	adresse_ = "";
	nombreSections_ = 0;
}

//Constructeur par paramètres.
//Paramètres : nom (string) , adresse (string).
//Initialisation selon les paramètres.
//Initialisation de l'attribut nombre de sections à 0.
Ecole::Ecole(const string& nom, const string& adresse){
	nom_ = nom;
	adresse_ = adresse;
	nombreSections_ = 0;
}

//Destructeur.
//Libère la mémoire pour le tableau de sections.
Ecole::~Ecole(){
	for (unsigned int i = 0; i < nombreSections_; i++){
		delete sections_[i];
		sections_[i] = 0;
	}
		
	
}

//Méthodes d'accès des variables membres.  *sauf pour le tableau de pointeurs de sections*
string Ecole::getNom() const {
	return nom_;
}
string Ecole::getAdresse() const {
	return adresse_;
}
unsigned int Ecole::getNombreSection() const {
	return nombreSections_;
}

//Méthodes de modification des variables membres.  *sauf pour le tableau de pointeurs de sections*
void Ecole::setNom(const string& nom){
	nom_ = nom;
}
void Ecole::setAdresse(const string& adresse){
	adresse_ = adresse;
}

//Méthode qui ajoute une section dans l'école.
//Retourne un bool qui indique si la section a été ajoutée.
bool Ecole::ajouterSection(Section* section){
	bool estPresent = false;
	for (unsigned int i(0); i < nombreSections_ && !estPresent; i++) //parcourir tableau pour trouver etudiant
		estPresent = section->getSigle() == sections_[i]->getSigle();

	if (!estPresent && nombreSections_ < MAX_SECTIONS){
		sections_[nombreSections_] = new Section;
		sections_[nombreSections_] = section;
		nombreSections_++; //incrémentation nombre étudiants
		return true;
	}
	else
		return false;
}

//Méthode qui supprime une section dans l'école.
//Retourne un bool qui indique si la section a été supprimée.
bool Ecole::supprimerSection(const string& sigle, const string& local){

	return true;
}





//Méthode d'affichage des informations qui concernent une école.
void Ecole::afficher() const {
	cout << "Nom de l'école : " << nom_ << endl
		<< "Adresse : " << adresse_ << endl
		<< "Nombre de sections : " << nombreSections_ << endl;
}

