#include "Array.hpp"
#include "Array.tpp"

int main(void)
{
    Array<int> array_1;
    Array<int> array_2(10);
    Array<std::string> s_array(5);
	Array<std::string> s_array_fail;
	std::string str = "Vanderhammer";

    std::cout << "------Int Array Tests------" << std::endl;
    for (int i = 0; i < 10; i++)
        array_2[i] = i + 3;
    for (int i = 0; i < 10; i++)
        std::cout << array_2[i] << std::endl;
    std::cout << "------Invalid Index Tests------" << std::endl;
    try{
        array_1[0] = -2;
    }
	catch (std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		array_2[11] = 11;
	}
	catch (std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------String Array Tests------" << std::endl;
	for(int i = 0; i < 5; i++)
	{
		s_array[i] = str;
		str += "|" + str;
	}
	for (int i = 0; i < 5; i++)
		std::cout << s_array[i] << std::endl;
	std::cout << "------Invalid Index String Tests------" << std::endl;
	try{
		s_array[6] = str;
	}
	catch(std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		s_array_fail[0] = str;
	}
	catch(std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}