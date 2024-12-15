#pragma once
#include<iostream>
#include"weapon.h"
class Unit
{
protected:
	weapon weapon;
	int hp, speed;
	std::string name;
	bool IsInDefence;
public:
	void Attak(Unit& enemy);
	void Defence();
};

