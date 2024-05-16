#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(int argc, char **argv){
    std::deque<int> dq;
    std::list<int> lst;

    srand(time(NULL));
    for (int i = 1; i < argc; ++i){
        int tmp = atoi(argv[i]);
        if (tmp < 1){
            std::cout << "ERR: Invalid value: " << argv[i] << ", only positve values" << std::endl;
            exit(1);
        }
        dq.push_back(tmp);
        lst.push_back(tmp);
    }
    std::cout << "Before: ";
    display(dq);

    clock_t start_dq = clock();
    mergeInsertSort(dq);
    clock_t end_dq = clock();
    double res_t = static_cast<double>(end_dq - start_dq) / CLOCKS_PER_SEC * 1000;

    clock_t start_lst = clock();
    mergeInsertSort(lst);
    clock_t end_lst = clock();
    double res_t2 = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display(dq);
    std::cout << "Time to process a range of " << dq.size() << " elements with a deque containter: " << res_t << " us" << std::endl;
    std::cout << "Time to process a range of " << lst.size() << " elements with a list container: " << res_t2 << " us" << std::endl;
    if (dq == std::deque<int>(lst.begin(), lst.end()))
        std::cout << "The sorted sequences are equal" << std::endl;
    else
        std::cout << "The sort sequences are not equal" << std::endl;
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