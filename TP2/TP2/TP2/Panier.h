#ifndef PANIER_H
#define PANIER_H

#include <iostream>
#include <vector>
#include "Article.h"
using namespace std;
class Panier
{
public:
	Panier();
	Panier(vector<Article*> articles);
	Panier(const Panier& autrePanier);
	~Panier();

	Panier& operator= (Panier panier);

	Panier operator+ (Article article);
	Panier operator+ (Panier autrePanier);
	Panier operator- (Article article);
	Panier operator- (Panier autrePanier);

	void operator+= (Article article);
	void operator+= (Panier autrePanier);
	void operator-= (Article article);

	size_t getTaille() const ;
	float getTotal() const ;

	friend ostream& operator<< (ostream& os, const Panier& article);
	friend Panier operator+ ( const Article& article, const Panier& autrePanier);

private:
	vector<Article*> listeArticles_;
	float total_;
};
#endif