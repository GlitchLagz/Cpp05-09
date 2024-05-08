#include "BitcoinExchange.hpp"

const char* WHITESPACE = " \t\n\r";

static std::string& ltrim(std::string& s){
    s.erase(0, s.find_last_not_of(WHITESPACE));
    return s;
}

static std::string& rtrim(std::string& s){
    s.erase(0, s.find_last_not_of(WHITESPACE) + 1);
    return s;
}

static std::string& trim(std::string& s){
    return ltrim(rtrim(s));
}

Btc::Btc(){
    std::string line;
    this->flag = 1;
    std::ifstream file("./data.csv");
    if (!file.is_open()){
        this->flag = 0;
        return;
    }
    int i = 0;
    while(std::getline(file, line))
    {
        if (i == 0){
            i = 1;
            continue;
        }
        size_t pos = line.find(',');
        if (pos == std::string::npos){
            std::cerr << "ERR: Invalid Paramter" << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        double value;
        try{
            value = std::stod(line.substr(0, pos));
        }
        catch (std::exception const &e){
            std::cerr << e.what() << std::endl;
            continue;
        }
        this->setData(date, value);
    }
    file.close();
}

Btc& Btc::operator=(Btc const &src){
    if (this != &src)
        this->data = src.data;
    return *this;
}

Btc::Btc(Btc const &src){
    operator=(src);
}

Btc::~Btc(){
}

void Btc::setData(std::string date, float nb){
    this->data.insert(std::make_pair(date, nb));
}

std::map<std::string, float> Btc::getData(){
    return this->data;
}

std::vector<std::string> Btc::cpp_split(std::string src, char dl){
    std::vector<std::string> res;
    std::string substr = "";

    for (size_t i = 0; i < src.length(); i++){
        if (src[i] != dl)
            substr += src[i];
        else{
            res.push_back(substr);
            while (src[i] == dl)
                i++;
            i--;
            substr = "";
        }
    }
    res.push_back(substr);
    return res;
}

void Btc::readFile(std::string path){
    int i = 0;
    std::string line;
    std::vector<std::string> vec;
    std::ifstream file(path);

    if (!file.is_open()){
        this->flag = -1;
        return;
    }
    while(std::getline(file, line)){
        if (i == 0){
            i = 1;
            continue;
        }
        vec = this->cpp_split(line, '|');
        if (vec[1].length() == 0 || vec.size() < 2){
            std::cout << "ERR: Bad input " << vec[0] << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it;
        it = this->data.upper_bound(trim(vec[0]));
        if (it != this->data.end()){
            std::pair<std::string, float> p = *(--it);
            try{
                if (std::stod(vec[1]) >1000)
                    std::cout << "ERR: num to large" << std::endl;
                else if (std::stod(vec[1]) < 0)
                    std::cout << "ERR: not a pos num" << std::endl;
                else
                    std::cout << vec[0] << " => " << vec[1] << " = " << std::stod(vec[1]) * p.second << std::endl;
            }
            catch (const std::exception &e){
                std::cerr << e.what() << std::endl;
                continue;
            }
        }
    }
    file.close();
}

const char *Btc::NotANumberException::what() const throw(){
    return ("ERR: input isnt a number");
}

const char *Btc::ParseValueException::what() const throw(){
    return ("ERR: couldn't parse value");
}
