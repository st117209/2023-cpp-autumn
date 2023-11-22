#include<iostream>

void hanoi(int n, int from, int to)
{
	if (n <= 0)
	{
		return;
	}
	if (n == 1)
	{
		printf("%d %d %d\n", n, from, to);
	}
	else
	{
		int res = 6 - from - to;
		hanoi(n - 1, from, to);
		printf("%d %d %d\n", n, from, res);
		hanoi(n - 1, to, from);
		printf("%d %d %d\n", n, res, to);
		hanoi(n - 1, from, to);

	}

}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 3);
	return 0;
}