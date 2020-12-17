#pragma once
#include <iomanip>
#include <iostream>
#include <locale>
using namespace std;
class Array
{
	int* array;
	int len;

public:
	Array(int arrl) // constructor of int array
	{
		array = new int[arrl];
		len = arrl;
	}
	~Array() // destructor of int array
	{
		delete[] array;
		cout << "\ndestructor finished his work" << endl;
	}
	void fill(int);
	int getelem(int);
	void bogosorting();
	void shuffle();
	int correct();
	void quicksorting(int, int);
	void bubblesorting();
	void binarysearching(int);
};


class Char_Array
{
	char* array;
	int len;

public:
	Char_Array(int arrl) // constructor of char array
	{
		array = new char[arrl];
		len = arrl;
	}
	~Char_Array() // destructor of char array
	{
		delete[] array;
		cout << "\ndestructor finished his work" << endl;
	}
	void countingsorting();
	void fill(int);
	char getelem(int ind);
};