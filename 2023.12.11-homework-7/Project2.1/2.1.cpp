#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
/*Ќайти самое часто встречающеес€ слово*/

bool isSyntax(char c)
{
	return (c == '.' || c == '?' || c == '!' || c == ',' ||c == ';' || c == ':');
}

void Syntax(std::string* word, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < word[i].length(); ++j)
		{
			if (isSyntax(word[i][j]))
			{
				word[i].erase(j, 1);
			}
		}
	}
}

std::string mostCommonWord(std::string* WordArr, int cntWord)
{
	std::string common = WordArr[0];
	int repeatCnt = 0;

	for (int i = 0; i < cntWord; ++i)
	{
		int repeat = 0;
		for (int j = i; j < cntWord; ++j)
		{
			if (WordArr[i] == WordArr[j])
			{
				++repeat;
			}
		}
		if (repeat > repeatCnt)
		{
			repeatCnt = repeat;
			common = WordArr[i];
		}
	}
	return common;
}

int countWord(std::string file)
{
	std::ifstream fin(file);
	int t = 0;
	std::string word = "";
	while (!fin.eof())
	{
		fin >> word;
		++t;
	}
	fin.close();
	return t;
}

void wordArray(std::string file, std::string* WordArr)
{
	std::ifstream fin(file);

	int i = 0;
	while (!fin.eof())
	{
		fin >> WordArr[i];
		++i;
	}
	fin.close();
}

int main(int argc, char* argv[])
{
	int n = countWord("in.txt");;
	std::string* WordArr = new std::string[n];

	wordArray("in.txt", WordArr);
	Syntax(WordArr, n);

	std::ofstream fout("out.txt");
	fout << "Most Common word: " << mostCommonWord(WordArr, n) << std::endl;
	fout.close();

	return 0;
}