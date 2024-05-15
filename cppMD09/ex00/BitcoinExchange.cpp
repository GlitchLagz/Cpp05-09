#include "BitcoinExchange.hpp"

const char* WHITESPACE = " \t\n\r";

static std::string& ltrim(std::string& s){
    s.erase(0, s.find_first_not_of(WHITESPACE));
    return s;
}

static std::string& rtrim(std::string& s){
    s.erase(s.find_last_not_of(WHITESPACE) + 1);
    return s;
}

static std::string& trim(std::string& s){
    return ltrim(rtrim(s));
}

Btc::Btc()
{
	int i = 0;
	this->flag = 1;
	std::ifstream file("./data.csv");
	if (!file.is_open()){
		this->flag = 0;
		return;
	}
	std::string line;
	while(std::getline(file, line))
	{
		if (i == 0){
			i = 1;
			continue;
		}
		size_t pos = line.find(',');
		if (pos == std::string::npos){
			std::cerr << "Error : Invalid Paramter" << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
        double value;
        try {
            value = std::stod(line.substr(pos + 1));
        }
        catch (std::exception &e){
            std::cerr << e.what() << std::endl;
            continue;
        }
		this->setData(date, value);
	}
	file.close();
}

Btc::~Btc()
{}

Btc& Btc::operator=(Btc const &src){
    if (this != &src)
        this->data = src.data;
    return *this;
}

Btc::Btc(Btc const &src){
    operator=(src);
}

void Btc::setData(std::string date, float value){
	this->data.insert(std::make_pair(date, value));
}

std::map<std::string, float> Btc::getData(){
	return this->data;
}

std::vector<std::string> Btc::cpp_split(std::string str, char dl)
{
	std::vector<std::string> res;
	std::string substr = "";
	for (size_t i = 0; i < str.length(); i++){
		if (str[i] != dl)
			substr += str[i];
		else{
			res.push_back(substr);
			while (str[i] == dl)
				i++;
			i--;
			substr = "";
		}
	}
	res.push_back(substr);
	return res;
}

void Btc::readFile(std::string path)
{
	int i = 0;
	std::ifstream file(path);
	if (!file.is_open()){
		this->flag = -1;
		return;
	}
	std::string line;
	std::vector<std::string> vec;
	while(std::getline(file, line))
	{
		if (i == 0){
			i = 1;
			continue;
		}
		vec = this->cpp_split(line, '|');
		if (vec[1].length() == 0 || vec.size() < 2){
			std::cout << "Error: bad input => " << vec[0] << std::endl;
			continue;
		}
		std::map<std::string, float>::iterator it = this->data.upper_bound(trim(vec[0]));
		if (it != this->data.end()){
	        std::pair<std::string, float> p = *(--it);
			try{
				if (std::stod(vec[1]) > 1000)
					std::cout << "Error: too large a number." << std::endl;
				else if (std::stod(vec[1]) < 0)
					std::cout << "Error: not a positive number." << std::endl;
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
