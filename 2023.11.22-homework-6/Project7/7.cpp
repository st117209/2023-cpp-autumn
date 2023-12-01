#include<iostream>

int n[4]{ 0 };
int** d = new int* [4] {nullptr, new int[10], new int[10], new int[10]};

void shift(int from = 1, int to = 3)
{
	std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
	--n[from];
	d[to][n[to]] = d[from][n[from]];
	n[from]++;
}

void hanoi(int cnt, int from = 1, int to = 3)
{
	if (cnt <= 0)
	{
		return;
	}

	int res = 6 - from - to;

	hanoi(cnt - 1, from, res);
	shift(from, to);
	printf("%d %d %d\n", cnt, from, to);
	hanoi(cnt - 1, res, to);
}

void sort()
{
	int cnt = 1;
	while(n[1] > 0)
	{
		for (int i = n[3]; i > 0; --i)
		{
			if (d[1][n[1] - 1] < d[3][i - 1])
			{
				cnt = n[3] - i;
				break;
			}
		}
		hanoi(cnt);
		cnt = 0;
	}
}

int main(int argc, char* argv[])
{
	std::cin >> n[1];
	for (int i = n[1] - 1; i >= 0; --i)
	{
		std::cin >> d[1][i];
	}
	sort();

	return 0;
}
