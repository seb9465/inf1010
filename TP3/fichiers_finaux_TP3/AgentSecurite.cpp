#include "AgentSecurite.h"

using namespace std;

/****************************************************************************
* Fonction:		AgentSecurite::AgentSecurite
* Description:	Constructeur par paramètres
* Paramètres:	(string) nom, (string) prenom
* Retour:		aucun
****************************************************************************/
AgentSecurite::AgentSecurite(string nom, string prenom)
	:Employe(nom, prenom)
{

}

/****************************************************************************
* Fonction:		AgentSecurite::getNiveauAcces
* Description:	Méthode d'accès à l'attributs
* Paramètres:	aucun
* Retour:		(unsigned int) valeur attributs accesAgentSecurite_ + accesEmploye_
****************************************************************************/
unsigned int AgentSecurite::getNiveauAcces() const
{
	return accesAgentSecurite_ + (Employe::getNiveauAcces());
}

/****************************************************************************
* Fonction:		AgentSecurite::getClasseEmploye
* Description:	Méthode d'accès de la classe
* Paramètres:	aucun
* Retour:		(string) nom de la classe
****************************************************************************/
string AgentSecurite::getClasseEmploye() const
{
	if (typeid(*this) == typeid(AgentSecurite))
		return "Agent de securite";
}


/****************************************************************************
* Fonction:		operator<<
* Description:	Définition de l'opérateur << pour un Agent de Sécurité
* Paramètres:	(ostream) os , (AgentSecurite) unAgent
* Retour:		(ostream) sortie
****************************************************************************/
ostream& operator<< (ostream& os, const AgentSecurite& unAgent)
{
	Employe employe = unAgent;
	os << employe;
	os << "Niveau d'acces : " << unAgent.getNiveauAcces() << endl;
	return os;
}


