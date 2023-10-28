#pragma once
#include<iostream>

void printMenu();
void printArray(int* a, int len);
void expandArray(int*& a, int& len);
void addElement(int*& a, int& len, int element);
void contractArray(int*& a, int& len);
bool indexValid(int index, int len);
int deleteElement(int*& a, int& len, int index);
void printReverseArray(int* a, int len);
void add_n_Elements(int*& a, int& len, int n);
void sortArray_ascending(int*& a, int& len);
void deleteDuplicates(int*& a, int& len);
void swapMinMax(int*& a, int& len, int& min, int& max);
void findMax(int*& a, int& len, int& max);
void findMin(int*& a, int& len, int& min);