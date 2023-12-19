/*
1. Посчитать количество слов в тексте
2. Вывести самое длинное предложение.
3.Реализовать функции:
	strcat() - сложение строк
	strstr() - поиск подстроки
	substr() - выделение подстроки
	strcmp() - сравнение строк
	strmult() - умножение строки на число : "ba" * 3 == "bababa"*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>

bool isLetter(char c)
{
	return (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я') ||
		(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isSyntax(char c)
{
	return (c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?');
}

/*char* strcpy(char* s1, const char* s2)
{
	for (int i = 0; i <= sizeof(s2); i++)
	{
		s1[i] = s2[i];
	}
	return s1;
}*/

void ReadLines(char* filename, char** lines, int maxlen)
{
	FILE* file = fopen(filename, "r");

	int ind = 0;
	while (!feof(file))
	{
		fgets(lines[ind], maxlen, file);
		ind++;
	}

	fclose(file);
}

void CountSize(char* filename, int& lines)
{
	FILE* file = fopen(filename, "r");

	int currentLen = 0;
	while (!feof(file))
	{
		char c = 0;
		fscanf_s(file, "%c", &c);
		if (c == '\n')
		{
			lines++;
			currentLen = 0;
		}
		else
		{
			currentLen++;
		}
	}
	lines++;
	fclose(file);
}
//
int countWords(char* text)
{
	int cnt = 0;
	int len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
		{
			cnt++;
		}
	}
	return cnt;
}

void findLongestSentence(char* filename)
{
	FILE* f = fopen(filename, "r");
	char* str = 0;

	int len = 0;
	CountSize(filename, len);
	int maxlen = 0;

	char* sent = (char*)malloc(sizeof(char) * len);
	int i = 0;
	while (!feof(f))
	{
		fscanf_s(f, "%c", &sent[i]);
		i++;
	}


	fclose(f);

	return  substr(sent, ind1, ind2);
}

//функции со строками
int strlen(char* str)
{
	int res = 0;
	while (str[res++] != '\0');
	return res;
}

char* strcat(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len = len1 + len2;
	char* str = (char*)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
	{
		str[i] = str1[i];
	}
	for (int i = 0; i < len; i++)
	{
		str[i] = str1[i];
	}
	str[len + 1] = '\0';
	return str;
}

int strstr(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int ind = 0;
	bool Check = false;
	for (int i = 0; i < len1; ++i)
	{
		if (str1[i] == str2[0])
		{
			Check = true;
			ind = i;
			int n = 1;
			for (int j = i + 1; j < i + len2; ++j)
			{
				Check = Check && (str1[j] == str2[n]);
				n++;
			}
			if (Check)
			{
				return ind;
			}
		}
	}
	return;
}

char* substr(char* str, int from, int sublen)
{
	int len = strlen(str);
	char* substr = (char*)malloc(sizeof(char) * (sublen + 2));
	for (int i = 0; i < sublen + 1; ++i)
	{
		substr[i] = str[from + i];
	}
	substr[sublen + 1] = '\0';
	return substr;
}

int strcmp(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; (i < len1) && (i < len2); ++i)
	{
		if (str1[i] != str2[i])
		{
			return ((int)str1[i] - (int)str2[i]);
		}
	}
	return 0;
}

char* strmult(char* str, int t)
{
	char test[255] = "";
	strcpy(test, str);
	while (t > 0)
	{
		strcat(str, test);
		t--;
	}
	return str;
}


int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");
	f = fopen("out.txt", "a");
	char str[255];
	gets_s(str);
	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "Count Words: %d\n", countWords(str));
	fclose(f);

	return 0;
}

char* maxsentence(char* filename)
{
	FILE* file = fopen(filename, "r");
	int len = CountSize(filename);

	char* sentences = (char*)malloc(sizeof(char) * len);
	int i = 0;
	while (!feof(file))
	{
		fscanf_s(file, "%c", &sentences[i]);
		i++;
	}

	int ind1 = 0;
	int ind2 = 0;
	int len2 = 0;
	int maxlen = 0;
	for (int i = 0; i < len; ++i)
	{
		len2++;
		if (sentences[i] == '.'  sentences[i] == '?'  sentences[i] == '!')
		{
			if (len2 > maxlen)
			{
				maxlen = (maxlen < len2 ? len2 : maxlen);
				ind1 = ind2 + 1;
				ind2 = i;
				len2 = 0; 
			}
		} 
	}

	fclose(file);
	return Substr(sentences, ind1, maxlen);
}
