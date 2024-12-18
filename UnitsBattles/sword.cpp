#include "sword.h"
#include "weapon.h"

sword::sword(std::string name, unsigned int damage) : weapon(name, damage) {}

Grade sword::GetDamage() {
    return this->GetGrade();
}

void sword::Upgrade() {
    this->UpGreade();
}
