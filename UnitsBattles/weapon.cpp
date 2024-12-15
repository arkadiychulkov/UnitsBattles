#include "weapon.h"
#include<iostream>
unsigned int weapon::GetDamage() {
	return damage;
}

Grade weapon::GetGrade() {
	return grade;
}

void weapon::UpGreade() {
	std::cout << this->grade << name << '\n';
}