#include "Ecole.h"

using namespace std;

//Constructeur par d�faut.
//Initialisation des param�tres nom et adresse � la chaine de caract�res vide.
//Initialisation de l'attribut nombre de sections � 0.
Ecole::Ecole(){
	nom_ = "";
	adresse_ = "";
	nombreSections_ = 0;
}

//Constructeur par param�tres.
//Param�tres : nom (string) , adresse (string).
//Initialisation selon les param�tres.
//Initialisation de l'attribut nombre de sections � 0.
Ecole::Ecole(const string& nom, const string& adresse){
	nom_ = nom;
	adresse_ = adresse;
	nombreSections_ = 0;
}

//Destructeur.
//Lib�re la m�moire pour le tableau de sections.
Ecole::~Ecole(){
	for (unsigned int i = 0; i < nombreSections_; i++){
		delete sections_[i];
		sections_[i] = 0;
	}
		
	
}

//M�thodes d'acc�s des variables membres.  *sauf pour le tableau de pointeurs de sections*
string Ecole::getNom() const {
	return nom_;
}
string Ecole::getAdresse() const {
	return adresse_;
}
unsigned int Ecole::getNombreSection() const {
	return nombreSections_;
}

//M�thodes de modification des variables membres.  *sauf pour le tableau de pointeurs de sections*
void Ecole::setNom(const string& nom){
	nom_ = nom;
}
void Ecole::setAdresse(const string& adresse){
	adresse_ = adresse;
}

//M�thode qui ajoute une section dans l'�cole.
//Retourne un bool qui indique si la section a �t� ajout�e.
bool Ecole::ajouterSection(Section* section){
	bool estPresent = false;
	for (unsigned int i(0); i < nombreSections_ && !estPresent; i++) //parcourir tableau pour trouver etudiant
		estPresent = section->getSigle() == sections_[i]->getSigle();

	if (!estPresent && nombreSections_ < MAX_SECTIONS){
		sections_[nombreSections_] = new Section;
		sections_[nombreSections_] = section;
		nombreSections_++; //incr�mentation nombre �tudiants
		return true;
	}
	else
		return false;
}

//M�thode qui supprime une section dans l'�cole.
//Retourne un bool qui indique si la section a �t� supprim�e.
bool Ecole::supprimerSection(const string& sigle, const string& local){

	return true;
}





//M�thode d'affichage des informations qui concernent une �cole.
void Ecole::afficher() const {
	cout << "Nom de l'�cole : " << nom_ << endl
		<< "Adresse : " << adresse_ << endl
		<< "Nombre de sections : " << nombreSections_ << endl;
}

