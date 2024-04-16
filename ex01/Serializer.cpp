#include "Serializer.hpp"

//Serialization converts a data object into a series of bytes that
//saves the state of the object in this easy transmittable form.
//Deserialization is the reverse process, putting it back together

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &src)
{
	operator=(src);
}

Serializer& Serializer::operator=(Serializer const &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}