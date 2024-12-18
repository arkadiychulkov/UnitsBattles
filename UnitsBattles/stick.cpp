#include "weapon.h"
#include "stick.h"

Grade stick::GetDamage() {
    return this->GetGrade();
}

void stick::Upgrade() {
    this->UpGreade();
}
