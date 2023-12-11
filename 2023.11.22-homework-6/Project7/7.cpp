#include<iostream>

int n[4]{ 0 };
int** d = new int* [4] {nullptr, new int[10], new int[10], new int[10]};

void shift(int from = 1, int to = 3)
{
	std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
	--n[from];
	d[to][n[to]] = d[from][n[from]];
	n[to]++;
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
	//printf("%d %d %d\n", cnt, from, to);
	hanoi(cnt - 1, res, to);
}

void sort()
{
	int cnt = 0;
	while (n[1] > 0)
	{
		for (int i = 0; i < n[3]; ++i)
		{
			if (d[1][n[1] - 1] > d[3][n[3] - 1 - i])
			{
				cnt++;
			}
			else
			{
				break;
			}
		}
		hanoi(cnt, 3, 2);
		shift(1, 3);
		hanoi(cnt, 2, 3);
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