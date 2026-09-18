#include "whatever.hpp"

int main(void)
{
    int num1 = 2;
    int num2 = 3;

    ::swap(num1, num2);
    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
    std::cout << "min( num1, num2 ) = " << ::min(num1, num2) << std::endl;
    std::cout << "max( num1, num2 ) = " << ::max(num1, num2) << std::endl;

    std::string str1 = "chaine1";
    std::string str2 = "chaine2";

    ::swap(str1, str2);
    std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
    std::cout << "min( str1, str2 ) = " << ::min(str1, str2) << std::endl;
    std::cout << "max( str1, str2 ) = " << ::max(str1, str2) << std::endl;
    return 0;
}
