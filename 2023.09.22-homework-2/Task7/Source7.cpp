#include <iostream> 

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int n1 = 0;
	int n10 = 0;
	n1 = n % 10;
	n10 = n / 10;
	if (n1 == 1) { std::cout << "I"; }
	if (n1 == 2) { std::cout << "II"; }
	if (n1 == 3) { std::cout << "III"; }
	if (n1 == 4) { std::cout << "IV"; }
	if (n1 == 5) { std::cout << "V"; }
	if (n1 == 6) { std::cout << "VI"; }
	if (n1 == 7) { std::cout << "VII"; }
	if (n1 == 8) { std::cout << "VIII"; }
	if (n1 == 9) { std::cout << "IX"; }
	if (n10 == 1) { std::cout << "X"; }
	if (n10 == 2) { std::cout << "XX"; }
	if (n10 == 3) { std::cout << "XXX"; }
	if (n10 == 4) { std::cout << "XL"; }
	if (n10 == 5) { std::cout << "L"; }
	if (n10 == 6) { std::cout << "LX"; }
	if (n10 == 7) { std::cout << "LXX"; }
	if (n10 == 8) { std::cout << "LXXX"; }
	if (n10 == 9) { std::cout << "XC"; }
	if (n10 == 10) {std::cout << "C"; }
	return EXIT_SUCCESS;
}