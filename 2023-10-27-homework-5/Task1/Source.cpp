#include<iostream>
#include"ArrayFunctions.h"

int main(int argc, char* argv[])
{
	int* a = nullptr;
	int len = 0;
	bool exit = false;
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			printArray(a, len);
		}
		int choice = 0;
		{
			std::cin >> choice;
		}
		{
			switch (choice)
			{
			case 0: // True
			{
				exit = true;
				break;
			}
			case 1: // True
			{
				printArray(a, len);
				system("pause");
				break;
			}
			case 2: // True
			{
				int element = 0;
				std::cout << "Input element to add : ";
				std::cin >> element;
				addElement(a, len, element);
				break;
			}
			case 3:
			{
				int index = 0;
				std::cout << "Input index to delete : ";
				std::cin >> index;
				std::cout << "Deleted  " << deleteElement(a, len, index) << std::endl;
				break;
			}
			case 4: // True
			{
				sortArray_ascending(a, len);
				break;
			}
			case 5: // True
			{
				printReverseArray(a, len);
				break;
			}
			case 6: // True
			{
				int min = 0;
				int max = 0;
				swapMinMax(a, len, min, max);
				break;
			}
			case 7:
			{
				deleteDuplicates(a, len);
				break;
			}
			case 8: // True
			{
				int n = 0;
				std::cout << "How many elements to add: ";
				std::cin >> n;
				add_n_Elements(a, len, n);
				break;
			}
			default:
				std::cout << "Unknown command" << std::endl;
				break;
			}
		}
	}
	return 0;
}