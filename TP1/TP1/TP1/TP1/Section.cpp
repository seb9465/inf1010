#include "Section.h"

using namespace std;

//Constructeur par défaut.
//Initialisation des attributs sigle, local et titre à la chaine de caractères vide.
//Initialisation de l'attribut du nombre d'étudiant à 0.
//Initialisation de l'attribut étudiants à un tableau de 75 étudiants.
Section::Section(){
	sigle_ = "";
	local_ = "";
	titre_ = "";
	professeur_ = new Professeur;
	nbEtudiants_ = 0;
}

//Constructeur par paramètres.
//Paramètres : sigle (string) , local (string) , titre (string) , professeur (pointeur).
//Initialisation des attributs selon les paramètres.
Section::Section(const string& sigle, const string& local, 
	const string& titre, Professeur* professeur){
	sigle_ = sigle;
	local_ = local;
	titre_ = titre;
	professeur_ = professeur;
	nbEtudiants_ = 0;
}

//Destructeur.
//Libère la mémoire pour le pointeur sur professeur et sur le tableau d'étudiants.
Section::~Section(){
	delete professeur_;
	professeur_ = 0;
	for (unsigned int i = 0; i < nbEtudiants_; i++){
		delete etudiants_[i];
		etudiants_[i] = 0;
	}
}

//Méthode d'accès. *Sauf pour le tableau d'étudiants*
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

//Méthode de modification. *Sauf pour le tableau d'étudiants & nombre d'étudiants*
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

//Méthode qui ajoute un étudiant dans la section.
//Retourne bool indiquant si l'étudiant a été ajouté ou non.
//Si l'étudiant est déjà dans la section ou si elle est dejàa remplie, étudiant non ajouté.
bool Section::ajouterEtudiant(Etudiant* un){

	bool estPresent = false;
	for (unsigned int i(0); i < nbEtudiants_ && !estPresent; i++) //parcourir tableau pour trouver etudiant
		estPresent = un->getMatricule() == etudiants_[i]->getMatricule();

	if (!estPresent && nbEtudiants_ < NB_ETUDIANTS_MAX){
		etudiants_[nbEtudiants_] = un;
		nbEtudiants_++; //incrémentation nombre étudiants
		return true;
	}
	else
		return false;
}

//Méthode d'affichage des informations qui concernent une section.
void Section::afficher() const{
	cout << "Sigle : " << sigle_ << endl
		<< "Titre : " << titre_ << endl
		<< "Local : " << local_ << endl;
}
