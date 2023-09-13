#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	b = (a > 0) ? (a * (a + 1)) / 2 : 1 - (a * (a - 1)) / 2;
	std::cout << b << std::endl;
	return EXIT_SUCCESS;
}