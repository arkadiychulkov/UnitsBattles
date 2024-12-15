#include "Unit.h"
void Unit::Attak(Unit& a) {
	std::cout << name << " " << a.name;
}

void Unit::Defence() {
	IsInDefence = !IsInDefence;
}