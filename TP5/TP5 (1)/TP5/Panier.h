#ifndef _PANIER_H_
#define _PANIER_H_

#include <list>
#include <algorithm>
#include <functional>
#include <iterator>

#include <iostream>

using namespace std;


template < typename T >
class Imprimer
{
public:
	Imprimer(ostream& out)
		:out_(out) {}
	void operator() (const T& obj)
	{
		out_ << obj << endl;
	}

private:
	ostream& out_;
};


template < typename T >
class Panier
{
public:
	Panier(unsigned int id) :id_(id) {}

	unsigned int getId() const { return id_; }
	list<T> getListe() const { return liste_; }

	void ajouter(T elem) { liste_.push_back(elem); }

	T obtenirPlusPetitElement() const { return (*min_element(liste_.begin(), liste_.end())); }
	T obtenirPlusGrandElement() const { return (*max_element(liste_.begin(), liste_.end())); }


	bool supprimer(unsigned int identifiant);

	void supprimer(bool predicat);


private:
	unsigned int id_;
	list<T> liste_;
	
};


template < typename T >
class ident
{
public:
	ident(unsigned int id) :id_(id) {}
	bool operator()(const T& obj)
	{
		return id_ == obj;
	}

private:
	unsigned int id_;
};
template < typename T >
bool Panier<T>::supprimer(unsigned int id)
{
	list<T>::iterator listIt = find_if(liste_.begin(), liste_.end(), ident<T>(id));
	
	if (listIt != liste_.end())
	{
		liste_.erase(listIt);
		return true;
	}
	return false;
}

template < typename T >
void Panier<T>::supprimer(bool predicat){
	liste_.remove_if(predicat);
}


template < typename T >
ostream& operator<< (ostream& out, const Panier<T>& panier)
{
	list<T> liste = panier.getListe();
	out << "ID du panier : " << panier.getId() << endl;
	
	for_each(liste.begin(), liste.end(), Imprimer<T>(out));

	return out;
}


#endif