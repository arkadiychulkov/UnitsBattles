#pragma once
#include"weapon.h"

namespace WeaponSpace {
	class bow : weapon
	{
	private:
		int maxDamage;
	public:
		bow(std::string name, int range, int damage);

		Grade GetDamage();
		void Upgrade();

	};
}