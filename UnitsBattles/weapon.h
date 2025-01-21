#pragma once
#include<string>

namespace WeaponSpace {
	enum Grade {
		Common,
		Rare,
		Epic,
		Legendary,
		Myphic
	};

	class weapon
	{
	protected:
		Grade grade;
		std::string name;
		unsigned int damage;
	public:
		weapon();
		weapon(std::string name, unsigned int damage);
		weapon(std::string name);

		Grade GetDamage();
		virtual void UpGreade();
		int GetUron();//он нужен
	};
}