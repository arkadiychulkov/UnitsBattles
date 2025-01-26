#pragma once
#include "weapon.h"

namespace WeaponSpace {
	class sword : public weapon
	{
	public:
		sword(std::string name, unsigned int damage);

		Grade GetDamage();
		void Upgrade();
	};
}