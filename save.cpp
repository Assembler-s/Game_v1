#include <iostream>
#include "save.h"
#include <cstdio>

using namespace std;

void saveParty(const PartyList& party, const char* filename)
{
	FILE* file = nullptr;

	fopen_s(&file, filename, "w");

	if (file == nullptr)
	{
		cout << "Не удалось сохранить!\n";
		return;
	}

	fprintf_s(file, "%d\n", party.size);
	for (int i = 0; i < party.size; i++)
	{
		fprintf_s(file, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%s\n%d\n", party.heroes[i].name, party.heroes[i].classType,
			party.heroes[i].level, party.heroes[i].hp, party.heroes[i].stats.strength,
			party.heroes[i].stats.agility, party.heroes[i].stats.intelligence,
			party.heroes[i].weapon.name, party.heroes[i].weapon.power);
	}
	fclose(file);
}

void loadParty(PartyList& party, const char* filename)
{
	FILE* file = nullptr;

	fopen_s(&file, filename, "r");

	if (file == nullptr)
	{
		cout << "Не удалось загрузить!\n";
		return;
	}

	fscanf_s(file, "%d", &party.size);
	party.heroes = new Character[party.size];

	for (int i = 0; i < party.size; i++)
	{
		fscanf_s(file, "%s", party.heroes[i].name, 100);
		fscanf_s(file, "%s", party.heroes[i].classType, 50);
		fscanf_s(file, "%d", &party.heroes[i].level);
		fscanf_s(file, "%d", &party.heroes[i].hp);
		fscanf_s(file, "%d", &party.heroes[i].stats.strength);
		fscanf_s(file, "%d", &party.heroes[i].stats.agility);
		fscanf_s(file, "%d", &party.heroes[i].stats.intelligence);
		fscanf_s(file, "%s", party.heroes[i].weapon.name, 50);
		fscanf_s(file, "%d", &party.heroes[i].weapon.power);
	}
	fclose(file);
}