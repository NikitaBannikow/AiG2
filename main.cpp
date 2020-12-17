#include "Header.h"
#include <iomanip>
#include <iostream>
#include <locale>
#include <chrono>
#include <cstdlib>

using namespace std;
int main()
{
	/*for (int i = 0; i < 10; i++)
	{
		int arrl = 100;
		Array arr(arrl);
		arr.fill();
		chrono::system_clock::time_point start = chrono::system_clock::now();
		arr.bubblesorting();
		chrono::system_clock::time_point end = chrono::system_clock::now();
		chrono::duration<double> sec = end - start;
		cout << "the execution time of the function is " << sec.count() << " seconds" << endl;
		cout << endl;
	}*/
	Begin:
	int arrl;
	cout << "Fill in the size of arrays" << endl;
	cin >> arrl;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	if (arrl < 1)
	{
		cout << "Wrong arrays len" << endl; //Exception
		goto Begin;
	}
	Array arr(arrl);
	arr.fill(arrl);
	Char_Array arrc(arrl);
	arrc.fill(arrl);
	cout << "Array after filing:" << endl;
	for (int i = 0; i < arrl; i++)
	{
		cout << arr.getelem(i) << " ";
	}
	cout << endl;
	cout << "Char array after filing:" << endl;
	for (int i = 0; i < arrl; i++)
	{
		cout << arrc.getelem(i) << " ";
	}
	cout << endl;
	while (true)
	{
	Choosing:
		cout << "-------------------------------------\n";
		cout << "Choose action (write 1 to 7 number):\n";
		cout << "1. binarysearching (int)\n"
			<< "2. quicksorting (int)\n"
			<< "3. bubblesorting (int)\n"
			<< "4. bogosorting (int)\n"
			<< "5. countingsorting (char)\n"
			<< "6. refill the arrays\n"
			<< "7. close the program\n";
		cout << "-------------------------------------\n";
		int issue;
		cin >> issue;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		switch (issue)
		{
		case 1:
		{
			cout << "Enter the searching number\n";
			int key;
			cin >> key;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			arr.binarysearching(key);
			goto Choosing;
		}
		case 2:
		{
			int initial = 0;
			int final = arrl - 1;
			arr.quicksorting(initial, final);
			cout << "Array after quicksorting:" << endl;
			for (int i = 0; i < arrl; i++)
			{
				cout << arr.getelem(i) << " ";
			}
			cout << endl;
			goto Choosing;
		}
		case 3:
		{
			arr.bubblesorting();
			cout << "Array after bubblesorting:" << endl;
			for (int i = 0; i < arrl; i++)
			{
				cout << arr.getelem(i) << " ";
			}
			cout << endl;
			goto Choosing;
		}
		case 4:
		{
			arr.bogosorting();
			cout << "Array after bogosorting:" << endl;
			for (int i = 0; i < arrl; i++)
			{
				cout << arr.getelem(i) << " ";
			}
			cout << endl;
			goto Choosing;
		}
		case 5:
		{
			arrc.countingsorting();
			cout << "Array after countingsorting:" << endl;
			for (int i = 0; i < arrl; i++)
			{
				cout << arrc.getelem(i) << " ";
			}
			cout << endl;
			goto Choosing;
		}
		case 6:
		{
			goto Begin;
		}
		case 7:
		{
			goto End;
		}
		default:
		{
			cout << "Error. Enter the number 1 to 7" << endl; //Exception
			goto Choosing;
		}
		}
	}
End:
	cout;
}
