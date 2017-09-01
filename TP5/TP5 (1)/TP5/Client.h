#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <string>

using namespace std;

class Client
{
public:
	Client(unsigned int id = 0, string nom = "",
		string prenom = "", float solde = 0.0);

	unsigned int getId() const;
	string getNom() const;
	string getPrenom() const;
	float getSolde() const;

	bool operator< (const Client& client) const;

	void achat(float prix);

private:
	unsigned int id_;
	string nom_;
	string prenom_;
	float solde_;
};

ostream& operator<< (ostream& out, const Client& client);

#endif