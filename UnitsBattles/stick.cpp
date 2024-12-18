#include "weapon.h"
#include "stick.h"

stick::stick(std::string name, unsigned int damage, int chargs) : weapon(name, damage), charges(chargs) {}

Grade stick::GetDamage() {
    return this->GetGrade();
}

void stick::Upgrade() {
    this->UpGreade();
}
