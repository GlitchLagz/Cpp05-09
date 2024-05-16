#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(int argc, char **argv){

}

PmergeMe &PmergeMe::operator=(const PmergeMe &src){
    if (this != &src)
       *this = src;
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &src){
    operator=(src);
}

PmergeMe::~PmergeMe()
{}

template <typename T>
void PmergeMe::display(const T& src){
    typename T::const_iterator it;
    for (it = src.begin(); it != src.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
void PmergeMe::mergeInsertSort(T &src){
    typename T::iterator it1, it2;
    for (it1 = ++src.begin(); it1 != src.end(); ++it1){
        int tmp = *it1;
        it2 = it1;
        while (it2 != src.begin() && *(std::prev(it2)) > tmp){
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = tmp;
    }
}