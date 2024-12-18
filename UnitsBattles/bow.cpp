#include "bow.h"
#include "weapon.h"

Grade bow::GetDamage() {
    return this->GetGrade();
}

void bow::Upgrade() {
    this->UpGreade();
}
