#include<iostream>
#include<ctime>

int* initRandomArray(int len);
void printArray(int* a, int len);
void mixArray(int* a, int len);
void bubbleSort(int* a, int len);
void insertionSort(int* a, int len);
void selectionSort(int* a, int len);
bool sorted(int* a, int len);
void monkeySort(int* a, int len);
void countSort(int* a, int len);
void gnomeSort(int* a, int len);

int main(int argc, char* argv[])
{
	srand(time(0));
	int len = 0;
	std::cout << "Set the length of the array: ";
	std::cin >> len;
	int* a = initRandomArray(len);
	printArray(a, len);
	std::cout << std::endl;
	{
		std::cout << "Mix array: " << std::endl;
		mixArray(a, len);
		printArray(a, len);
	}
	{
		std::cout << "bubbleSort: " << std::endl;
		mixArray(a, len);
		bubbleSort(a, len);
		printArray(a, len);
	}
	{
		std::cout << "insertionSort: " << std::endl;
		mixArray(a, len);
		insertionSort(a, len);
		printArray(a, len);
	}
	{
		std::cout << "selectionSort: " << std::endl;
		mixArray(a, len);
		selectionSort(a, len);
		printArray(a, len);
	}
	{
		std::cout << "countSort: " << std::endl;
		mixArray(a, len);
		countSort(a, len);
		printArray(a, len);
	}
	{
		std::cout << "gnomeSort: " << std::endl;
		mixArray(a, len);
		gnomeSort(a, len);
		printArray(a, len);
	}
	{
		std::cout << "monkeySort: " << std::endl;
		mixArray(a, len);
		monkeySort(a, len);
		printArray(a, len);
	}
	return 0;
}

int* initRandomArray(int len)
{
	int* a = new int [len] { 0 };
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 10;
	}

	return a;
}

void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void mixArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::swap(a[i], a[rand() % len]);
	}
}

void bubbleSort(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
			}
		}
	}
}

void insertionSort(int* a, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int n = i;
		while (n > 0 && a[n] < a[n - 1])
		{
			std::swap(a[n], a[n - 1]);
			--n;
		}
	}
}

void selectionSort(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		int min = i;
		for (int j = i + 1; j < len; ++j)
		{
			min = (a[min] <= a[j] ? min : j);
		}
		std::swap(a[i], a[min]);
	}
}

void countSort(int* a, int len)
{
	int maxx = a[0];
	for (int i = 0; i < len; ++i)
	{
		if (maxx < a[i])
		{
			maxx = a[i];
		}
	}
	maxx++;
	int* cnt = new int [maxx] { 0 };
	for (int i = 0; i < len; ++i)
	{
		++cnt[a[i]];
	}
	int i = 0;
	for (int j = 0; j < maxx; ++j)
	{
		while (cnt[j] > 0)
		{
			a[i] = j;
			++i;
			--cnt[j];
		}
	}

}

void gnomeSort(int* a, int len)
{
	int i = 1;
	while (i < len)
	{
		if (a[i - 1] <= a[i])
		{
			i++;
		}
		else
		{
			std::swap(a[i], a[i - 1]);
			--i;
		}
		if (i == 0)
		{
			i++;
		}
	}
}

bool sorted(int* a, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			return false;
		}
	}
	return true;
}

void monkeySort(int* a, int len)
{
	while (!sorted(a, len))
	{
		mixArray(a, len);
	}
}