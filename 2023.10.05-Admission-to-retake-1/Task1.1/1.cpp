#include <iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    int s = 0;
    for (int i = 0; n >> i != 0; i++)
    {
        if ((n >> i & 1) == 1)
        {
            s++;
        }
    }
    std::cout << s;

    return 0;
}