#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    int n = 0;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    if (a > b)
    {
        n = a;
        a = b;
        b = n;
    }
    if (b > c)
    {
        n = b;
        b = c;
        c = n;
    }
    if (a > b)
    {
        n = a;
        a = b;
        b = n;
    }
    std::cout << a;
    std::cout << b;
    std::cout << c;
    return EXIT_SUCCESS;
}