#pragma once
#include<iostream>
#include<ostream>
#include"weapon.h"
class Unit
{
protected:
	weapon weaponn;
	int hp, speed;
	std::string name;
	bool IsInDefenceó;
public:
	Unit(std::string name, int hp);
	 
	void Attak(Unit& enemy);
	void Defence();
	void GetDamag(int damag);
	friend std::ostream& operator<<(std::ostream& os, const Unit& arr);
};