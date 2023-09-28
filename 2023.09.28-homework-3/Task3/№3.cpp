#include<iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	std::cin >> x;

	int DEL = 0;
	for (int i = 1; i <= x; ++i)
	{
		if (x % i == 0)
		{
			++DEL;
		}
	}
	std::cout << DEL;
	return 0;
}