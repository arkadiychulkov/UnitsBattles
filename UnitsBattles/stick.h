#pragma once
#include"weapon.h"
class stick : weapon
{
private:
	int charges;
public:
	Grade GetDamage();
	void Upgrade();
};

