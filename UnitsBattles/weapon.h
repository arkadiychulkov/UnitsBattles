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
	weapon(std::string name, unsigned int damage);
	weapon(std::string name);

	unsigned int GetDamage();
	void UpGreade();
	Grade GetGrade();
};

