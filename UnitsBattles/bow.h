#pragma once
#include"weapon.h"
class bow : weapon
{
private:
	int maxDamage;
public:
	Grade GetDamage();
	void Upgrade();

};

