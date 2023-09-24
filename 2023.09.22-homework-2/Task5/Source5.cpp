#include <iostream>

int main(int argc, char* argv[]) 
{
    int n = 0;
    std::cin >> n;
    if ((n % 10) == 1) 
    {
        if ((n % 100) == 11) 
        {
            std::cout << n << " bochek" << std::endl;
        }
        else 
        {
            std::cout << n << " bochka" << std::endl;
        }
    }
    else if (((n % 10) == 2) || ((n % 10) == 3) || ((n % 10) == 4)) 
    {
        if (((n % 100) == 12) || ((n % 100) == 13) || ((n % 100) == 14)) 
        {
            std::cout << n << " bochek" << std::endl;
        }
        else 
        {
            std::cout << n << " bochki" << std::endl;
        }
    }
    else 
    {
        std::cout << n << " bochek" << std::endl;
    }
    return EXIT_SUCCESS;
}