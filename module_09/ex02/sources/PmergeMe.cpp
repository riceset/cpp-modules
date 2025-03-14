#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    (void)other;
    return (*this);
}

PmergeMe::~PmergeMe() {}

double PmergeMe::getTimeInMicroSeconds(const struct timeval& start, const struct timeval& end) const {
    return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

std::deque<size_t> PmergeMe::generateJacobsthalNumbers(size_t n) {
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < n) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

std::deque<size_t> PmergeMe::getInsertionSequence(size_t n) {
    std::deque<size_t> jacobsthal = generateJacobsthalNumbers(n);
    std::deque<size_t> sequence;
    
    for (size_t i = 2; i < jacobsthal.size(); ++i) {
        for (size_t pos = jacobsthal[i]; pos > jacobsthal[i-1]; --pos) {
            if (pos <= n) {
                sequence.push_back(pos);
            }
        }
    }
    return sequence;
}

void PmergeMe::processInput(int argc, char **argv) {
    try {
        // Validate input first
        validateInput(argc, argv);
        
        // Parse input into both containers
        std::deque<int> dequeNumbers = parseInput<std::deque<int> >(argc, argv);
        std::list<int> listNumbers = parseInput<std::list<int> >(argc, argv);
        
        // Print unsorted sequence
        std::cout << "Before: ";
        printSequence<std::deque<int> >(dequeNumbers);
        
        // Timing for deque
        struct timeval dequeStart, dequeEnd;
        gettimeofday(&dequeStart, NULL);
        mergeInsertSort(dequeNumbers);
        gettimeofday(&dequeEnd, NULL);
        
        // Timing for list
        struct timeval listStart, listEnd;
        gettimeofday(&listStart, NULL);
        mergeInsertSort(listNumbers);
        gettimeofday(&listEnd, NULL);
        
        // Print sorted sequence
        std::cout << "After: ";
        printSequence<std::deque<int> >(dequeNumbers);
        
        // Print timing measurements
        double dequeTime = getTimeInMicroSeconds(dequeStart, dequeEnd);
        double listTime = getTimeInMicroSeconds(listStart, listEnd);
        
        std::cout << "Time to process a range of " << dequeNumbers.size() 
                  << " elements with std::deque : " << std::fixed << std::setprecision(5) 
                  << dequeTime << " us" << std::endl;
        std::cout << "Time to process a range of " << listNumbers.size() 
                  << " elements with std::list : " << std::fixed << std::setprecision(5) 
                  << listTime << " us" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

//error handling

void PmergeMe::throwError(const std::string& message) const {
    std::cerr << "Error: " << message << std::endl;
    throw std::runtime_error(message);
}

bool PmergeMe::isValidNumber(const std::string& str) const {
    // Check if string is empty
    if (str.empty())
        return false;
    
    // Check if string contains only digits
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool PmergeMe::isPositiveInteger(const std::string& str) const {
    if (!isValidNumber(str))
        return false;
    
    // Convert to integer and check if positive
    std::istringstream iss(str);
    int num;
    iss >> num;
    return num > 0;
}

void PmergeMe::validateInput(int argc, char **argv) const {
    if (argc < 2)
        throwError("No arguments provided");
    
    for (int i = 1; i < argc; ++i) {
        if (!isPositiveInteger(argv[i]))
            throwError("Invalid input: " + std::string(argv[i]));
    }
}