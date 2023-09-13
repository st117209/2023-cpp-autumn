#include <iostream>
using namespace std;
int main() {
    int v, t, s;
    cin >> v;
    cin >> t;
    s = v * t;
    cout << (109 + s % 109) % 109 + 1;
    return 0;
}