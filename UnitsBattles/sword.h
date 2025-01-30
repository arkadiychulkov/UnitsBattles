#pragma once
#include "weapon.h"
#include"ISerializable.h"

namespace WeaponSpace {
	class sword : public weapon, public ISerializable
	{
	public:
		sword(std::string name, unsigned int damage);

		Grade GetDamage();
		void Upgrade() override;

		std::ostream& Serialize(std::ostream& output) override;
		std::istream& Deserialize(std::istream& input) override;
		std::ostream& Serialize(std::string& path) override;
		std::istream& Deserialize(std::string& path) override;
		std::ostream& Serialize() override;
		std::istream& Deserialize() override;
	};
}