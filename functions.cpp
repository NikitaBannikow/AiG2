#include <iomanip>
#include <iostream>
#include <locale>
#include <chrono>
#include <cstdlib>
#include "Header.h"
using namespace std;

void Array::fill(int ind) //fill of the array
{
	int temp;
	for (int i = 0; i < len; i++)
	{
		temp = rand() % 2;
		if (temp == 0)
		{
			array[i] = (rand() % 10) * (-1);
		}
		else
			array[i] = rand() % 10;
	}
}

void Char_Array::fill(int ind) //fill of the char array
{
	for (int i = 0; i < len; i++)
	{
		array[i] = rand() % 10 + '0';
	}
}

int Array::getelem(int ind) //Getting the value of array
{
	return array[ind];
}

char Char_Array::getelem(int ind) //Getting the value of char array
{
	return array[ind];
}

int Array::correct()  //Part of bogosorting
{
	int len2 = len;
	while (--len2 > 0)
		if (array[len2 - 1] > array[len2])
			return 0;
	return 1;
}

void Array::shuffle() //Part of bogosorting
{
	for (int i = 0; i < len; ++i)
		swap(array[i], array[(rand() % len)]);
}

void Array::bogosorting()
{
	while (!correct())
		shuffle();
}

void Array::quicksorting(int initial, int final) //quicksorting
{
	int mid, count;
	int f = initial, l = final;
	mid = array[(f + l) / 2];
	do
	{
		while (array[f] < mid) f++;
		while (array[l] > mid) l--;
		if (f <= l)
		{
			count = array[f];
			array[f] = array[l];
			array[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (initial < l) quicksorting(initial, l);
	if (f < final) quicksorting(f, final);
}

void Array::bubblesorting() //bubblesorting
{
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

void Array::binarysearching(int key) //binarysearching
{
	bool flag = false;
	int l = 0;
	int r = len - 1;
	int mid;
	while ((l <= r) && (flag != true))
	{
		mid = (l + r) / 2;
		if (array[mid] == key) flag = true;
		if (array[mid] > key) r = mid - 1;
		else l = mid + 1;
	}
	if (flag) cout << "ind of element " << key << " in array is equal to: " << mid;
	else cout << "Sorry, but there is no such an element in array";
}

void Char_Array::countingsorting() //Counting sort
{
	int* output = new int[len];
	int* count = new int[len];
	int max = 0;
	int temp = 0;
	for (int i = 1; i < len; i++)
	{
		temp = array[i] - '0';
		if (temp > max)
		{
			max = temp;
		}
	}
	for (int i = 0; i <= max; ++i)
	{
		count[i] = 0;
	}
	for (int i = 0; i < len; i++)
	{
		count[array[i] - '0']++;
	}
	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = len - 1; i >= 0; i--)
	{
		output[count[array[i] - '0'] - 1] = array[i] - '0';
		count[array[i] - '0']--;
	}
	for (int i = 0; i < len; i++)
	{
		array[i] = output[i] + '0';
	}

	delete[] output;
	delete[] count;

}
