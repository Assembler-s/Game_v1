#include <iostream>
#include <cstring>
#include "party.h"

using namespace std;

void recruitHero(PartyList& party, Character newHero)
{
	Character* arr_heroes = new Character[party.size + 1];

	for (int i = 0; i < party.size; i++)
	{
		arr_heroes[i] = party.heroes[i];
	}
	arr_heroes[party.size] = newHero;

	party.size++;

	delete[] party.heroes;
	party.heroes = arr_heroes;
}

int findHeroIndex(const PartyList& party, const char* searchName)
{
	for (int i = 0; i < party.size; i++)
	{
		if (strcmp(searchName, party.heroes[i].name) == 0)
			return i;
	}
	return -1;
}

Character getHeroByName(const PartyList& party, const char* searchName)
{
	int result = findHeroIndex(party, searchName);

	if (result > -1)
		return party.heroes[result];

	Character hero;
	hero.level = -1;
	return hero;
}

void printParty(const PartyList& party)
{
	for (int i = 0; i < party.size; i++)
	{
		cout << "name " << party.heroes[i].name << " class " << party.heroes[i].classType <<
			" level " << party.heroes[i].level << " hp " << party.heroes[i].hp <<
			"\nstrength " << party.heroes[i].stats.strength << " agility " << party.heroes[i].stats.agility <<
			" intelligence " << party.heroes[i].stats.intelligence << "\nweapon name " << party.heroes[i].weapon.name <<
			" weapon power " << party.heroes[i].weapon.power << endl << endl;
	}
}

void printHero(const Character hero)
{
	if (hero.level != -1)
	{
		cout << "name " << hero.name << " class " << hero.classType <<
			" level " << hero.level << " hp " << hero.hp <<
			"\nstrength " << hero.stats.strength << " agility " << hero.stats.agility <<
			" intelligence " << hero.stats.intelligence << "\nweapon name " << hero.weapon.name <<
			" weapon power " << hero.weapon.power << endl << endl;
	}
	else cout << "Нет такого героя!\n";
}