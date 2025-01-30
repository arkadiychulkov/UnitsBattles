#pragma once
#include<iostream>
class ISerializable {
public:
	virtual std::ostream& Serialize(std::ostream& output) = 0;
	virtual std::istream& Deserialize(std::istream& input) = 0;

	virtual std::ostream& Serialize(std::string& Path) = 0;
	virtual std::istream& Deserialize(std::string& Path) = 0;

	virtual std::ostream& Serialize() = 0;
	virtual std::istream& Deserialize() = 0;
};