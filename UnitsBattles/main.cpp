#include <iostream>
#include "swordsman.h"
#include "archer.h"
#include "mage.h"
#include"bow.h"
#include"stick.h"
#include"sword.h"

int main() {
    sword Sword("Sword", 10);
    bow Bow("Bow", 20, 30);
    stick Posoh("Stick", 30, 5);

    swordsman Swordsman("Swordsman", Sword, 100, 30);
    archer Archer("Archer", Bow, 100, 20);
    mage Mag("Mag", Posoh, 100, 50);

    std::cout << Swordsman << std::endl;
    std::cout << Archer << std::endl;
    std::cout << Mag << std::endl;

    std::cout << "\n--- Attak ---\n";
    Swordsman.AttakArcher(Archer);
    Archer.Defence();
    Mag.AttakSwordsman(Swordsman);

    Swordsman.Defence();
    Archer.AttakMage(Mag);

    std::cout << "\n--- After War ---\n";
    std::cout << Swordsman << std::endl;
    std::cout << Archer << std::endl;
    std::cout << Mag << std::endl;

    return 0;
}
