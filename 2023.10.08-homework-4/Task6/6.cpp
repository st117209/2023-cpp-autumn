#include<iostream>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	std::cin >> *(a);
	int min = *(a);
	int max = *(a);
	int min_ad = 0;
	int max_ad = 0;
	for (int i = 1; i < n; ++i)
	{
		std::cin >> *(a + i);
		if (*(a + i) < min)
		{
			min = *(a + i);
			min_ad = i;
		}
		if (*(a + i) >= max)
		{
			max = *(a + i);
			max_ad = i;
		}
	}
	*(a + max_ad) = min;
	*(a + min_ad) = max;
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	free(a);

	return 0;
}
