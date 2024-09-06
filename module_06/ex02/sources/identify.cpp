#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

template <typename T>
bool tryIdentify(Base &p, const std::string &typeName) {
    try {
        dynamic_cast<T&>(p);
        std::cout << typeName << std::endl;
        return (true);
    } catch (const std::bad_cast& err) {
        return (false);
    }
}

void identify(Base &p) {
    if (tryIdentify<A>(p, "A")) return ;
    if (tryIdentify<B>(p, "B")) return ;
    if (tryIdentify<C>(p, "C")) return ;
    std::cout << "Unknown" << std::endl;
}