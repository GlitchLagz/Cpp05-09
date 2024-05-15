#include "RPN.hpp"

int main (int argc, char **argv){
    if (argc != 2){
        std::cout << "ERR: wrong amount of arguments" << std::endl;
        return 1;
    }
    std::string tmp = argv[1];
    RPN calc;
    calc.exe(tmp);
    return 0;
}