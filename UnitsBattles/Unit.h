#pragma once
#include<iostream>
#include<ostream>
#include"weapon.h"

namespace UnintSpace {
	class Unit
	{
	protected:
		WeaponSpace::weapon* weaponn;
		int speed;
		int hp;
		std::string name;
		bool IsInDefenceó;
	public:
		Unit(std::string name, int hp);
		Unit(std::string name, int hp, WeaponSpace::weapon& weapon);

		virtual void Attak(Unit& enemy);
		virtual void Defence() = 0;

		bool GetDef();
		bool IsDead();

		int GetDamag(int damag);//TakeDamag

		int ReturnDamagByGrade(WeaponSpace::Grade grade);

		friend std::ostream& operator<<(std::ostream& os, const Unit& arr);
	};
}
//'UnintSpace::Unit': cannot instantiate abstract class