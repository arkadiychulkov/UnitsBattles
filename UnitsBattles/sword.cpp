#include "sword.h"
#include "weapon.h"

Grade sword::GetDamage() {
    return this->GetGrade();
}

void sword::Upgrade() {
    this->UpGreade();
}
