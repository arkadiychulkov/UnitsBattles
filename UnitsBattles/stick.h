#pragma once
#include"weapon.h"
#include"ISerializable.h"

namespace WeaponSpace {
	class stick : public weapon, public ISerializable
	{
	private:
		int charges;
	public:
		stick(std::string name, unsigned int damage, int charges);

		Grade GetDamage();
		void Upgrade() override;
		void AddCharges(int a);

		std::ostream& Serialize(std::ostream& output) override;
		std::istream& Deserialize(std::istream& input) override;
		std::ostream& Serialize(std::string& path) override;
		std::istream& Deserialize(std::string& path) override;
		std::ostream& Serialize() override;
		std::istream& Deserialize() override;
	};
}