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

int switch_helper(char c, std::stack<double> nums){
    if (!(nums.size() >= 2))
        return INV;
    if (c == '+')
        return ADD;
    if (c == '-')
        return SUB;
    if (c == '*')
        return MUL;
    if (c == '/')
        return DIV;
    return INV;
}
void RPN::exe(std::string src)
{
    
    for (int i = 0; i < src.size(); i++){
        char c = src[i];        
        if (c == ' ')
            continue;
        else if (isdigit(c)){
            int nb = c - '0';
            nums.push(nb);
            continue;
        }
        //std::cout << c << std::endl;
        int op = switch_helper(c, nums);
       //std::cout << op << std::endl;
        double a, b;
        switch(op){
            case ADD:
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a + b);
                break;
            case SUB:
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a - b);
                break;
            case MUL:
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a * b);
                break;
            case DIV:
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a / b);
                break;
            case INV:
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