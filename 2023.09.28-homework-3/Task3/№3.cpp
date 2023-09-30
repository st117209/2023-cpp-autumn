#include<iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	std::cin >> x;
	int del = 0;
	for (int i = 1; i <= x; ++i)
	{
		if (x % i == 0)
		{
			++del;
		}
	}
	std::cout << del << std::endl;
	return 0;
}