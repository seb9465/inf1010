#include "Employe.h"
#include <string>

using namespace std;

/****************************************************************************
* Fonction:		Employe::Employe
* Description:	Constructeur par param�tres
* Param�tres:	(string) nom, (string) prenom
* Retour:		aucun
****************************************************************************/
Employe::Employe(string nom, string prenom)
	:nom_(nom), prenom_(prenom)
{
}

/****************************************************************************
* Fonction:		Employe::getNom
* Description:	M�thode d'acc�s � l'attributs
* Param�tres:	aucun
* Retour:		(string) valeur attribut nom_
****************************************************************************/
string Employe::getNom() const
{
	return nom_;
}

/****************************************************************************
* Fonction:		Employe::getPrenom
* Description:	M�thode d'acc�s � l'attributs
* Param�tres:	aucun
* Retour:		(string) valeur attribut prenom_
****************************************************************************/
string Employe::getPrenom() const
{
	return prenom_;
}

/****************************************************************************
* Fonction:		Employe::getNiveauAcces
* Description:	M�thode d'acc�s � l'attribut
* Param�tres:	aucun
* Retour:		(unsigned int) valeur attributs accesEmploye_
****************************************************************************/
unsigned int Employe::getNiveauAcces() const
{
	return accesEmploye_;
}

/****************************************************************************
* Fonction:		Employe::getClasseEmploye
* Description:	M�thode d'acc�s de la classe
* Param�tres:	aucun
* Retour:		(string) nom de la classe
****************************************************************************/
string Employe::getClasseEmploye() const
{
	if (typeid(*this) == typeid(Employe))
		return "Employe";
}

/****************************************************************************
* Fonction:		operator<<
* Description:	D�finition de l'op�rateur << pour un Employe
* Param�tres:	(ostream) os , (Employe) unEmploye
* Retour:		(ostream) sortie
****************************************************************************/
ostream& operator<< (ostream& os, const Employe& unEmploye)
{
	os << "Prenom : " << unEmploye.getPrenom() << endl
		<< "Nom : " << unEmploye.getNom() << endl
		<< "Nom de la classe : " << unEmploye.getClasseEmploye() << endl;
	return os;
}

