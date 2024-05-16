#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <deque>

class PmergeMe{
    private:

    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        PmergeMe &operator=(const PmergeMe &src);
        PmergeMe(const PmergeMe &src);
        ~PmergeMe();

        template<typename T>
        void display(const T& src);
        template<typename T>
        void mergeInsertSort(T& src);
};