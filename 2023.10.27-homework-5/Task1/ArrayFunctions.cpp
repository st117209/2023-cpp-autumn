#include"ArrayFunctions.h"
#include<iostream>
#include<cstdlib>
#include<ctime>


void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Print array" << std::endl;
	std::cout << "2 - Append element to array" << std::endl;
	std::cout << "3 - Extract element from array" << std::endl;
	std::cout << "4 - Sort the array in ascending order" << std::endl;
	std::cout << "5 - Expand Array" << std::endl;
	std::cout << "6 - Swap the first maximum and last minimum element of the array" << std::endl;
	std::cout << "7 - Remove all duplicates from the array" << std::endl;
	std::cout << "8 - Add N random elements to the array" << std::endl;
}

void printArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[i] << " ";
		}
	}
	std::cout << std::endl;
}

void expandArray(int*& a, int& len)
{
	int* newA = new int[len + 1] { 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
	}
	a = newA;
	++len;
}

void addElement(int*& a, int& len, int element)
{
	expandArray(a, len);
	a[len - 1] = element;
}

void contractArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int* newA = new int[len - 1];
		for (int i = 0; i < len - 1; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
		a = newA;
		--len;
	}
}

bool indexValid(int index, int len)
{
	return (index >= 0 && index < len);
}

int deleteElement(int*& a, int& len, int index)
{
	int res = -1;
	if (indexValid(index, len))
	{
		res = a[index];
		for (int i = index; i < len - 1; ++i)
		{
			a[i] = a[i + 1];
		}
		contractArray(a, len);
	}
	return res;
}

void printReverseArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len / 2; ++i)
		{
			std::swap(a[i], a[len - i - 1]);
		}
	}
	std::cout << std::endl;
}

void add_n_Elements(int*& a, int& len, int n)
{
	srand(time(0));
	int newElement = 0;
	for (int i = 0; i < n; i++)
	{
		newElement = rand() % 10;
		addElement(a, len, newElement);
	}
}

void sortArray_ascending(int*& a, int& len)
{
	while (true)
	{
		int cnt = 0;
		for (int i = 0; i < len - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				std::swap(a[i], a[i + 1]);
				cnt++;
			}
		}
		if (cnt != 0)
		{
			cnt = 0;
		}
		else
		{
			break;
		}

	}
}

void findMin(int*& a, int& len, int& min) // last min
{
	for (int i = 0; i < len; i++)
	{
		if (a[min] >= a[i])
		{
			min = i;
		}
	}
}

void findMax(int*& a, int& len, int& max) // first max
{
	for (int i = 0; i < len; i++)
	{
		if (a[max] < a[i])
		{
			max = i;
		}
	}
}

void swapMinMax(int*& a, int& len, int& min, int& max)
{
	findMin(a, len, min);
	findMax(a, len, max);
	std::swap(a[min], a[max]);
}

void deleteDuplicates(int*& a, int& len)
{
	int index = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (a[i] == a[j])
			{
				index = j;
				deleteElement(a, len, index);
			}
		}
	}
}