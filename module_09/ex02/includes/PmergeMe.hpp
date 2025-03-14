#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <list>
#include <utility>
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <sys/time.h>

class PmergeMe {
private:
    std::deque<size_t> generateJacobsthalNumbers(size_t n);
    std::deque<size_t> getInsertionSequence(size_t n);

    // Error handling methods
    void throwError(const std::string& message) const;
    bool isValidNumber(const std::string& str) const;
    bool isPositiveInteger(const std::string& str) const;

    // Time measurement helper
    double getTimeInMicroSeconds(const struct timeval& start, const struct timeval& end) const;

    // Function object for pair comparison
    struct PairCompare {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
            return a.second < b.second;
        }
    };

    template<typename Container>
    void mergeInsertSort(Container& container);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void processInput(int argc, char **argv);
    void validateInput(int argc, char **argv) const;

    template<typename Container>
    Container parseInput(int argc, char **argv);

    template<typename Container>
    void printSequence(const Container& container);
};

//TPP

template<typename Container>
void PmergeMe::mergeInsertSort(Container& container) {
    if (container.size() <= 1) return;

    // Step 1: Create pairs
    std::deque<std::pair<typename Container::value_type, typename Container::value_type> > pairs;
    typename Container::iterator it = container.begin();
    
    // Handle the last element if size is odd
    typename Container::value_type lastElement;
    bool hasLastElement = false;
    
    if (container.size() % 2 != 0) {
        typename Container::iterator last = container.end();
        --last;
        lastElement = *last;
        hasLastElement = true;
    }

    // Create and sort pairs
    while (it != container.end()) {
        typename Container::iterator next_it = it;
        ++next_it;
        if (next_it == container.end()) break;

        typename Container::value_type first = *it;
        typename Container::value_type second = *next_it;
        
        if (second < first) {
            std::swap(first, second);
        }
        pairs.push_back(std::make_pair(first, second));
        ++it; ++it;
    }

    // Sort pairs by their larger elements (second elements)
    std::sort(pairs.begin(), pairs.end(), PairCompare());

    // Create main chain
    Container result;
    for (typename std::deque<std::pair<typename Container::value_type, typename Container::value_type> >::iterator pit = pairs.begin();
         pit != pairs.end(); ++pit) {
        result.push_back(pit->second);
    }

    // Insert remaining elements using Jacobsthal numbers
    std::deque<typename Container::value_type> pending;
    for (typename std::deque<std::pair<typename Container::value_type, typename Container::value_type> >::iterator pit = pairs.begin();
         pit != pairs.end(); ++pit) {
        pending.push_back(pit->first);
    }
    if (hasLastElement) {
        pending.push_back(lastElement);
    }

    // Get Jacobsthal-based insertion sequence
    std::deque<size_t> insertSequence = getInsertionSequence(pending.size());
    
    // Insert first element
    typename Container::iterator insertPos = std::lower_bound(result.begin(), result.end(), pending[0]);
    result.insert(insertPos, pending[0]);

    // Insert remaining elements according to Jacobsthal sequence
    for (std::deque<size_t>::iterator seqIt = insertSequence.begin(); seqIt != insertSequence.end(); ++seqIt) {
        if (*seqIt - 1 < pending.size()) {
            typename Container::iterator insertPos = std::lower_bound(result.begin(), result.end(), pending[*seqIt - 1]);
            result.insert(insertPos, pending[*seqIt - 1]);
        }
    }

    container = result;
}

template<typename Container>
Container PmergeMe::parseInput(int argc, char **argv) {
    Container numbers;
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || !iss.eof() || num < 0) {
            throw std::runtime_error("Error: Invalid input");
        }
        numbers.push_back(num);
    }
    return numbers;
}

template<typename Container>
void PmergeMe::printSequence(const Container& container) {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif