#pragma once
#include "MutantStack.tpp"
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	protected:
		
	public:
		MutantStack();
		MutantStack(MutantStack consr &src);
		MutantStack &operator=(MutantStack const &src);
		~MutantStack();


}