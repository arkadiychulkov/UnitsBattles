#include <iostream>
#include "swordsman.h"
#include "archer.h"
#include "mage.h"
#include"bow.h"
#include"stick.h"
#include"sword.h"
#include"team.h"
#include<fstream>


int main() {

    WeaponSpace::sword Sword1("Sword", 100);
    WeaponSpace::sword Sword(" ", 0);

    WeaponSpace::stick Posoh1("Stick", 30, 5);
    WeaponSpace::stick Posoh(" ", 0, 0);

    WeaponSpace::bow Bow1("Bow", 30, 5);
    WeaponSpace::bow Bow(" ", 0, 0);
    /*Posoh1.Serialize();
    Posoh.Deserialize();
    Sword1.Serialize();
    Sword.Deserialize();*/

    UnintSpace::swordsman Swordsman("Swordsman", Sword1, 200, 30);
    UnintSpace::swordsman Swordsman1(" ", Sword, 0, 0);
    UnintSpace::swordsman Swordsman2(" ", Sword, 0, 0);
    UnintSpace::swordsman Swordsman3(" ", Sword, 0, 0);

    std::string a = "input1.txt";
    std::string b = "input2.txt";
    std::string c = "input3.txt";

    Swordsman.Serialize(a);
    Swordsman1.Deserialize(a);
    Swordsman2.Deserialize(a);
    Swordsman3.Deserialize(a);

    UnintSpace::mage Mag("Mag1", Posoh1, 200, 50);
    UnintSpace::mage Mag1(" ", Posoh, 0, 0);
    UnintSpace::mage Mag2(" ", Posoh, 0, 0);
    UnintSpace::mage Mag3(" ", Posoh, 0, 0);

    Mag.Serialize(b);
    Mag1.Deserialize(b);
    Mag2.Deserialize(b);
    Mag3.Deserialize(b);

    UnintSpace::archer Archer("Archer", Posoh1, 200, 50);
    UnintSpace::archer Archer1(" ", Posoh, 0, 0);

    Archer.Serialize(c);
    Archer1.Deserialize(c);

    std::cout << Archer1;

    team team3;
    team3.SetName("first");
    team3.Append(&Swordsman1);
    team3.Append(&Swordsman2);
    team3.Append(&Swordsman3);
    //team3.show();


    team team2;
    team2.Append(&Mag1);
    team2.Append(&Mag2);
    team2.Append(&Mag3);
    team2.SetName("second");
    team2.show();

    team team1;
    team3.Serialize();
    team1.Deserialize();
    team1.show();
    a = 1;
    
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
