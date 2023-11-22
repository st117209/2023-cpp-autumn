#include<iostream>

void hanoi(int n, int from, int to)
{
	if (n <= 0)
	{
		return;
	}

	int res = 6 - from - to;
	hanoi(n - 1, from, res);
	printf("%d %d %d\n", n, from, to);
	hanoi(n - 1, res, to);
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int from = 1;
	int to = 0;
	if (n % 2 == 0)
	{
		to = 3;
	}
	else
	{
		to = 2;
	}
	hanoi(n, from, to);
	int res = 5 - to;
	for (int i = n; i > 0; i--)
	{
		hanoi(i - 1, to, res);
		std::swap(to, res);
	}
	return 0;
}