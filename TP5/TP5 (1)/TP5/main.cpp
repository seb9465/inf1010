
#include <vector>
#include <iostream>
#include "Foncteur.h"
#include "PanierArticles.h"
#include "Commerce.h"
#include "Client.h"


using namespace std;


class FoncteurPrixZero
{
public:
	FoncteurPrixZero() :prixZero_((float)0.0){}
	bool operator() (const Article& article)
	{
		return (article.getPrix() == prixZero_);
	}

private:
	float prixZero_;
};

int main() {


	// 1) Créer une classe PanierArticle avec un id quelconque. =================================
	PanierArticles panierUn(34);
    
	// 2) Ajouter les articles suivants dans le panier ==========================================
	// Article 1 -> id = 1, nom = Livre, prix = 32.73$
	// Article 2 -> id = 2, nom = Film, prix = 34.97$
	// Article 3 -> id = 3, nom = Accessoire, prix = 12.12$
	// Article 4 -> id = 4, nom = Article bizarre, prix = 0.0$
	// Article 5 -> id = 5, nom = Mauvais article, prix = 0.0$
	Article livre = Article(1, "Livre", (float)32.73);
	panierUn.ajouter(livre);
	Article film = Article(2, "Film", (float)34.97);
	panierUn.ajouter(film);
	Article accessoire = Article(3, "Accessoire", (float)12.12);
	panierUn.ajouter(accessoire);
	Article articleBizarre = Article(4, "Article bizarre", (float)0.0);
	panierUn.ajouter(articleBizarre);
	Article mauvaisArticle = Article(5, "Mauvais article", (float)0.0);
	panierUn.ajouter(mauvaisArticle);

	// Afficher le panier avec l'opérateur <<
	cout << panierUn << endl;

	// 3) Afficher la moyenne des prix des articles du panier ===================================
	cout << "Somme des prix des articles du panier : "
		<< panierUn.sommeArticles() << " $" << endl;

	cout << "Moyenne des prix des articles du panier : "
		<< panierUn.obtenirMoyenne() << " $" << endl;
    
	// 4) Afficher l'id de l'article le moins cher et l'id de l'article le plus cher ============
	unsigned int IDmoinsCher = panierUn.obtenirPlusPetitElement().getId();

	cout << "ID de l'element le moins cher : " << IDmoinsCher << endl;

	unsigned int IDplusCher = panierUn.obtenirPlusGrandElement().getId();

	cout << "ID de l'element le plus cher : " << IDplusCher << endl;

    
	// 5) Supprimer l'article avec id = 2. ======================================================
	cout << "Supprimer l'article avec id = 2..." << endl << endl;

	unsigned int idASupprimer = 2;

	panierUn.supprimer(idASupprimer);
    
	// 6) Supprimer les articles qui ont un prix == 0. Créer un foncteur FoncteurPrixZero =======
	// et le passer en paramètre dans la méthode supprimer.
	//cout << "Supprimer les articles avec un prix = 0..." << endl << endl;
	
	
	//panierUn.supprimer(FoncteurPrixZero());
    
	// 7) Afficher de nouveau le panier =========================================================
	cout << "Afficher de nouveau le panier..." << endl << endl;

	cout << panierUn << endl;
    
	// 8) Appeller la fonction trier du panier et afficher la liste d'article obtenue avec ======
	// la fonction for_each.
	cout << "Trier le panier" << endl;
	cout << "=============================" << endl;
    
	list<Article> articlesTries = panierUn.trier();
	for_each(articlesTries.begin(), articlesTries.end(), Imprimer<Article>(cout));

	cout << "=============================" << endl << endl << endl;

    
	// 9) Créer un nouveau panier avec id = 2. ==================================================
	PanierArticles panierDeux(2);
    
	// 10) Ajouter les articles suivants dans ce panier:=========================================
	// Article 1 -> id = 1, nom = Livre, prix = 32.73$ (reprendre celui créer plus haut)
	// Article 6 -> id = 6, nom = Laptop, prix = 400.0$
	panierDeux.ajouter(livre);
	Article laptop = Article(6, "Laptop", (float)400.0);
	panierDeux.ajouter(laptop);

	// 11) Créer les clients suivants: ==========================================================
	// Client 1 -> id = 1, nom = Doe, prenom = John
	// Client 2 -> id = 2, nom = Tremblay, prenom = Martin
	Client John(1, "Doe", "John");
	Client Martin(2, "Tremblay", "Martin");
	

	cout << "*********** COMMERCE ***********" << endl;
	// 12) Créer un commerce et ajouter deux commandes ==========================================
	// Commande 1 -> John Doe avec panier 1
	// Commande 2 -> Martin Tremblay avec panier 2
	Commerce unCommerce;
	unCommerce.ajouterCommande(John, panierUn);
	unCommerce.ajouterCommande(Martin, panierDeux);

	// 13) Afficher les commandes par ordre alphabétique ========================================
	cout << "************* Affichage alphabetique ****************" << endl;
	unCommerce.afficherParOrdreAlphabetique();

	// 14) Afficher les commandes en ordre décroissant par le prix moyen des panier =============
	//cout << "************* Affichage prix moyen decroissant **************" << endl;


	// 15) Appliquer 10% de rabais sur le panier de Martin.  ====================================
	//cout << "*********** Affichage apres modifications ***********" << endl;


	// 16) Créer l'article suivant: =============================================================
	// Article 7 -> id = 7, nom = "Bureau", prix = 200
	Article bureau(7, "Bureau", 200.00);

	// 17) Ajouter l'article 7 au panier de John ================================================
	unCommerce.ajouterArticle(John, bureau);

	// 18) Supprimer l'article 3 de John ========================================================
	unCommerce.supprimerArticleCommande(John, accessoire);
	

	// 19) Afficher les commandes en ordre décroissant par le prix moyen des panier


	// 20) Supprimer la commande de Martin et afficher les commandes en ordre alphabétique
	//cout << "******** Affichage apres suppression commande ************" << endl;
	unCommerce.supprimerCommande(Martin);

	// 21) Libérer la mémoire (si nécessaire)

	return 0;
}