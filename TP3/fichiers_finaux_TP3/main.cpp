
#include "SystemeSecurite.h"
#include "PirateInformatique.h"

int main()
{
	//Creer le systeme de securite
	SystemeSecurite* systeme = new SystemeSecurite();

	/////////////////////////////////////////////////////////////
	//Ajouter les regles suivantes:
	//
	//	niveau d'acces	Local		Periode
	//
	//	1,				"L-3589",	PERIODE_ACCES_MATIN
	//	1,				"L-3587",	PERIODE_ACCES_MATIN
	//	1,				"L-3588",	PERIODE_ACCES_MATIN
	//
	//	5,				"L-3589",	PERIODE_ACCES_SOIR
	//	5,				"L-3587",	PERIODE_ACCES_SOIR
	//	5,				"L-3588",	PERIODE_ACCES_SOIR
	//
	//	20,				"L-3589",	PERIODE_ACCES_NUIT
	//	20,				"L-3587",	PERIODE_ACCES_NUIT
	//	25,				"L-3588",	PERIODE_ACCES_NUIT
	//
	//	10,				"L-4489",	PERIODE_ACCES_MATIN
	//	10,				"L-4487",	PERIODE_ACCES_MATIN
	//
	//	10,				"L-4489",	PERIODE_ACCES_SOIR
	//	10,				"L-4487",	PERIODE_ACCES_SOIR
	//
	//	20,				"L-4489",	PERIODE_ACCES_NUIT
	//	25,				"L-4487",	PERIODE_ACCES_NUIT
	//
	////////////////////////////////////////////////////////////
	systeme->ajouterRegle(RegleAcces(1 , "L-3589", PERIODE_ACCES_MATIN));
	systeme->ajouterRegle(RegleAcces(1 , "L-3587", PERIODE_ACCES_MATIN));
	systeme->ajouterRegle(RegleAcces(1 , "L-3588", PERIODE_ACCES_MATIN));
	systeme->ajouterRegle(RegleAcces(5 , "L-3589", PERIODE_ACCES_SOIR ));
	systeme->ajouterRegle(RegleAcces(5 , "L-3587", PERIODE_ACCES_SOIR ));
	systeme->ajouterRegle(RegleAcces(5 , "L-3588", PERIODE_ACCES_SOIR ));
	systeme->ajouterRegle(RegleAcces(20, "L-3589", PERIODE_ACCES_NUIT ));
	systeme->ajouterRegle(RegleAcces(20, "L-3587", PERIODE_ACCES_NUIT ));
	systeme->ajouterRegle(RegleAcces(25, "L-3588", PERIODE_ACCES_NUIT ));
	systeme->ajouterRegle(RegleAcces(10, "L-4489", PERIODE_ACCES_MATIN));
	systeme->ajouterRegle(RegleAcces(10, "L-4487", PERIODE_ACCES_MATIN));
	systeme->ajouterRegle(RegleAcces(10, "L-4489", PERIODE_ACCES_SOIR ));
	systeme->ajouterRegle(RegleAcces(10, "L-4487", PERIODE_ACCES_SOIR ));
	systeme->ajouterRegle(RegleAcces(20, "L-4489", PERIODE_ACCES_NUIT ));
	systeme->ajouterRegle(RegleAcces(25, "L-4487", PERIODE_ACCES_NUIT ));

	//Creer un agent de securite
	//
	//	nom: Nelson
	//  prenom: Garry
	//
	AgentSecurite agentGarry("Nelson", "Garry");

    // afficher les infos de l'agent de sécurité (operator <<)
	cout << agentGarry << endl << "----------------------------------------------------------" << endl;

	//Creer un professeur
	//
	//	nom: Rios
	//  prenom: Janet
	//
	Professeur profRios("Rios", "Janet");
	// afficher les infos du professeur (operator <<)
	cout << profRios << endl << "----------------------------------------------------------" << endl;

	//Creer un etudiant
	//
	//	nom: Ball
	//  prenom: Damon
	//
	Etudiant etudiantBall("Ball", "Damon");
	// afficher les infos de l'étudiant (operator <<)
	cout << etudiantBall << endl << "----------------------------------------------------------" << endl;

	//Cree un pirate Informatique qui prendra l'identite 
	//du gardien de securite
	PirateInformatique pirate(agentGarry);

	//L'agent de securite tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	//	"L-4489",	PERIODE_ACCES_SOIR
	//	"L-4487",	PERIODE_ACCES_NUIT
	//
	//
	systeme->accederLocal(agentGarry, "L-3587", PERIODE_ACCES_NUIT);
	systeme->accederLocal(agentGarry, "L-4489", PERIODE_ACCES_SOIR);
	systeme->accederLocal(agentGarry, "L-4487", PERIODE_ACCES_NUIT);

	//Le professeur tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_MATIN
	//	"L-4489",	PERIODE_ACCES_NUIT
	//	"L-4487",	PERIODE_ACCES_SOIR
	//
	//
	systeme->accederLocal(profRios, "L-3587", PERIODE_ACCES_MATIN);
	systeme->accederLocal(profRios, "L-4489", PERIODE_ACCES_NUIT);
	systeme->accederLocal(profRios, "L-4487", PERIODE_ACCES_SOIR);
	
	//L'etudiant tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3589",	PERIODE_ACCES_MATIN
	//	"L-4489",	PERIODE_ACCES_NUIT
	//	"L-3589",	PERIODE_ACCES_SOIR
	//
	//
	systeme->accederLocal(etudiantBall, "L-3589", PERIODE_ACCES_MATIN);
	systeme->accederLocal(etudiantBall, "L-4489", PERIODE_ACCES_NUIT );
	systeme->accederLocal(etudiantBall, "L-3589", PERIODE_ACCES_SOIR );

	//Le pirate informatique tente d'acceder aux locaux suivants a l'aide de la fonction suivante:
	//
	//	bool accederLocal(string nom, string prenom, string fonction, unsigned int niveauAcces, string local, string periode);
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	//	"L-4489",	PERIODE_ACCES_SOIR
	//	"L-4487",	PERIODE_ACCES_NUIT
	//
	//
	
	//<!---PROBLEME ICI---!>
	/*
	pirate.getClasseEmploye() retourne la chaine vide causant une erreur.
	Le programme fonctionne si on remplace par agentGarry.getClasseEmploye()
	Problème logique sachant que pirate n'est pas un agent de securité le typeID est donc différent et la fonction ne retourne rien.
	*/
	systeme->accederLocal(pirate.getNom(), pirate.getPrenom(), pirate.getClasseEmploye(), pirate.getNiveauAcces(), "L-3587", PERIODE_ACCES_NUIT);
	systeme->accederLocal(pirate.getNom(), pirate.getPrenom(), pirate.getClasseEmploye(), pirate.getNiveauAcces(), "L-4489", PERIODE_ACCES_SOIR);
	systeme->accederLocal(pirate.getNom(), pirate.getPrenom(), pirate.getClasseEmploye(), pirate.getNiveauAcces(), "L-4487", PERIODE_ACCES_NUIT);
	//<!---FIN PROBLEME---!>

		Employe* etudiant = new Etudiant("Etudiant", "Test");
	
		systeme->accederLocal	(	etudiant->getNom(), 
									etudiant->getPrenom(), 
									etudiant->getClasseEmploye(), 
									etudiant->getNiveauAcces(), 
									"L-3589", 
									PERIODE_ACCES_NUIT
								);
	
		delete etudiant;
		

	//Afficher le journal d'acces du systeme de securite
	systeme->imprimerJournal();

	//On supprime le pointeur ainsi que l'objet
	delete systeme;
	return 0;
}


//Reponse a la question:
//	
//	
//	Employe* etudiant = new Etudiant("Ball", "Damon");
//
//	sysSecu.accederLocal	(	etudiant->getNom(), 
//								etudiant->getPrenom(), 
//								etudiant->getFonction(), 
//								etudiant->getNiveauAcces(), 
//								"L-3589", 
//								PERIODE_ACCES_NUIT
//							);
//
//	delete etudiant;
//	
//	
//	
//	




