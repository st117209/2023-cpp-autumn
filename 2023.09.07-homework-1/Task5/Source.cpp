#include <iostream>

int main() 
{
    int v = 0;
    int t = 0;
    int s = 0;
    cin >> v;
    cin >> t;
    s = v * t;
    cout << (109 + s % 109) % 109 + 1;
    return 0;
}