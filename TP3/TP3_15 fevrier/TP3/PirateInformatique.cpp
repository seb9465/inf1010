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
	return AgentSecurite::getNiveauAcces();
}