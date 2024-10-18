#include <iostream>
#include "PrivateAccessor.hpp"

class X
{
private:
    int a = 1;
    double b = 2.5;
    std::string str = "hello";
};

DECLARE_ACCESS(X, int, a)
DECLARE_ACCESS(X, double, b)
DECLARE_ACCESS(X, std::string, str)

int main()
{
    X x;
    std::cout << PrivateAccess::access(x, PrivateAccess::PlaceHolder<int>) << "\n";
    std::cout << PrivateAccess::access(x, PrivateAccess::PlaceHolder<double>) << "\n";
    std::cout << PrivateAccess::access(x, PrivateAccess::PlaceHolder<std::string>) << "\n";
}
