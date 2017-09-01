#include "SystemeSecurite.h"

using namespace std;

/****************************************************************************
* Fonction:		SystemeSecurite::SystemeSecurite
* Description:	Constructeur par d�faut
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
SystemeSecurite::SystemeSecurite()
{

}

/****************************************************************************
* Fonction:		SystemeSecurite::accederLocal
* Description:	Acces au local + entr�e dans le journal
* Param�tres:	(string) nom, (string) prenom, (string) fonction, (unsigned int) niveauAcces, (string) local, (string) periode
* Retour:		(bool) acces
****************************************************************************/
bool SystemeSecurite::accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode){
	bool acces = false;
	stringstream entreeJournal;

	for (unsigned int i = 0; i < this->regles_.size(); i++){
		if (this->regles_[i].getLocal() == local)
			if (this->regles_[i].getPeriode() == periode)
				if (this->regles_[i].getNiveauAccesRequis() <= niveauAcces)
					acces = true;
	}

	entreeJournal << "Nom, Prenom: " << nom << ", " << prenom << endl << "Classe d'employe: " << fonction << endl << "Niveau d'acces: " << niveauAcces << endl << "Local: " << local << endl << "Perdiode: " << periode << endl << "Acces: " << (acces == true ? "Accorde" : "Refuse") << endl;

	this->journalAcces_.push_back(entreeJournal.str());

	return acces;
}

/****************************************************************************
* Fonction:		SystemeSecurite::accederLocal
* Description:	Surchage pour un agent
* Param�tres:	(AgentSecurite) agent, (string) local, (string) periode
* Retour:		(bool) acces
****************************************************************************/
bool SystemeSecurite::accederLocal(const AgentSecurite& agent, const string& local, const string& periode){
	return this->accederLocal(agent.getNom(), agent.getPrenom(), agent.getClasseEmploye(), agent.getNiveauAcces(), local, periode);
}

/****************************************************************************
* Fonction:		SystemeSecurite::accederLocal
* Description:	Surchage pour un professeur
* Param�tres:	(Professeur) professeur, (string) local, (string) periode
* Retour:		(bool) acces
****************************************************************************/
bool SystemeSecurite::accederLocal(const Professeur& professeur, const string& local, const string& periode){
	return this->accederLocal(professeur.getNom(), professeur.getPrenom(), professeur.getClasseEmploye(), professeur.getNiveauAcces(), local, periode);
}

/****************************************************************************
* Fonction:		SystemeSecurite::accederLocal
* Description:	Surchage pour un etudiant
* Param�tres:	(Etudiant) etudiant, (string) local, (string) periode
* Retour:		(bool) acces
****************************************************************************/
bool SystemeSecurite::accederLocal(const Etudiant& etudiant, const string& local, const string& periode){
	return this->accederLocal(etudiant.getNom(), etudiant.getPrenom(), etudiant.getClasseEmploye(), etudiant.getNiveauAcces(), local, periode);
}

/****************************************************************************
* Fonction:		SystemeSecurite::ajouterRegle
* Description:	Ajoute une r�gle si elle n'existe pas d�j�
* Param�tres:	(RegleAcces) regle
* Retour:		(bool) ajout
****************************************************************************/
bool SystemeSecurite::ajouterRegle(const RegleAcces& regle){
	for (unsigned int i = 0; i < this->regles_.size(); i++){
		if (this->regles_[i] == regle)
			return false;
	}
	this->regles_.push_back(regle);
	return true;
}

/****************************************************************************
* Fonction:		SystemeSecurite::imprimerJournal	
* Description:	Affiche le journal
* Param�tres:	aucun
* Retour:		aucun
****************************************************************************/
void SystemeSecurite::imprimerJournal() const{
	for (unsigned int i = 0; i < this->journalAcces_.size(); i++)
		cout << this->journalAcces_[i] << endl << "----------------------------------------------------------" << endl;
}