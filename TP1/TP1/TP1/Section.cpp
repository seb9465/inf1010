#include "Section.h"

using namespace std;

//Constructeur par d�faut.
//Initialisation des attributs sigle, local et titre � la chaine de caract�res vide.
//Initialisation de l'attribut du nombre d'�tudiant � 0.
//Initialisation de l'attribut �tudiants � un tableau de 75 �tudiants.
Section::Section(){
	sigle_ = "";
	local_ = "";
	titre_ = "";
	professeur_ = new Professeur;
	nbEtudiants_ = 0;
}

//Constructeur par param�tres.
//Param�tres : sigle (string) , local (string) , titre (string) , professeur (pointeur).
//Initialisation des attributs selon les param�tres.
Section::Section(const string& sigle, const string& local, 
	const string& titre, Professeur* professeur){
	sigle_ = sigle;
	local_ = local;
	titre_ = titre;
	professeur_ = professeur;
	nbEtudiants_ = 0;
}

//Destructeur.
//Lib�re la m�moire pour le pointeur sur professeur et sur le tableau d'�tudiants.
Section::~Section(){
	delete professeur_;
	professeur_ = 0;
	for (unsigned int i = 0; i < nbEtudiants_; i++){
		delete etudiants_[i];
		etudiants_[i] = 0;
	}
}

//M�thode d'acc�s. *Sauf pour le tableau d'�tudiants*
string Section::getSigle() const {
	return sigle_;
}
string Section::getLocal() const {
	return local_;
}
string Section::getTitre() const {
	return titre_;
}
Professeur* Section::getProfesseur() const {
	return professeur_;
}
unsigned int Section::getNbEtudiants() const {
	return nbEtudiants_;
}

//M�thode de modification. *Sauf pour le tableau d'�tudiants & nombre d'�tudiants*
void Section::setSigle(string sigle){
	sigle_ = sigle;
}
void Section::setLocal(string local){
	local_ = local;
}
void Section::setTitre(string titre){
	titre_ = titre;
}
void Section::setProfesseur(Professeur* prof){
	professeur_ = prof;
}

//M�thode qui ajoute un �tudiant dans la section.
//Retourne bool indiquant si l'�tudiant a �t� ajout� ou non.
//Si l'�tudiant est d�j� dans la section ou si elle est dej�a remplie, �tudiant non ajout�.
bool Section::ajouterEtudiant(Etudiant* un){

	bool estPresent = false;
	for (unsigned int i(0); i < nbEtudiants_ && !estPresent; i++) //parcourir tableau pour trouver etudiant
		estPresent = un->getMatricule() == etudiants_[i]->getMatricule();

	if (!estPresent && nbEtudiants_ < NB_ETUDIANTS_MAX){
		etudiants_[nbEtudiants_] = un;
		nbEtudiants_++; //incr�mentation nombre �tudiants
		return true;
	}
	else
		return false;
}

//M�thode d'affichage des informations qui concernent une section.
void Section::afficher() const{
	cout << "Sigle : " << sigle_ << endl
		<< "Titre : " << titre_ << endl
		<< "Local : " << local_ << endl;
}
