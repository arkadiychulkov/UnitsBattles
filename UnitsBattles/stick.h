#pragma once
#include"weapon.h"
class stick : weapon
{
private:
	int charges;
public:
	stick(std::string name, unsigned int damage, int charges);

	Grade GetDamage();
	void Upgrade();
	void AddCharges(int);
};

