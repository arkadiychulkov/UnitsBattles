#pragma once
#include<iostream>
#include<ostream>
#include"weapon.h"
#include"ISerializable.h"

namespace UnintSpace {
	class Unit : ISerializable
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

		virtual void Attak(Unit& enemy) = 0;
		virtual void Defence() = 0;

		bool GetDef();
		bool IsDead();

		virtual int GetDamag(int damag) = 0;//TakeDamag

		int ReturnDamagByGrade(WeaponSpace::Grade grade);

		friend std::ostream& operator<<(std::ostream& os, const Unit& arr);

		virtual std::ostream& Serialize(std::ostream& output) = 0;
		virtual std::istream& Deserialize(std::istream& input) = 0;
		virtual std::ostream& Serialize(std::string& path) = 0;
		virtual std::istream& Deserialize(std::string& path) = 0;
		virtual std::ostream& Serialize() = 0;
		virtual std::istream& Deserialize() = 0;
	};
}
//'UnintSpace::Unit': cannot instantiate abstract class