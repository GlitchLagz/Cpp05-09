#pragma once
#include <iostream>
#include <stack>
# define INV -1
# define ADD 0
# define SUB 1
# define MUL 2
# define DIV 3

class RPN{
    private:
        std::stack<double> nums;
    public:
        RPN();
        RPN(std::stack<double> nb);
        RPN &operator=(const RPN &var);
        RPN(const RPN &src);
        ~RPN();
        
        void exe(std::string src);
};