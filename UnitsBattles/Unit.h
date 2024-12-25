#pragma once
#include<iostream>
#include<ostream>
#include"weapon.h"
class Unit
{
protected:
	weapon weaponn;
	int speed;
	unsigned int hp;
	std::string name;
	bool IsInDefenceó;
public:
	Unit(std::string name, int hp);
	 
	virtual void Attak(Unit& enemy);
	virtual void Defence();
	void GetDamag(int damag);
	friend std::ostream& operator<<(std::ostream& os, const Unit& arr);
};