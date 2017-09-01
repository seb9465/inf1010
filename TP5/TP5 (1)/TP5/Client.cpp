#include "Client.h"

// ========== CONSTRUCTEUR PAR DEFAUT ==========

Client::Client(unsigned int id, string nom, string prenom, float solde)
	:id_(id), nom_(nom), prenom_(prenom), solde_(solde)
{
}


// ========== ACCESSEURS ==========

unsigned int Client::getId() const { return id_; }

string Client::getNom() const { return nom_; }

string Client::getPrenom() const { return prenom_; }

float Client::getSolde() const { return solde_; }


// ========== SURCHARGE operator< ==========

bool Client::operator<(const Client& client) const
{
	return (id_ < client.getId());
}


// ========== METHODE achat ==========

void Client::achat(float montant) { solde_ -= montant; }


// ========== SURCHARGE operator<< ==========

ostream& operator<< (ostream& out, const Client& client)
{
	out << client.getId() << " : " << client.getPrenom() << " "
		<< client.getNom() << " a un solde de " << client.getSolde()
		<< "$." << endl;
	return out;
}