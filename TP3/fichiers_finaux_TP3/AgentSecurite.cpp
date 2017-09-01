#include "AgentSecurite.h"

using namespace std;

/****************************************************************************
* Fonction:		AgentSecurite::AgentSecurite
* Description:	Constructeur par param�tres
* Param�tres:	(string) nom, (string) prenom
* Retour:		aucun
****************************************************************************/
AgentSecurite::AgentSecurite(string nom, string prenom)
	:Employe(nom, prenom)
{

}

/****************************************************************************
* Fonction:		AgentSecurite::getNiveauAcces
* Description:	M�thode d'acc�s � l'attributs
* Param�tres:	aucun
* Retour:		(unsigned int) valeur attributs accesAgentSecurite_ + accesEmploye_
****************************************************************************/
unsigned int AgentSecurite::getNiveauAcces() const
{
	return accesAgentSecurite_ + (Employe::getNiveauAcces());
}

/****************************************************************************
* Fonction:		AgentSecurite::getClasseEmploye
* Description:	M�thode d'acc�s de la classe
* Param�tres:	aucun
* Retour:		(string) nom de la classe
****************************************************************************/
string AgentSecurite::getClasseEmploye() const
{
	if (typeid(*this) == typeid(AgentSecurite))
		return "Agent de securite";
}


/****************************************************************************
* Fonction:		operator<<
* Description:	D�finition de l'op�rateur << pour un Agent de S�curit�
* Param�tres:	(ostream) os , (AgentSecurite) unAgent
* Retour:		(ostream) sortie
****************************************************************************/
ostream& operator<< (ostream& os, const AgentSecurite& unAgent)
{
	Employe employe = unAgent;
	os << employe;
	os << "Niveau d'acces : " << unAgent.getNiveauAcces() << endl;
	return os;
}


