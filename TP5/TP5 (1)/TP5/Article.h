#ifndef _ARTICLE_H_
#define _ARTICLE_H_

#include <string>

using namespace std;

class Article
{
public:
	Article(unsigned int id = 0, string nom = "", float prix = 0.0);

	unsigned int getId() const;
	string getNom() const;
	float getPrix() const;

	bool operator< (const Article article) const;
	

private:
	unsigned int id_;
	string nom_;
	float prix_;
};

// ========== CONSTRUCTEUR PAR PARAMETRES ==========

Article::Article(unsigned int id, string nom, float prix)
	:id_(id), nom_(nom), prix_(prix)
{
}


// ========== ACCESSEURS ==========

unsigned int Article::getId() const  { return id_; }

string Article::getNom() const { return nom_; }

float Article::getPrix() const { return prix_; }


// ========== SURCHARGE operator< ==========

bool Article::operator<(const Article article) const
{
	return (prix_ < article.getPrix());
}


// ========== SURCHARGE operator<< ==========

ostream& operator<<(ostream& out, const Article& article)
{
	out << article.getId() << " \t " << article.getNom() << " \t "
		<< article.getPrix() << "$" << endl;
	return out;
}

bool operator==(unsigned int id, const Article& art)
{
	return (art.getId() == id);
}


#endif