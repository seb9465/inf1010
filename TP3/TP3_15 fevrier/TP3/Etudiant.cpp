#include "Etudiant.h"

using namespace std;

/****************************************************************************
* Fonction:		Etudiant::Etudiant
* Description:	Constructeur par paramètres
* Paramètres:	(string) nom, (string) prenom
* Retour:		aucun
****************************************************************************/
Etudiant::Etudiant(string nom, string prenom)
	:Employe(nom, prenom)
{

}

/****************************************************************************
* Fonction:		Etudiant::getNiveauAcces
* Description:	Méthode d'accès à l'attributs
* Paramètres:	aucun
* Retour:		(unsigned int) valeur attribut accesEtudiant_
****************************************************************************/
unsigned int Etudiant::getNiveauAcces() const
{
	return accesEtudiant_;
}

/****************************************************************************
* Fonction:		Etudiant::getClasseEmploye
* Description:	Méthode d'accès de la classe
* Paramètres:	aucun
* Retour:		(string) nom de la classe
****************************************************************************/
string Etudiant::getClasseEmploye() const
{
	if (typeid(*this) == typeid(Etudiant))
		return "Etudiant";
}

