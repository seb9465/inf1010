#include "PirateInformatique.h"
using namespace std;

/****************************************************************************
* Fonction:		PirateInformatique::PirateInformatique
* Description:	Constructeur par paramètre
* Paramètres:	(AgentSecurite) unAgent
* Retour:		aucun
****************************************************************************/
PirateInformatique::PirateInformatique(AgentSecurite unAgent)
	:AgentSecurite(unAgent)
{

}

/****************************************************************************
* Fonction:		PirateInformatique::getNiveauAcces
* Description:	Méthode d'accès à l'attributs
* Paramètres:	aucun
* Retour:		(unsigned int) niveau accès d'un agent de securite
****************************************************************************/
unsigned int PirateInformatique::getNiveauAcces() const
{
	return AgentSecurite::getNiveauAcces() + Employe::getNiveauAcces();
}

/****************************************************************************
* Fonction:		Employe::getClasseEmploye
* Description:	Méthode d'accès de la classe
* Paramètres:	aucun
* Retour:		(string) nom de la classe
****************************************************************************/
string PirateInformatique::getClasseEmploye() const
{
	if (typeid(*this) == typeid(PirateInformatique))
		return"Pirate Informatique";
}