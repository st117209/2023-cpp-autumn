#include <iostream>

int main(int argc, char* argv[])
{
    int BITS = sizeof(unsigned int) * 8;
    unsigned int a = 0;
    std::cin >> a;
    unsigned int b = 0;
    std::cin >> b;
    unsigned int c = 0;
    
    bool up = 0;
    for (int i = 0; i < BITS; i++)
    {
        bool bitA = ((a >> i) & 1);
        bool bitB = ((b >> i) & 1);
        bool d = bitA ^ bitB ^ up;
        up = (bitA & bitB) | (bitA & up) | (bitB & up);
        c = c | ((int)d << i);
    }   
    std::cout << c;

    return 0;
}