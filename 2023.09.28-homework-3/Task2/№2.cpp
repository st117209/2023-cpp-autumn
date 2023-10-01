#include <iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	bool n = 0;
	std::cin >> x;
	while (x > 0) {
		n = n || (x % 10);
		if (n)
		{
			std::cout << x % 10;
		}
		x = x / 10;
	}
		return 0;
	}