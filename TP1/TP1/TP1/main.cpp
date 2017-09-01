/********************************************************************
 Fichier: main.cpp
 Auteur: Konstantinos Lambrou-Latreille
 Description: 
	Fichier main qui contient l'ex�cution principale du TP1 de INF1010.
	Bien lire les commentaires et coder les instructions.
********************************************************************/

#include <iostream>
#include "Ecole.h"
#include "Section.h"

using namespace std;

int main()
{
	cout << endl;
	
	// 1) Cr�er automatiquement un objet Ecole avec son constructeur par d�faut
	//    et modifier ses attributs :
	string nom = "�cole Polytechnique de Montr�al";
	string adresse = "2900 Boulevard Edouard-Montpetit, Montr�al, Qu�bec H3T 1J4";
	Ecole Polytechnique = Ecole();
	Polytechnique.setAdresse(adresse);
	Polytechnique.setNom(nom);
	Polytechnique.afficher();

	// 2) Cr�er dynamiquement un objet Ecole avec son constructeur par param�tres
	//    et modifier ses attributs :
	string nomUqam = "Universit� de Qu�bec � Montr�al";
	string adresseUqam = "405 Rue Sainte-Catherine Est, Montr�al, Qu�bec H2L 2C4";
	Ecole uqam = Ecole(nom, adresse);
	uqam.setNom(nomUqam);
	uqam.setAdresse(adresseUqam);

	// 3) Cr�er automatiquement un objet Professeur avec son constructeur par d�faut.
	//    et modifier les arguments suivants:
	Professeur unProf = Professeur();
	string matriculeProfUn = "p12";
	string prenomProfUn = "Jean-Martin";
	string nomProfUn = "Aussant";
	string departementProfUn = "D�partement de science �conomique";

	unProf.setNumero(matriculeProfUn);
	unProf.setPrenom(prenomProfUn);
	unProf.setNom(nomProfUn);
	unProf.setDepartement(departementProfUn);

	// 4) Cr�er dynamiquement un objet Professeur avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	string matriculeProfDeux = "p13";
	string prenomProfDeux = "Chahira";
	string nomProfDeux = "Bechiri";
	string departementProfDeux = "D�partement de science informatique";
	Professeur profDeux = Professeur(matriculeProfDeux, prenomProfDeux,
		nomProfDeux, departementProfDeux);

	// 5) Cr�er dynamiquement un objet Professeur avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	string matriculeProfTrois = "p14";
	string prenomProfTrois = "Samuel";
	string nomProfTrois = "Kadoury";
	string departementProfTrois = "D�partement de g�nie informatique et logiciel";
	Professeur profTrois = Professeur(matriculeProfTrois, prenomProfTrois,
		nomProfTrois, departementProfTrois);

	// 6) Cr�er dynamiquement un objet Professeur avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	string matriculeProfQuatre = "p15";
	string prenomProfQuatre = "Michel";
	string nomProfQuatre = "Gagnon";
	string departementProfQuatre = "D�partement de g�nie informatique et logiciel";
	Professeur profQuatre = Professeur(matriculeProfQuatre, prenomProfQuatre,
		nomProfQuatre, departementProfQuatre);

	// 7) Cr�er automatiquement un objet Etudiant avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	string matriculeEtudiantUn = "1510301";
	string prenomEtudiantUn = "Konstantinos";
	string nomEtudiantUn = "Lambrou-Latreille";
	Etudiant etudiantUn = Etudiant(matriculeEtudiantUn, prenomEtudiantUn, nomEtudiantUn);


	// 8) Cr�er automatiquement un objet Etudiant avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	string matriculeEtudiantDeux = "1475812";
	string prenomEtudiantDeux = "Kahina";
	string nomEtudiantDeux = "Bechiri";


	// 9) Cr�er automatiquement un objet Etudiant avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		matricule="1506813"
	//		prenom="Mathieu"
	//		nom="Fafard"


	// 10) Cr�er automatiquement un objet Section avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		sigle="ISF1000"
	//		local="C215"
	//		titre="�conomie 101"
	//		prof=p12 - Jean-Martin Aussant


	// 11) Ajouter le deuxi�me �tudiant au cours ISF1000.


	// 12) Cr�er dynamiquement un objet Section avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		sigle="ISF2000"
	//		local="C214"
	//		titre="�tude en science cognitive"
	//		prof=p13 - Chahira Bechiri


	// 13) Ajouter le premier et le deuxi�me �tudiant au cours ISF2000.


	// 14) Cr�er automatiquement un objet Section avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		sigle="INF1010"
	//		local="L6614"
	//		titre="Programmation orient�e-objet"
	//		prof=p14 - Samuel Kadoury


	// 15) Ajouter le premier et le troisi�me �tudiant au cours INF1010.


	// 16) Cr�er dynamiquement un objet Section avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		sigle="LOG4420"
	//		local="M6410"
	//		titre="Conception de sites web dynamiques et transactionnels"
	//		prof=p15 - Michel Gagnon


	// 17) Ajouter le premier, le deuxi�me et le troisi�me �tudiant au cours LOG4420.


	// 18) Ajouter le cours INF1010 et le cours LOG4420 � l'�cole Polytechnique.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section INF1010 et LOG4420 � l'�cole Polytechnique" << endl;
	cout << "===============================================" << endl;


	// 19) Ajouter le cours ISF1000 � l'UQAM.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section ISF1000 � l'UQAM" << endl;
	cout << "===============================================" << endl;


	// 20) Modifier le local du cours ISF2000 vers le local A250.
	// 21) Ajouter le cours ISF2000 � l'UQAM.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section ISF2000 � l'UQAM" << endl;
	cout << "===============================================" << endl;


	// 22) Supprimer le cours ISF2000 de l'UQAM
	cout << endl << "===============================================" << endl;
	cout << "On supprime la section ISF2000 � l'UQAM" << endl;
	cout << "===============================================" << endl;


	// 23) Afficher les deux �coles cr��es.


	// 24) Lib�rer la m�moire


	cout << endl;
}