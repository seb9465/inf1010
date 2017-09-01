#include "Professeur.h"

using namespace std;

/****************************************************************************
* Fonction:		Professeur::Professeur
* Description:	Constructeur par param�tres
* Param�tres:	(string) nom, (string) prenom
* Retour:		aucun
****************************************************************************/
Professeur::Professeur(string nom, string prenom)
	:Employe(nom, prenom)
{

}

/****************************************************************************
* Fonction:		Professeur::getNiveauAcces
* Description:	M�thode d'acc�s � l'attributs
* Param�tres:	aucun
* Retour:		(unsigned int) valeur attributs accesProfesseur_ + accesEmploye_
****************************************************************************/
unsigned int Professeur::getNiveauAcces() const
{
	return accesProfesseur_ + Employe::getNiveauAcces();
}

/****************************************************************************
* Fonction:		Professeur::getClasseEmploye
* Description:	M�thode d'acc�s de la classe
* Param�tres:	aucun
* Retour:		(string) nom de la classe
****************************************************************************/
string Professeur::getClasseEmploye() const
{
	if (typeid(*this) == typeid(Professeur))
		return "Professeur";
}

/****************************************************************************
* Fonction:		operator<<
* Description:	D�finition de l'op�rateur << pour un professeur
* Param�tres:	(ostream) os , (Professeur) unProfesseur
* Retour:		(ostream) sortie
****************************************************************************/
ostream& operator<< (ostream& os, const Professeur& unProfesseur)
{
	Employe employe = unProfesseur;
	os << employe;
	os << "Niveau d'acces : " << unProfesseur.getNiveauAcces() << endl;
	return os;
}


