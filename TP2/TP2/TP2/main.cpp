#include <iostream>
#include <vector>
#include "Panier.h"

using namespace std;

int main()
{
	// 1. Créer un panier vide panierUn
	Panier panierUn;

	// 2. Créer quelques articles (au moins trois) avec  les constructeurs et 
	// l'opérateur >>
	Article articleUn;
	Article articleDeux;
	Article articleTrois;
	cout << "Veuillez entrer les informations de l'article : " << endl;
	cin >> articleUn;
	cout << "Veuillez entrer les informations de l'article : " << endl;
	cin >> articleDeux;
	cout << "Veuillez entrer les informations de l'article : " << endl;
	cin >> articleTrois;

	// 3. Ajouter les articles au panier
	panierUn + articleUn;
	panierUn + articleDeux;
	panierUn + articleTrois;

	// 4. Afficher le panier
	cout << "Panier 1 -> Addition des trois premiers articles" << endl << panierUn << endl;

	// 5. Créer d'autres articles (au moins deux) et les placer dans un vecteur
	Article articleQuatre;
	Article articleCinq;

	cout << "Veuillez entrer les informations de l'article : " << endl;
	cin >> articleQuatre;
	cout << "Veuillez entrer les informations de l'article : " << endl;
	cin >> articleCinq;

	vector<Article*> vecteurArticleUn;
	vecteurArticleUn.push_back(new Article(articleQuatre));
	vecteurArticleUn.push_back(new Article(articleCinq));

	// 6. Créer un panierDeux qui contient initialement les articles du vecteur créé en 5
	Panier panierDeux(vecteurArticleUn);

	// 7. Créer un panierTrois qui contient l'ensemble des articles du panierUn et du panierDeux (+)
	Panier panierTrois;
	panierTrois = panierUn + panierDeux;

	// 8. Retirer un article créé en 2 du panierTrois avec l'operateur -=
	panierTrois -= articleUn;

	// 9. Afficher le panierTrois
	cout << "Panier 3 -> Panier1 + Panier2.  -= article1" << endl << panierTrois << endl;

	// 10. Créer un panierQuatre vide puis lui assigner le second panier
	Panier panierQuatre;
	panierQuatre = panierDeux;

	// 11. Ajouter au panierQuatre un article en utilisant uniquement un id (non utilisé précédement)
	panierQuatre += Article(12);

	// 12. Afficher le panierQuatre
	cout << "Panier 4 -> = Panier2.  += Article(12)" << endl << panierQuatre << endl;

	// 13. Créer un panierCinq vide
	Panier panierCinq;

	// 14. Effectuer l'opération "panierCinq = article + panierQuatre" puis afficher le panier 5
	Article article;
	cout << "Veuillez entrer les informations de l'article : " << endl;
	cin >> article;
	panierCinq = article + panierQuatre;
	cout << "Panier 5 -> Article + Panier4" << endl << panierCinq << endl;

	// 15. Créer un panierSix vide et ajouter au moins  4 articles.
	Panier panierSix;
	Article articleSix(687, "Feve au lard", 7);
	Article articleSept(74, "Olive Noir", 7);
	Article articleHuit(889, "Spaghetti Catelli", 8);
	Article articleNeuf(943, "Rigattoni", 9);
	panierSix + articleSix;
	panierSix + articleCinq;
	panierSix + articleHuit;
	panierSix + articleNeuf;
	cout << "Panier 6 -> 4 nouveaux articles" << endl << panierSix << endl;

	// 16. créer un panierSept vide
	Panier panierSept;

	//  17. Effectuer l'opération panierSept = panierSix  - panierCinq 
	panierSept = panierSix - panierCinq;

	//  18. Afficher le panierSept
	cout << "Panier 7 -> Panier6 - Panier5" << endl << panierSept << endl;

	return 0;
}
