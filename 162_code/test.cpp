#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

char charCounter(char array[], const int);
void test();

int main()
{
	const int VAL = 15;
	char array[VAL];
	//charCounter(array, VAL);
	test();

}

char charCounter(char array[], const int)
{
	int x = 0;
	cin >> array;

	while (array[x] != '\0')
	{

		cout << array[x];
		x++;
		cout << x << endl;

	}

	return x;
}

void test()
{
	int i=0,e=0,t=0,a1=0,a2=0;
	char check[6] = { 'a','b','c','d','e','f' };
	char letters[6];
	cin.get(letters,6,'\n');
	cin.ignore(100, '\n');
	while (i < 6)
	{
		if (letters[0] != check[t] & letters[5] !=check[e])
		{
			cout << " " << endl;

		}
		else
		{
			cout << "Found it" << endl;
			a1 = a1 + t;
			a2 = a2 + e;
			cout << a2 << endl;
			/*cout << a1 << endl;
			cout << "It does have one of these letters" << endl;*/
		}
		
		t++;// for the first letter
		e++;// The last letter
		i++;
	}
	if (a1 < a2)
	{
		swap(letters[0], letters[5]);
		cout << letters << endl;
		cout << a1 << " " << a2 << endl;

	}
	else
	{
		cout << "Code failed sad face" << endl;
		cout << a1 << " " << a2 << endl;
		swap(letters[0], letters[5]);
		cout << letters << endl;
	}

}