#pragma once
#include "weapon.h"
class sword : weapon
{
public:
	sword(std::string name, unsigned int damage);

	Grade GetDamage();
	void Upgrade();
};

