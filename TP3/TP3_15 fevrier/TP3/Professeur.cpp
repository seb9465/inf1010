#include "Professeur.h"

using namespace std;

/****************************************************************************
* Fonction:		Professeur::Professeur
* Description:	Constructeur par paramètres
* Paramètres:	(string) nom, (string) prenom
* Retour:		aucun
****************************************************************************/
Professeur::Professeur(string nom, string prenom)
	:Employe(nom, prenom)
{

}

/****************************************************************************
* Fonction:		Professeur::getNiveauAcces
* Description:	Méthode d'accès à l'attributs
* Paramètres:	aucun
* Retour:		(unsigned int) valeur attributs accesProfesseur_ + accesEmploye_
****************************************************************************/
unsigned int Professeur::getNiveauAcces() const
{
	return accesProfesseur_ + Employe::getNiveauAcces();
}

/****************************************************************************
* Fonction:		Professeur::getClasseEmploye
* Description:	Méthode d'accès de la classe
* Paramètres:	aucun
* Retour:		(string) nom de la classe
****************************************************************************/
string Professeur::getClasseEmploye() const
{
	if (typeid(*this) == typeid(Professeur))
		return "Professeur";
}


ostream& operator<< (ostream& os, const Professeur& unProfesseur)
{
	
	return os;
}


