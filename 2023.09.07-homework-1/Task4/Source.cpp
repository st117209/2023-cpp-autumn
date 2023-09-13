#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	std::cout << 100 * n + 9 * 10 + 9 - n << std::endl;

	return EXIT_SUCCESS;
}