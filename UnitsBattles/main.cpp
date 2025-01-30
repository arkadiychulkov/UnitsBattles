#include <iostream>
#include "swordsman.h"
#include "archer.h"
#include "mage.h"
#include"bow.h"
#include"stick.h"
#include"sword.h"
#include"team.h"


int main() {
    /*WeaponSpace::sword Sword("Sword", 5);
    WeaponSpace::bow Bow("Bow", 20, 30);
    WeaponSpace::stick Posoh("Stick", 30, 5);

    UnintSpace::swordsman Swordsman("Swordsman", Sword, 200, 30);
    UnintSpace::archer Archer("Archer", Bow, 200, 20);
    UnintSpace::mage Mag("Mag", Posoh, 200, 50);

    std::cout << Swordsman << std::endl;
    std::cout << Archer << std::endl;
    std::cout << Mag << std::endl;

    std::cout << "\n--- Attak ---\n";
    Swordsman.Attak(Mag);
    Mag.Attak(Archer);
    Archer.Attak(Swordsman);
    std::cout << '\n';

    Swordsman.Defence();
    Archer.Defence();
    Mag.Defence();
    std::cout << '\n';

    Swordsman.Attak(Mag);
    Mag.Attak(Archer);
    Archer.Attak(Swordsman);
    std::cout << '\n';

    Swordsman.Defence();
    Archer.Defence();
    Mag.Defence();
    std::cout << '\n';

    Swordsman.Attak(Mag);
    Mag.Attak(Archer);
    Archer.Attak(Swordsman);

    std::cout << "\n--- After War ---\n";
    std::cout << Swordsman << std::endl;
    std::cout << Archer << std::endl;
    std::cout << Mag << std::endl;*/

    WeaponSpace::sword Sword1("Sword", 100);
    WeaponSpace::sword Sword(" ", 0);
    WeaponSpace::stick Posoh1("Stick", 30, 5);
    WeaponSpace::stick Posoh(" ", 0, 0);
    Posoh1.Serialize();
    Posoh.Deserialize();
    Sword1.Serialize();
    Sword.Deserialize();


    UnintSpace::swordsman Swordsman1("Swordsman1", Sword,200, 30);
    UnintSpace::swordsman Swordsman2("Swordsman2", Sword, 200, 30);
    UnintSpace::swordsman Swordsman3("Swordsman3", Sword, 200, 30);
    UnintSpace::mage Mag1("Mag1", Posoh, 200, 50);
    UnintSpace::mage Mag2("Mag2", Posoh, 200, 50);
    UnintSpace::mage Mag3("Mag3", Posoh, 200, 50);


    team team1;
    team1.SetName("first");
    team1.Append(&Swordsman1);
    team1.Append(&Swordsman2);
    team1.Append(&Swordsman3);
    team1.show();


    team team2;
    team2.Append(&Mag1);
    team2.Append(&Mag2);
    team2.Append(&Mag3);
    team2.SetName("second");
    
    do
    {
        std::cout << "Team: " << team1.GetName() << "turn\n";
        team1.Attack(team2);
        std::cout << '\n';
        std::cout << '\n';
        team1.show();
        std::cout << '\n';
        if (team2.isDead())
        {
            std::cout << "Team: " << team1.GetName() << "win!\n";
            break;
        }
        std::cout << "Team: " << team2.GetName() << "Turn\n";
        team2.Attack(team1);
        std::cout << '\n';
        std::cout << '\n';
        team2.show();
        std::cout << '\n';
        if (team1.isDead())
        {
            std::cout << "Team: " << team2.GetName() << "win!\n";
            break;
        }
    } while (true);

    return 0;
}
