#include <iostream>
#include "swordsman.h"
#include "archer.h"
#include "mage.h"
#include"bow.h"
#include"stick.h"
#include"sword.h"


int main() {
    WeaponSpace::sword Sword("Sword", 10);
    WeaponSpace::bow Bow("Bow", 20, 30);
    WeaponSpace::stick Posoh("Stick", 30, 5);

    UnintSpace::swordsman Swordsman("Swordsman", Sword, 200, 30);
    UnintSpace::archer Archer("Archer", Bow, 200, 20);
    UnintSpace::mage Mag("Mag", Posoh, 200, 50);

    std::cout << Swordsman << std::endl;
    std::cout << Archer << std::endl;
    std::cout << Mag << std::endl;

    std::cout << "\n--- Attak ---\n";
    Swordsman.Attak(Archer);
    Mag.Attak(Swordsman);
    Archer.Attak(Mag);
    std::cout << '\n';

    Swordsman.Defence();
    Archer.Defence();
    Mag.Defence();
    std::cout << '\n';

    Swordsman.Attak(Archer);
    Mag.Attak(Swordsman);
    Archer.Attak(Mag);
    std::cout << '\n';

    Swordsman.Defence();
    Archer.Defence();
    Mag.Defence();
    std::cout << '\n';

    Swordsman.Attak(Archer);
    Mag.Attak(Swordsman);
    Archer.Attak(Mag);

    std::cout << "\n--- After War ---\n";
    std::cout << Swordsman << std::endl;
    std::cout << Archer << std::endl;
    std::cout << Mag << std::endl;

    return 0;
}
