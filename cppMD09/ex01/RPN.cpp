#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(std::stack<double> nb){
    this->nums = nb;
}

RPN &RPN::operator=(const RPN &src){
    if (this != &src)
        this->nums = src.nums;
    return *this;
}

RPN::RPN(RPN const &src){
    operator=(src);
}

RPN::~RPN()
{}

void RPN::exe(std::string src)
{
    
    for (int i = 0; i < src.size(); i++){
        char c = src[i];        
        if (c == ' ')
            continue;
        else if (isdigit(c)){
            int nb = c - '0';
            nums.push(nb);
        }
        else if (c == '+' && nums.size() >= 2){
            double a, b = nums.top();
            nums.pop();
            a = nums.top();
            nums.pop();
            nums.push(a + b);
        }
        else if (c == '-' && nums.size() >=2){
            double a, b = nums.top();
            nums.pop();
            a = nums.top();
            nums.pop();
            nums.push(a - b);
        }
        else if (c == '*' && nums.size() >= 2){
            double a, b = nums.top();
            nums.pop();
            a = nums.top();
            nums.pop();
            nums.push(a * b);
        }
        else if (c == '/' && nums.size() >= 2){
            double a, b = nums.top();
            nums.pop();
            a = nums.top();
            nums.pop();
            nums.push(a / b);
        }
        else{
            std::cout << "ERR: Invalid input." << std::endl;
            return;
        }
    }
    if (nums.size() == 1){
        double res = nums.top();
        nums.pop();
        std::cout << "Result: " << res << std::endl;
    }
    else
        std::cout << "ERR: Invalid input." << std::endl;
}