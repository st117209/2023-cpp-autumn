#include <iostream>

int main(int argc, char* argv[])
{
	int t = 0;
	std::cin >> t;

	int num = 1;
	int cnt = 1;
	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j <= cnt; ++j)
		{
			std::cout << num << " ";
		}
		cnt++;
		if (cnt > num)
		{
			cnt = 1;
			num++;
		}
	}

	return 0;
}