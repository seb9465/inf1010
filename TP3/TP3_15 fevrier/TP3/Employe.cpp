#include "Employe.h"
#include <string>

using namespace std;

/****************************************************************************
* Fonction:		Employe::Employe
* Description:	Constructeur par paramètres
* Paramètres:	(string) nom, (string) prenom
* Retour:		aucun
****************************************************************************/
Employe::Employe(string nom, string prenom)
	:nom_(nom), prenom_(prenom)
{
}

/****************************************************************************
* Fonction:		Employe::getNom
* Description:	Méthode d'accès à l'attributs
* Paramètres:	aucun
* Retour:		(string) valeur attribut nom_
****************************************************************************/
string Employe::getNom() const
{
	return nom_;
}

/****************************************************************************
* Fonction:		Employe::getPrenom
* Description:	Méthode d'accès à l'attributs
* Paramètres:	aucun
* Retour:		(string) valeur attribut prenom_
****************************************************************************/
string Employe::getPrenom() const
{
	return prenom_;
}

/****************************************************************************
* Fonction:		Employe::getNiveauAcces
* Description:	Méthode d'accès à l'attribut
* Paramètres:	aucun
* Retour:		(unsigned int) valeur attributs accesEmploye_
****************************************************************************/
unsigned int Employe::getNiveauAcces() const
{
	return accesEmploye_;
}

/****************************************************************************
* Fonction:		Employe::getClasseEmploye
* Description:	Méthode d'accès de la classe
* Paramètres:	aucun
* Retour:		(string) nom de la classe
****************************************************************************/
string Employe::getClasseEmploye() const
{
	if (typeid(*this) == typeid(Employe))
		return "Employe";
}

/****************************************************************************
* Fonction:		operator<<
* Description:	Définition de l'opérateur << pour un Employe
* Paramètres:	(ostream) os , (Employe) unEmploye
* Retour:		(ostream) sortie
****************************************************************************/
ostream& operator<< (ostream& os, const Employe& unEmploye)
{
	os << "Prenom : " << unEmploye.getPrenom() << endl
		<< "Nom : " << unEmploye.getNom() << endl
		<< "Nom de la classe : " << unEmploye.getClasseEmploye() << endl;
	return os;
}

