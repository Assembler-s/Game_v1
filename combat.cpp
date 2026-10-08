#include "combat.h"
#include "party.h"
#include <cstring>

bool levelUp(PartyList& party, const char* searchName)
{
    int index_hero = findHeroIndex(party, searchName);

    if (index_hero > -1)
    {
        party.heroes[index_hero].level++;
        party.heroes[index_hero].hp += 10;

        return true;
    }

    return false;
}

bool equipWeapon(PartyList& party, const char* searchName, Item newWeapon)
{
    int index_hero = findHeroIndex(party, searchName);

    if (index_hero > -1)
    {
        strcpy_s(
            party.heroes[index_hero].weapon.name,
            50,
            newWeapon.name
        );

        party.heroes[index_hero].weapon.power = newWeapon.power;

        return true;
    }

    return false;
}

bool damageHero(PartyList& party, const char* searchName, int amount)
{
    if (amount < 0)
        return false;

    int index_hero = findHeroIndex(party, searchName);

    if (index_hero != -1)
    {
        if (amount > party.heroes[index_hero].hp)
        {
            party.heroes[index_hero].hp = 0;
            return true;
        }

        party.heroes[index_hero].hp -= amount;

        return true;
    }

    return false;
}

bool healHero(PartyList& party, const char* searchName, int amount)
{
    if (amount < 0)
        return false;

    int index_hero = findHeroIndex(party, searchName);

    if (index_hero != -1)
    {
        if (amount + party.heroes[index_hero].hp > 100)
        {
            party.heroes[index_hero].hp = 100;
            return true;
        }

        party.heroes[index_hero].hp += amount;

        return true;
    }

    return false;
}

bool dismissHero(PartyList& party, const char* searchName)
{
    int index_hero = findHeroIndex(party, searchName);

    if (index_hero < 0)
        return false;

    if (party.size == 1)
    {
        delete[] party.heroes;

        party.heroes = nullptr;
        party.size = 0;

        return true;
    }

    Character* new_arr = new Character[party.size - 1];

    int index = 0;

    for (int i = 0; i < party.size; i++)
    {
        if (strcmp(party.heroes[i].name, searchName) == 0)
            continue;

        new_arr[index] = party.heroes[i];
        index++;
    }

    party.size--;

    delete[] party.heroes;
    party.heroes = new_arr;

    return true;
}

int totalPartyPower(const PartyList& party)
{
    int total_power = 0;

    for (int i = 0; i < party.size; i++)
    {
        total_power +=
            party.heroes[i].level * 10
            + party.heroes[i].weapon.power;
    }

    return total_power;
}

int findStrongestHeroIndex(const PartyList& party)
{
    if (party.size == 0)
        return -1;

    int result =
        party.heroes[0].stats.agility
        + party.heroes[0].stats.strength
        + party.heroes[0].stats.intelligence;

    int index = 0;

    for (int i = 1; i < party.size; i++)
    {
        if (result <
            party.heroes[i].stats.agility
            + party.heroes[i].stats.strength
            + party.heroes[i].stats.intelligence)
        {
            result =
                party.heroes[i].stats.agility
                + party.heroes[i].stats.strength
                + party.heroes[i].stats.intelligence;

            index = i;
        }
    }

    return index;
}

void sortByLevelDescending(PartyList& party)
{
    int border = party.size - 1;
    int swap = 0;

    for (int i = 0; i < party.size; i++)
    {
        for (int j = 0; j < border; j++)
        {
            if (party.heroes[j].level < party.heroes[j + 1].level)
            {
                Character temp = party.heroes[j];

                party.heroes[j] = party.heroes[j + 1];
                party.heroes[j + 1] = temp;

                swap = j + 1;
            }
        }

        if (swap == 0 || swap == 1)
            break;

        border = swap - 1;
        swap = 0;
    }
}