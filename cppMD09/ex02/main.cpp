#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2){
        std::cerr << "ERR: wrong amount of arguments" << std::endl;
        return 1;
    }
    PmergeMe PmergeMe(argc, argv);
    return 0;
}
``