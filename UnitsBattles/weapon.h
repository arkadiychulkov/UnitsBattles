#pragma once
#include<string>
#include"ISerializable.h"

namespace WeaponSpace {
	enum Grade {
		Common,
		Rare,
		Epic,
		Legendary,
		Myphic
	};

	class weapon : ISerializable
	{
	protected:
		Grade grade;
		std::string name;
		unsigned int damage;
	public:
		weapon();
		weapon(std::string name, int damage);
		weapon(std::string name);

		Grade GetDamage();
		virtual void Upgrade() = 0;
		int GetUron();//он нужен

		virtual std::ostream& Serialize(std::ostream& output) = 0;
		virtual std::istream& Deserialize(std::istream& input) = 0;
		virtual std::ostream& Serialize(std::string& path) = 0;
		virtual std::istream& Deserialize(std::string& path) = 0;
		virtual std::ostream& Serialize() = 0;
		virtual std::istream& Deserialize() = 0;
	};
}