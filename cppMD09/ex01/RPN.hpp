#pragma once
#include <iostream>
#include <stack>

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