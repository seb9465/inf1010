#include "Panier.h"

using namespace std;

/****************************************************************************
* Fonction:		Panier::Panier
* Description:	Un constructeur par defaut
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Panier::Panier()
{
	total_ = 0;
}


/****************************************************************************
* Fonction:		Panier::Panier
* Description:	Un constructeur par paramètre qui prend un vecteur d’articles
				et initialise le prix total des articles en conséquence.
* Paramètres:	(vector<Article*>) articles
* Retour:		aucun
****************************************************************************/
Panier::Panier(vector<Article*> articles)
{
	float total = 0.0;
	for (unsigned int i = 0; i < articles.size(); i++)
	{
		listeArticles_.push_back(new Article(*articles[i]));
		total += articles[i]->getPrix();
	}
	total_ = total;
}


/****************************************************************************
* Fonction:		Panier::Panier
* Description:	Un constructeur par copie
* Paramètres:	(Panier) autrePanier
* Retour:		aucun
****************************************************************************/
Panier::Panier(const Panier& autrePanier)
	:total_(autrePanier.total_)
{
	for (unsigned int i = 0; i < autrePanier.getTaille(); i++)
		listeArticles_.push_back(new Article(*autrePanier.listeArticles_[i]));
}


/****************************************************************************
* Fonction:		Panier::~Panier
* Description:	Un dstructeur
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Panier::~Panier()
{
	for (unsigned int i = 0; i < listeArticles_.size(); i++)
		delete listeArticles_[i];
	listeArticles_.clear();
}


/****************************************************************************
* Fonction:		Panier::operator=
* Description:	L’opérateur = qui prend comme paramètre un autre panier.
				Cette opération écrase le contenu du panier.
* Paramètres:	(Panier) autrePanier
* Retour:		(Panier) le nouveau panier
****************************************************************************/
Panier& Panier::operator=(Panier autrePanier)
{
	if (this != &autrePanier){
		for (unsigned int i = 0; i < listeArticles_.size(); i++)
			delete listeArticles_[i];
		listeArticles_.clear();

		for (unsigned int i = 0; i < autrePanier.listeArticles_.size(); i++)
			listeArticles_.push_back(new Article(*autrePanier.listeArticles_[i]));
	}

	total_ = autrePanier.total_;

	return *this;
}


/****************************************************************************
* Fonction:		Panier::operator+
* Description:	L’opérateur + qui prend comme paramètre un article.
				Cette opération ajoute l’article au panier et fait la mise à jour du total.
* Paramètres:	(Article) article
* Retour:		(Panier) un panier
****************************************************************************/
Panier Panier::operator+(Article article)
{
	listeArticles_.push_back(new Article(article));
	total_ += article.getPrix();
	return Panier(listeArticles_);
}


/****************************************************************************
* Fonction:		Panier::operator+
* Description:	L’opérateur + qui prend comme paramètre un autre panier.
				Cette opération fusionne 2 paniers.
* Paramètres:	(Panier) un autre panier
* Retour:		(Panier) la fusion des deux paniers
****************************************************************************/
Panier Panier::operator+(Panier autrePanier)
{
	for (unsigned int i = 0; i < autrePanier.listeArticles_.size(); i++)
		listeArticles_.push_back(new Article(*autrePanier.listeArticles_[i]));
	total_ += autrePanier.getTotal();
	return Panier(listeArticles_);
}


/****************************************************************************
* Fonction:		Panier::operator-
* Description:	L’opérateur – qui prend comme paramètre un article.
				Cette opération retire l’article s’il est contenu dans le panier.
				Rien ne se passe sinon.
* Paramètres:	(Article) un article a supprimer
* Retour:		(Panier) le panier modifié
****************************************************************************/
Panier Panier::operator-(Article article)
{
	bool estPresent = false;
	for (unsigned int i = 0; i < listeArticles_.size() && !estPresent; i++)
	{
		estPresent = listeArticles_[i]->getId() == article.getId();
		if (estPresent)
		{
			unsigned int last = listeArticles_.size() - 1;
			total_ -= listeArticles_[i]->getPrix();		//retrait du prix de l'article au total_
			listeArticles_[i] = listeArticles_[last];	//retrait de l'article par le dernier de la liste
			listeArticles_.pop_back();					//retrait de la dernière position maintenant "vide"
		}
	}
	return *this;
}


/****************************************************************************
* Fonction:		Panier::operator-
* Description:	L’opérateur – qui prend comme paramètre un autre panier.
				Cette opération détermine les articles en commun.
* Paramètres:	(Panier) un autre panier
* Retour:		(Panier) panier contenant les articles commun
****************************************************************************/
Panier Panier::operator-(Panier autrePanier)
{
	Panier articleCommun;
	for (unsigned int i = 0; i < listeArticles_.size(); i++)
		for (unsigned int j = 0; j < autrePanier.getTaille(); j++)
			if (listeArticles_[i]->operator==(*autrePanier.listeArticles_[j]))
				articleCommun.operator+(*listeArticles_[i]);
	return articleCommun;
}


/****************************************************************************
* Fonction:		Panier::operator+=
* Description:	Les opérateurs += et -= qui correspondent aux opérateurs + et - décris plus haut.
* Paramètres:	(Article) un article
* Retour:		aucun
****************************************************************************/
void Panier::operator+=(Article article)
{
	listeArticles_.push_back(new Article(article));
	total_ += article.getPrix();
}


/****************************************************************************
* Fonction:		Panier::operator+=
* Description:	Les opérateurs += et -= qui correspondent aux opérateurs + et - décris plus haut.
* Paramètres:	(Panier) un autre panier
* Retour:		aucun
****************************************************************************/
void Panier::operator+=(Panier autrePanier)
{
	for (unsigned int i = 0; i < autrePanier.listeArticles_.size(); i++)
		listeArticles_.push_back(new Article(*autrePanier.listeArticles_[i]));
}


/****************************************************************************
* Fonction:		Panier::operator-=
* Description:	Les opérateurs += et -= qui correspondent aux opérateurs + et - décris plus haut.
* Paramètres:	(Article) un article
* Retour:		aucun
****************************************************************************/
void Panier::operator-=(Article article)
{
	bool estPresent = false;
	for (unsigned int i = 0; i < listeArticles_.size() && !estPresent; i++)
	{
		estPresent = listeArticles_[i]->getId() == article.getId();
		if (estPresent)
		{
			unsigned int last = listeArticles_.size() - 1;
			total_ -= listeArticles_[i]->getPrix();		//retrait du prix de l'article au total_
			listeArticles_[i] = listeArticles_[last];	//retrait de l'article par le dernier de la liste
			listeArticles_.pop_back();					//retrait de la dernière position maintenant "vide"
		}

	}
}


/****************************************************************************
* Fonction:		Panier::getTaille
* Description:	Une méthode s’appelant getTaille() qui retourne la taille du vecteur du panier.
* Paramètres:	aucun
* Retour:		(size_t) la taille
****************************************************************************/
size_t Panier::getTaille() const
{
	return listeArticles_.size();
}


/****************************************************************************
* Fonction:		Panier::getTotal
* Description:	Une méthode s’appelant getTotal() qui retourne le prix total du panier.
* Paramètres:	aucun
* Retour:		(float) le prix total
****************************************************************************/
float Panier::getTotal() const
{
	return total_;
}


/****************************************************************************
* Fonction:		operator<<
* Description:	L’opérateur << qui permet d’afficher le contenu du panier et sa somme total.
* Paramètres:	(ostream) une sortie
				(Panier) un article
* Retour:		(ostream) une sortie
****************************************************************************/
ostream& operator<< (ostream& os, const Panier& article)
{
	for (unsigned int i = 0; i < article.getTaille(); i++)
		os << *(article.listeArticles_[i]) << endl;

	os << "Total : " << article.getTotal() << "$" << endl
		<< "===========================================" << endl;
	return os;
}


/****************************************************************************
* Fonction:		operator<<
* Description:	Il doit être possible d’effectuer des opérations « article+panier » ou « entier+panier »
				qui retournent un panier (selon la même logique que les opérateurs + déjà décris).
				Cela doit être réalisé à l’aide de fonctions amies.
* Paramètres:	(Article) un article
				(Panier) un autre panier
* Retour:		(Panier) un panier
****************************************************************************/
Panier operator+ (const Article& article, const Panier& autrePanier)
{
	Panier panier = autrePanier;
	return panier + article;
}
