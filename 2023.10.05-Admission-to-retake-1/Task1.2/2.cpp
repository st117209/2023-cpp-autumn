#include<iostream>

int main(int argc, char* argv[])
{
	int BITS = sizeof(unsigned int) * 8;

	unsigned int n = 0;
	std::cin >> n;
	if (n == 0)
	{
		n = ~n;

	}
	else
	{
		int start = BITS - 1;
		int end = 0;
		while ((n >> start & 1) == 0)
		{
			start--;
		}
		while ((n >> end & 1) == 0)
		{
			end++;
		}
		start--;
		end++;
		unsigned int mask = 0;
		mask = ~mask;
		mask = (mask >> (start - end + 1));
		mask = ~mask;
		mask = (mask >> (BITS - start - 1));
		n = n ^ mask;

		for (int i = BITS - 1; i >= 0; --i)
		{
			std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
		}
	}

	return 0;
}