#include <iostream>

int main(int argc, char* argv[])
{
	int t = 0;
	std::cin >> t;
	int n = t;
	for (int i = 0; i < t; ++i)
	{
		for (int j = 1; j <= i && n > 0; j++)
		{
			std::cout << i << " " << std::endl;
			n -= 1;
		}
	}

	return 0;
}