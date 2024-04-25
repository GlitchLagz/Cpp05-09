#include "Array.hpp"

int main(void)
{
    Array<int> array_1;
    Array<int> array_2(10);
    Array<std::string> s_array(5);

    std::cout << "------Int Array Tests------" << std::endl;
    for (int i = 0; i < 10; i++)
        array_2[i] = i + 3;
    for (int i = 0; i < 10; i++)
        std::cout << array_2[i] << std::endl;
    std::cout << "------Invalid Index Tests------" << std::endl;
    try{
        
    }

}