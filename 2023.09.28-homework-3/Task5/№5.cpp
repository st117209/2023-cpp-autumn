#include<iostream>

int main(int argc, char* argv[])
{
	int k = 0;
	int cnt = 0;
	std::cin >> k;
	for (int i = 1; i <= k; ++i)
	{
		int polindrom = 0;
		for (int j = i; j > 0; j = j / 10)
		{
			polindrom = j % 10 + polindrom * 10;
		}
		if (polindrom == i)
		{
			cnt += 1;
		}
	}
	std::cout << cnt << std::endl;

	return 0;
}