#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

template <typename T>
void castByPointer(Base *p, std::string message) {
    if (dynamic_cast<T*>(p)) {
        std::cout << message << std::endl;
    }
}

template <typename T>
void castByReference(Base &p, std::string message) {
    try {
        T t = dynamic_cast<T&>(p);
        std::cout << message << std::endl;
    } catch (std::exception &e) {}
}

void identify(Base *p) {
    castByPointer<A>(p, "A");
    castByPointer<B>(p, "B");
    castByPointer<C>(p, "C");
}

void identify(Base &p) {
    castByReference<A>(p, "A");
    castByReference<B>(p, "B");
    castByReference<C>(p, "C");
}