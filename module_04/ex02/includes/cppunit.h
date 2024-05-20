#ifndef CPPUNIT_H
#define CPPUNIT_H

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

class Cppunit {
public:
    #define CHECK(a, b) check<long long>(a, b, #a, #b, __FILE__, __LINE__, __FUNCTION__)
    #define CHECKT(a)   check<bool>(a, true, #a, "true", __FILE__, __LINE__, __FUNCTION__)
    #define CHECKS(a, b) check<std::string>(a, b, #a, #b, __FILE__, __LINE__, __FUNCTION__)
    typedef const std::string& cs;
    int checks, fails; std::ostringstream serr;
    std::istringstream* in;
    
    Cppunit() : checks(0), fails(0), in(0) {}
    ~Cppunit() {
        delete in;
    }

    void test_cin(cs s) {
        if (in) delete in;
        in = new std::istringstream(s);
        std::cin.rdbuf(in->rdbuf());
    }

    void fail_hdr(cs stra, cs strb, cs file, int line, cs func) {
        serr << ANSI_COLOR_RED << "==================================================" << std::endl
             << "FAIL: " << func << std::endl
             << "--------------------------------------------------" << std::endl
             << "File \"" << file << "\", line " << line << " in " << func << std::endl
             << "  Checking " << stra << " == " << strb << std::endl;
    }

    template <typename T>
    void check(T a, T b, cs stra, cs strb, cs file, int line, cs func) {
        checks++;
        if (a == b) {
            std::cout << ANSI_COLOR_GREEN << "." << ANSI_COLOR_RESET << std::endl;
            return;
        }
        fails++;
        std::cout << ANSI_COLOR_RED << "F" << ANSI_COLOR_RESET << std::endl;
        fail_hdr(stra, strb, file, line, func);
        serr << "  Error: \"" << a << "\" != \"" << b << "\"" << std::endl << std::endl;
    }

    virtual void single_test() {}
    virtual void test_list() {
        single_test();
    }
    double dclock() {
        return static_cast<double>(clock()) / CLOCKS_PER_SEC;
    }

    int status() {
        std::cout << ANSI_COLOR_RESET << std::endl;
        if (fails) std::cout << serr.str();
        std::cout << "--------------------------------------------------" << std::endl
                  << "Ran " << checks << " checks in " << dclock() << "s" << std::endl;
        if (fails) {
            std::cout << ANSI_COLOR_RED << "FAILED (failures=" << fails << ")" << ANSI_COLOR_RESET;
        } else {
            std::cout << ANSI_COLOR_GREEN << "OK" << ANSI_COLOR_RESET;
        }
        std::cout << std::endl;
        return fails > 0;
    }

    int run() {
        std::streambuf* ocin = std::cin.rdbuf();
        test_list();
        std::cin.rdbuf(ocin);
        return status();
    }
};

#endif // CPPUNIT_H
