#include "swap.hpp"
#include "min.hpp"
#include "max.hpp"
#include <iostream>

void swapTest() {
    int x = 5, y = 3;
    std::cout << x << y << std::endl;
    swap(x,y);
    std::cout << x << y << std::endl;

    char a = 'a', b = 'z';
    std::cout << a << b << std::endl;
    swap(a,b);
    std::cout << a << b << std::endl;

    float g = 3.4, h = 4.5;
    std::cout << g << std::endl << h << std::endl;
    swap(g,h);
    std::cout << g << std::endl << h << std::endl;

    std::string s = "hello1", t = "hello2";
    std::cout << s << std::endl << t << std::endl;
    ::swap(s,t);
    std::cout << s << std::endl << t << std::endl;
}

void minTest() {
    int x = 5, y = 3;
    std::cout << min(x, y) << std::endl;
    x = 3, y = 5;
    std::cout << min(x, y) << std::endl;
    x = 3, y = 3;
    std::cout << min(x, y) << std::endl;

    char a = 'a', b = 'z';

    std::cout << min(a, b) << std::endl;
    a = 'z', b = 'a';
    std::cout << min(a, b) << std::endl;
    a = 'a', b = 'a';
    std::cout << min(a, b) << std::endl;

    float g = 3.4, h = 4.5;
    std::cout << min(g, h) << std::endl;

    std::string s = "hello1", t = "hello2";
    std::cout << ::min(s, t) << std::endl;
}

void maxTest() {
    int x = 5, y = 3;
    std::cout << max(x, y) << std::endl;
    x = 3, y = 5;
    std::cout << max(x, y) << std::endl;
    x = 3, y = 3;
    std::cout << max(x, y) << std::endl;

    char a = 'a', b = 'z';

    std::cout << max(a, b) << std::endl;
    a = 'z', b = 'a';
    std::cout << max(a, b) << std::endl;
    a = 'a', b = 'a';
    std::cout << max(a, b) << std::endl;

    float g = 3.4, h = 4.5;
    std::cout << max(g, h) << std::endl;

    std::string s = "hello1", t = "hello2";
    std::cout << ::max(s, t) << std::endl;
}

int main(void) {
    swapTest();
    std::cout << "---" << std::endl;
    minTest();
    std::cout << "---" << std::endl;
    maxTest();
    return (0);
}