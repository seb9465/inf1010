#ifndef PIRATE_INFORMATIQUE_H
#define PIRATE_INFORMATIQUE_H

#include "AgentSecurite.h"

class PirateInformatique : AgentSecurite
{
public:
	PirateInformatique(AgentSecurite unAgent);

	virtual unsigned int getNiveauAcces() const;
};

#endif //PIRATE_INFORMATIQUE_H