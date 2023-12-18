#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

bool isPalindrom(std::string str)
{
	for (int i = 0; i < str.length() / 2; ++i)
	{
		if (str[i] != str[str.size() - 1 - i])
		{
			return false;
			break;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");

	std::string str = "";
	std::getline(fin, str);

	if (isPalindrom(str))
	{
		std::cout << "It's polindrom" << std::endl;
		fout << "It's polindrom \n" << std::endl;
	}
	else
	{
		printf("It's not polindrom \n");
		fout << "It's not polindrom \n" << std::endl;
	}

	fin.close();
	fout.close();

	return 0;
}