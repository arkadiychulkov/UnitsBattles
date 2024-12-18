#include "bow.h"
#include "weapon.h"

bow::bow(std::string name, unsigned int damage, int maxda) : weapon(name, damage), maxDamage(maxda) {}

Grade bow::GetDamage() {
    return this->GetGrade();
}

void bow::Upgrade() {
    this->UpGreade();
}
