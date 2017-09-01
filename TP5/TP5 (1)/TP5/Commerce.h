#ifndef _COMMERCE_H_
#define _COMMERCE_H_

#include "Client.h"
#include "PanierArticles.h"
#include <map>

class Commerce
{
public:
	bool ajouterCommande(const Client &client, PanierArticles panier);
	bool ajouterArticle(const Client &client, Article article);
	bool supprimerCommande(const Client &client);
	bool supprimerArticleCommande(const Client &client, Article article);
	void appliquerRabais(const Client &client );
	void payerPanier(Client &client, const float &montant);
	void afficher(const Client& client);
	void afficher(string nomClient);
	void afficherParOrdreAlphabetique();
	void afficherPrixMoyenDecroissant();

private:
	map<Client, PanierArticles> mapClientPanier_;
};

void Compare(pair<Client, PanierArticles> & pair)
{
	pair.first.getId();
}
bool Commerce::ajouterCommande(const Client &client, PanierArticles panier){
	std::pair< std::map<Client, PanierArticles>::iterator, bool> ret;
	return this->mapClientPanier_.insert(std::pair<Client, PanierArticles>(client, panier)).second;
}

bool Commerce::ajouterArticle(const Client &client, Article article){
	std::map<Client, PanierArticles>::iterator it = this->mapClientPanier_.find(client);
	if (it != this->mapClientPanier_.end()){
		it->second.ajouter(article);
		return true;
	}
	return false;
}

bool Commerce::supprimerCommande(const Client &client)
{
	map<Client, PanierArticles>::iterator pos = mapClientPanier_.find(client);

	if (pos != mapClientPanier_.end()){
		mapClientPanier_.erase(pos);
		return true;
	}
	return false;
}

bool Commerce::supprimerArticleCommande(const Client &client, Article article)
{
	map<Client, PanierArticles>::iterator pos = mapClientPanier_.find(client);

	if (pos != mapClientPanier_.end())
	{
		return pos->second.supprimer(article.getId());
	}
	return false;
}


void Commerce::afficher(const Client& client)
{
	map<Client, PanierArticles>::iterator pos = mapClientPanier_.find(client);

	if (pos != mapClientPanier_.end())
		cout <<"Panier de " << client.getPrenom() << endl << pos->second << endl;
}

class CompareClientNom
{
public:
	CompareClientNom(string reference) :reference_(reference) {}

	bool operator()(const pair<Client, PanierArticles> & param)
	{
		return (reference_ == param.first.getPrenom());
	}
private:
	string reference_;
};
void Commerce::afficher(string nomClient)
{
	map<Client, PanierArticles>::iterator pos = find_if(mapClientPanier_.begin(), mapClientPanier_.end(), CompareClientNom(nomClient));
	
	if (pos != mapClientPanier_.end())
		cout << "Panier de " << pos->first.getPrenom() << endl << pos->second << endl;
}


void print(const pair<Client, PanierArticles>& paire)
{
	cout << "Panier de " << paire.first.getPrenom() << endl
		<< paire.second << endl;
}
void Commerce::afficherParOrdreAlphabetique()
{
	for_each(mapClientPanier_.begin(), mapClientPanier_.end(), print);
}


void Commerce::payerPanier(Client& client, const float& montant)
{
	client.achat(montant);
}
#endif