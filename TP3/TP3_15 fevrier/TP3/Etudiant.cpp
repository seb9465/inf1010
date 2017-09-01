#include "Etudiant.h"

using namespace std;

/****************************************************************************
* Fonction:		Etudiant::Etudiant
* Description:	Constructeur par param�tres
* Param�tres:	(string) nom, (string) prenom
* Retour:		aucun
****************************************************************************/
Etudiant::Etudiant(string nom, string prenom)
	:Employe(nom, prenom)
{

}

/****************************************************************************
* Fonction:		Etudiant::getNiveauAcces
* Description:	M�thode d'acc�s � l'attributs
* Param�tres:	aucun
* Retour:		(unsigned int) valeur attribut accesEtudiant_
****************************************************************************/
unsigned int Etudiant::getNiveauAcces() const
{
	return accesEtudiant_;
}

/****************************************************************************
* Fonction:		Etudiant::getClasseEmploye
* Description:	M�thode d'acc�s de la classe
* Param�tres:	aucun
* Retour:		(string) nom de la classe
****************************************************************************/
string Etudiant::getClasseEmploye() const
{
	if (typeid(*this) == typeid(Etudiant))
		return "Etudiant";
}

