/*
1. ��������� ���������� ���� � ������
2. ������� ����� ������� �����������.
3.����������� �������:
	strcat() - �������� �����
	strstr() - ����� ���������
	substr() - ��������� ���������
	strcmp() - ��������� �����
	strmult() - ��������� ������ �� ����� : "ba" * 3 == "bababa"*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>

/*char* strcpy(char* s1, const char* s2)
{
	for (int i = 0; i <= sizeof(s2); i++)
	{
		s1[i] = s2[i];
	}
	return s1;
}*/

int CountSize(char* filename)
{
	FILE* file = fopen(filename, "r");

	int len = 0;
	while (!feof(file))
	{
		char c = 0;
		fscanf_s(file, "%c", &c);
		len++;
	}
	len++;
	fclose(file);
	return len;
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

char* findLongestSentence(char* filename)
{
	FILE* file = fopen(filename, "r");
	int len = CountSize(filename);

	char* sentences = (char*)malloc(sizeof(char) * len);
	int i = 0;
	while (!feof(file))
	{
		fscanf_s(file, "%c", &sentences[i]);
		++i;
	}
	sentences[i + 1] = '\0';
	int ind1 = -1;
	int ind2 = 0;
	int len2 = 0;
	int maxlen = 0;
	for (int i = 0; i < len; ++i)
	{
		len2++;
		if ((sentences[i] == '.') || (sentences[i] == '?') || (sentences[i] == '!'))
		{
			if (len2 > maxlen)
			{
				maxlen = len2;
				ind1 = ind2;
				ind2 = i;
			}
			len2 = 0;
		}
	}

	fclose(file);
	return substr(sentences, ind1 + 1, ind2 - ind1 - 1);
}

//������� �� ��������
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
	char str[255];
	gets_s(str);
	fclose(f);

	f = fopen("out.txt", "w");
	char* name = new char[6] {'f', '.', 't', 'x', 't', '\0'};

	fprintf(f, "Count Words: %d\n", countWords(str));
	fscanf(f, "Count Words: %d\n", countWords(str));
	printf_s("%s \n", findLongestSentence(name));
	fscanf(f, "%s\n", countWords(str));

	fclose(f);
	return 0;
}