#include <iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	std::cin >> x;
	while (x > 0) {
		std::cout << x % 10 << std::endl;
		x = x / 10;
	}
	return 0;
}