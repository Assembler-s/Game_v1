#include <iostream>
#include <windows.h>
#include "party.h"
#include "combat.h"
#include "save.h"

using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    PartyList party;
    Character recruit;

    recruit = {
        "Кадгар",
        "Маг",
        99,
        100,
        {0, 0, 100},
        {"Посох", 1001}
    };

    recruitHero(party, recruit);

    recruit = {
        "Гаррош",
        "Воин",
        101,
        120,
        {100, 0, 0},
        {"Топор", 1002}
    };

    recruitHero(party, recruit);

    recruit = {
        "Рексар",
        "Охотник",
        100,
        105,
        {0, 100, 0},
        {"Топор", 1003}
    };

    recruitHero(party, recruit);
    saveParty(party, "save.txt");


    // 1-2. Вывод лагеря

    printParty(party);


    // 3. Получение героя по имени

    printHero(getHeroByName(party, "Кадгар"));


    // 4. Повышение уровня

    levelUp(party, "Рексар");


    // 5. Новое оружие

    equipWeapon(
        party,
        "Рексар",
        { "Элитный лук", 1100 }
    );


    // 6. Бой

    damageHero(party, "Гаррош", 10);
    healHero(party, "Гаррош", 15);


    // 7. Общая сила лагеря

    cout << "Сила команды: "
        << totalPartyPower(party)
        << endl << endl;


    // 8. Индекс самого сильного героя

    cout << "Индекс сильнейшего: "
        << findStrongestHeroIndex(party)
        << endl << endl;


    // 9. Герой погибает

    dismissHero(party, "Кадгар");


    // 10. Вывод лагеря после изменений

    printParty(party);


    // Сортировка по уровню, если требуется продемонстрировать
    // функцию sortByLevelDescending

    sortByLevelDescending(party);

    cout << "После сортировки по уровню:\n\n";

    printParty(party);


    // 11. Освобождение памяти

    delete[] party.heroes;
    loadParty(party, "save.txt");
    printParty(party);
    delete[] party.heroes;

    return 0;
}