#pragma once
#include<string>

enum Grade {
	Common,
	Rare,
	Epic,
	Legendary,
	Myphic
};

class weapon
{
private:
	Grade grade;
	std::string name;
	unsigned int damage;
public:
	unsigned int GetDamage();
	void UpGreade();
	Grade GetGrade();
};

