#pragma once
# include <iostream>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &src);
		Serializer& operator=(Serializer const &other);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};