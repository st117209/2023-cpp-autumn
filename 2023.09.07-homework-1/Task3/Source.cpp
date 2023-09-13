#include<iostream>

int main(int argc, char* argv[])
{
	int long n = 0;
	std::cin >> n;
	std::cout << (n / 10) * (n / 10 + 1) * 100 + 25 << std::endl;

	return EXIT_SUCCESS;
}