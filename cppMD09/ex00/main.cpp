#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cerr << "ERR: Cant Open File" << std::endl;
        return EXIT_FAILURE;
    }
    Btc btc;

    btc.readFile(argv[1]);
    return 0;
}