#pragma once

#include "types.h"

bool levelUp(PartyList&, const char*);
bool equipWeapon(PartyList&, const char*, Item);
bool damageHero(PartyList&, const char*, int);
bool healHero(PartyList&, const char*, int);
bool dismissHero(PartyList&, const char*);
int totalPartyPower(const PartyList&);
int findStrongestHeroIndex(const PartyList&);
void sortByLevelDescending(PartyList&);