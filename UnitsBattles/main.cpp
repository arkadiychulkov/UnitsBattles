#include <iostream>
#include "swordsman.h"
#include "archer.h"
#include "mage.h"

int main() {
    swordsman Swordsman("Swordsman", "Sword", 150, 30, 30);
    archer Archer("Archer", "Bow", 100, 20, 60);
    mage Mag("Mag", "Stick", 80, 50, 100);

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
