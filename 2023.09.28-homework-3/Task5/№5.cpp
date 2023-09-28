#include<iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	std::cin >> x;

	int polindrom = 0;
	for (int i = 1; i <= x; ++i)
	{
		if (i == obr(i)) {
			polindrom++;
		}
	}

	return 0;
}
int obr(int n) {
	for (n > 0) {
		
	}
}