#include "RegleAcces.h"

using namespace std;

/****************************************************************************
* Fonction:		RegleAcces::RegleAcces
* Description:	Constructeur par defaut
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
RegleAcces::RegleAcces()
{
	niveauAccesRequis_ = 1;
	local_ = "";
	periode_ = "Matin";
}

/****************************************************************************
* Fonction:		RegleAcces::RegleAcces
* Description:	Constructeur par parametres
* Paramètres:	(unsigned int) niveau, (string) local, (string) periode)
* Retour:		aucun
****************************************************************************/
RegleAcces::RegleAcces(unsigned int niveau, const string& local,
	const string& periode)
	:local_(local), niveauAccesRequis_(niveau), periode_(periode)
{
}

/****************************************************************************
* Fonction:		RegleAcces::getLocal
* Description:	Methode d'acces a un attribut
* Paramètres:	aucun
* Retour:		(string) local_
****************************************************************************/
string RegleAcces::getLocal() const
{
	return local_;
}

/****************************************************************************
* Fonction:		RegleAcces::getNiveauAccesRequis
* Description:	Methode d'acces a un attribut
* Paramètres:	aucun
* Retour:		(unsigned int) niveauAccesRequis_
****************************************************************************/
unsigned int RegleAcces::getNiveauAccesRequis() const
{
	return niveauAccesRequis_;
}

/****************************************************************************
* Fonction:		RegleAcces::getPeriode
* Description:	Methode d'acces a un attribut
* Paramètres:	aucun
* Retour:		(string) periode_
****************************************************************************/
string RegleAcces::getPeriode() const
{
	return periode_;
}


bool RegleAcces::operator== (const RegleAcces& regle) const
{
	return (local_ == regle.getLocal() &&
		niveauAccesRequis_ == regle.getNiveauAccesRequis() &&
		periode_ == regle.getPeriode());
}