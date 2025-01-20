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
	bool IsInDefence�;
public:
	Unit(std::string name, int hp);
	 
	virtual void Attak(Unit& enemy);
	virtual void Defence();

	bool GetDef();

	void GetDamag(int damag);//TakeDamag

	int ReturnDamagByGrade(Grade grade);//� �� ������� ������ ��� ������ � ������ ���������� ����� ������� ���� ������ ���

	friend std::ostream& operator<<(std::ostream& os, const Unit& arr);
};