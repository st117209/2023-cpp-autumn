#include<iostream>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	std::cin >> *(a + 0);
	int max = *(a + 0);
	for (int i = 1; i < n; ++i)
	{
		std::cin >> *(a + i);

		if (*(a + i) > max)
		{
			max = *(a + i);
		}

	}
	std::cout << max;
	free(a);

	return 0;
}

