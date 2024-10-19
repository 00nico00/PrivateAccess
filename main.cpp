#include <iostream>
#include "PrivateAccessor.hpp"

class X
{
private:
    int a = 1;
    double b = 2.5;
    std::string str = "hello";

    int func(int& para)
    {
        std::cout << a + para << "\n";
        para = 2;
        return a + para;
    }
};

DECLARE_PROPERTY_ACCESSOR(X, int, a)
DECLARE_PROPERTY_ACCESSOR(X, double, b)
DECLARE_PROPERTY_ACCESSOR(X, std::string, str)

DECLARE_FUNCTION_ACCESSOR_With_1_ARGS(X, int, int&, func)

int main()
{
    X x;
    std::cout << PrivateAccess::access(x, PrivateAccess::Flag<int>) << "\n";
    std::cout << PrivateAccess::access(x, PrivateAccess::Flag<double>) << "\n";
    std::cout << PrivateAccess::access(x, PrivateAccess::Flag<std::string>) << "\n";

    int b = 1;
    int res = PrivateAccess::call(x, b, PrivateAccess::Flag<int>);
    std::cout << "res: " << res << ", b: " << b << "\n";
}
