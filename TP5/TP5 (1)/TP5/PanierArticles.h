#ifndef _PANIER_ARTICLES_H_
#define _PANIER_ARTICLES_H_

#include "Panier.h"
#include "Article.h"

class PanierArticles :public Panier < Article >
{
public:
	PanierArticles(unsigned int id = 0);

	float sommeArticles() const;
	float obtenirMoyenne() const;

	list<Article> trier() const;
};



// ========== CONSTRUCTEUR PAR PARAMETRES ==========

PanierArticles::PanierArticles(unsigned int id)
	:Panier(id)
{
}


// ========== METHODE sommeArticles ==========
float somme;
void sommer(Article article){
	::somme += article.getPrix();
}
float PanierArticles::sommeArticles() const
{
	::somme = 0.0;
	list<Article> liste = Panier::getListe();

	if (!liste.empty()){

		for_each(liste.begin(), liste.end(), sommer);

		/*for (itListe; itListe != liste.end(); itListe++)
		somme += itListe->getPrix();
		}*/

		return somme;
	}
	return somme;
}


// ========== METHODE obtenirMoyenne ==========

float PanierArticles::obtenirMoyenne() const
{
	return (sommeArticles() / (float)Panier::getListe().size());
}



// ========== METHODE trier ==========

bool plusGrandQue(Article art1, Article art2)
{
	return (art1.getPrix() > art2.getPrix());
}

list<Article> PanierArticles::trier() const
{
	list<Article> liste = Panier::getListe();
	list<Article> nouvelleListe(liste.begin(), liste.end());

	nouvelleListe.sort(plusGrandQue);

	return nouvelleListe;
}

// ========== SURCHARGE operator<< ==========

ostream& operator<< (ostream& out, const PanierArticles& panier)
{
	list<Article> liste = panier.getListe();
	out << "ID du panier : " << panier.getId() << endl;

	for_each(liste.begin(), liste.end(), Imprimer<Article>(out));

	return out;
}

#endif

