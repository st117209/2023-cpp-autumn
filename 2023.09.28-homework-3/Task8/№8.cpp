#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int n = 0;
    int t = 0;
    int nod = 0;
    char a_ch = 'A';
    char b_ch = 'B';
    std::cin >> a >> b >> n;
    int a1 = a;
    int b1 = b;
    if (a > b)
    {
        nod = a;
        a = b;
        b = nod;
        a_ch = 'B';
        b_ch = 'A';
    }
    if (n == b)
    {
        std::cout << ">" << b_ch;
        return 0;
    }
    while (b1 != 0)
    {
        nod = a1 % b1;
        a1 = b1;
        b1 = nod;
    }
    if ((n % a1 != 0) || ((n > a) && (n > b)))
    {
        std::cout << "Impossible" << std::endl;
    }
    else
    {
        while (1)
        {
            t += a;
            std::cout << ">" << a_ch << std::endl;
            std::cout << a_ch << ">" << b_ch << std::endl;
            if (t >= b)
            {
                std::cout << b_ch << ">" << std::endl;
                std::cout << a_ch << ">" << b_ch << std::endl;
                t %= b;
            }
            if ((t == n) || (t == 0))
            {
                break;
            }
        }
    }
    return 0;
}