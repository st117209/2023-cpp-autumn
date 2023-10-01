#include <iostream>

int main(int argc, char* argv[]) 
{
    int n;
    std::cin >> n;
    int a1 = 15;
    int a5 = 70;
    int a10 = 125;
    int a20 = 230;
    int a60 = 440;
    int b1 = 0;
    int b5 = 0;
    int b10 = 0;
    int b20 = 0;
    int b60 = 0;
    int c20 = 0;
    int c10 = 0;
    int c5 = 0;
    int c1 = 0;
    int st = 0;
    int count = 0;

    if (n / 60 > 0) 
    {
        b60 = n / 60;
        n = n % 60;
    }
    if (n <= 5) 
    {
        if (a1 * n < a5) 
        {
            b1 = n;
        }
        else 
        {
            b5 = 1;
        }
    }
    else if (n <= 10) 
    {
        count = n / 5;
        st = n % 5;
        if ((a5 * count + st * a1) < a10)
        {
            b5 += 1;
            b1 += st;
        }
        else 
        {
            b10 += 1;
        }
    }
    else if (n <= 20) 
    {
        c10 = n / 10;
        c5 = (n - c10 * 10) / 5;
        c1 = n % 5;
        if ((a10 * c10 + a5 * c5 + a1 * c1) < a20)
        {
            b10 = c10;
            b5 = c5;
            b1 = c1;
        }
        else 
        {
            b20 += 1;
        }
    }
    else 
    {
        c20 = n / 20;
        c10 = (n - c20 * 20) / 10;
        c5 = (n - c20 * 20 - c10 * 10) / 5;
        c1 = n % 5;
        if ((c20 * a20 + c10 * a10 + c5 * a5 + c1 * a1) < a60)
        {
            b20 = c20;
            if ((a10 * c10 + a5 * c5 + a1 * c1) < a20)
            {
                b10 = c10;
                if ((a5 * c5 + a1 * c1) < a10)
                {
                    b5 = c5;
                    b1 = c1;
                }
                else 
                {
                    b10 += 1;
                }
            }
            else 
            {
                b20 += 1;
            }
        }
        else 
        {
            b60 += 1;
        }
    }
    std::cout << b1 << " " << b5 << " " << b10 << " " << b20 << " " << b60 << std::endl;

    return 0;
}