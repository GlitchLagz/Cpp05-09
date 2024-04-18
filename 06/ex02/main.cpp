#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>


Base * generate(void)
{
    std::srand(time(NULL));

    int rand_num = rand() % 3;
    
    switch (rand_num)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            std::cout << "Couldn't Generate a Class" << std::endl;
            return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A identified" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B identified" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C identified" << std:: endl;
}

void identify(Base& p)
{
    try{
        A& tmp = dynamic_cast<A&>(p);
        (void)tmp;
        std::cout << "A identified" << std::endl;
    }
    catch (std::exception &e){}
    try{
        B& tmp = dynamic_cast<B&>(p);
        (void)tmp;
        std::cout << "B identified" << std::endl;
    }
    catch (std::exception &e){}
    try{
        C& tmp = dynamic_cast<C&>(p);
        (void)tmp;
        std::cout << "C identified" << std::endl;
    }
    catch (std::exception &e){}
}

int main(void)
{
    Base *base;
    base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}