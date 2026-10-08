#pragma once

#include "types.h"

void recruitHero(PartyList&, Character);
int findHeroIndex(const PartyList&, const char*);
Character getHeroByName(const PartyList&, const char*);
void printParty(const PartyList&);
void printHero(const Character);