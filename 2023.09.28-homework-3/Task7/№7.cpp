#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int k = 1;
	int degree = 0;
	std::cin >> n;
	while (k < n)
	{
		k *= 2;
		degree += 1;
	}
	std::cout << degree << std::endl;

	return 0;
}