#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;		
	std::cout << (a * (a / b) + b * (b / a)) / (b / a + a / b) << std::endl;

	return EXIT_SUCCESS;
}