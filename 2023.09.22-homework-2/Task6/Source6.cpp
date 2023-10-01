#include <iostream>

int main(int argc, char* argv[]) 
{
    int k = 0;
    int m = 0;
    int n = 0;
    int t = 0;
    std::cin >> k;
    std::cin >> m;
    std::cin >> n;
    t = n / k * 2 * m;
    if (n % k > 0) 
    {
        if (k / 2 < n % k) 
        {
            t = t + m * 2;
        }
        else 
        {
            t = t + m;
        }
    }
    if (n <= k) 
    {
        t = 2 * m;
    }
    std::cout << t << std::endl;
    return EXIT_SUCCESS;
}