#include "PirateInformatique.h"
using namespace std;

/****************************************************************************
* Fonction:		PirateInformatique::PirateInformatique
* Description:	Constructeur par param�tre
* Param�tres:	(AgentSecurite) unAgent
* Retour:		aucun
****************************************************************************/
PirateInformatique::PirateInformatique(AgentSecurite unAgent)
	:AgentSecurite(unAgent)
{

}

/****************************************************************************
* Fonction:		PirateInformatique::getNiveauAcces
* Description:	M�thode d'acc�s � l'attributs
* Param�tres:	aucun
* Retour:		(unsigned int) niveau acc�s d'un agent de securite
****************************************************************************/
unsigned int PirateInformatique::getNiveauAcces() const
{
	return AgentSecurite::getNiveauAcces();
}