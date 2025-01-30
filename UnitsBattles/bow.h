#pragma once
#include"weapon.h"
#include"ISerializable.h"

namespace WeaponSpace {
	class bow : public weapon, public ISerializable
	{
	private:
		int maxDamage;
	public:
		bow(std::string name, int range, int damage);

		Grade GetDamage();
		void Upgrade();

		std::ostream& Serialize(std::ostream& output) override;
		std::istream& Deserialize(std::istream& input) override;
		std::ostream& Serialize(std::string& path) override;
		std::istream& Deserialize(std::string& path) override;
		std::ostream& Serialize() override;
		std::istream& Deserialize() override;
	};
}