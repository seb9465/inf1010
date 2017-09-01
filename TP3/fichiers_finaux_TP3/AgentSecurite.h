#ifndef AGENT_SECURITE_H
#define AGENT_SECURITE_H

#include "Employe.h"
#include <iostream>

class AgentSecurite : public Employe
{
public:
	AgentSecurite(std::string nom, std::string prenom);
	virtual unsigned int getNiveauAcces() const;
	virtual std::string getClasseEmploye() const;

	friend  std::ostream& operator<< (std::ostream& os, const AgentSecurite& unAgentSecurite);
	
private: 
	const unsigned int accesAgentSecurite_ = 20;
};



#endif //AGENT_SECURITE_H