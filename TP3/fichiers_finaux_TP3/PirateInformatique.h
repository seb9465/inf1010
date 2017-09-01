#ifndef PIRATE_INFORMATIQUE_H
#define PIRATE_INFORMATIQUE_H

#include "AgentSecurite.h"

class PirateInformatique : public AgentSecurite
{
public:
	PirateInformatique(AgentSecurite unAgent);

	virtual unsigned int getNiveauAcces() const;

	virtual std::string getClasseEmploye() const;
};

#endif //PIRATE_INFORMATIQUE_H