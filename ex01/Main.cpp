#include "Serializer.hpp"

int main(void)
{
	Data *info = new Data;
	info->client = "John";
	info->pin = 1021;
	
	uintptr_t raw = Serializer::serialize(info);
	Data *res = Serializer::deserialize(raw);

	std::cout << res->client << std::endl;
	std::cout << res->pin << std::endl;
	
	delete info;
	return 0;
}