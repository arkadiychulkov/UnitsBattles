#pragma once
#include"weapon.h"

namespace WeaponSpace {
	class bow : weapon
	{
	private:
		int maxDamage;
	public:
		bow(std::string name, unsigned int damage, int maxda);

		Grade GetDamage();
		void Upgrade();

	};
}