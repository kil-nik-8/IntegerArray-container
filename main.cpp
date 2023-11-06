#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
	IntegerArray a;
	a.setLength(5);
	for (int i = 0; i < 5; i++)
	{
		a[i] = i;
	}
	a.push_back(10);
	cout << a.getLength() << endl;
	a.push_front(10);
	cout << a.getLength() << endl;
	a.pop_front();
	cout << a.getLength() << endl;
	a.pop_back();
	cout << a.getLength() << endl;
	a.setLength(3);
	cout << a.getLength() << endl;
	IntegerArray b;
	b = a;
	b.insertBefore(10, 1);
	cout << "Integer Array: ";
	for (int i = 0; i < b.getLength(); i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	cout << "Is in Integer Array 10 (1 - true, 0 - false): " << b.find(10) << endl;
	cout << "Is in Integer Array -10 (1 - true, 0 - false): " << b.find(-10) << endl;
	b.erase();
	cout << "Length of Integer Array after erase: " << b.getLength() << endl;
	try 
	{
		IntegerArray b(-5);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		IntegerArray b(0);
		b.pop_front();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		IntegerArray b(0);
		b.pop_back();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		IntegerArray b(5);
		b.insertBefore(1, -1);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		IntegerArray b(5);
		b.insertBefore(1, 2);
		b.setLength(-5);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		IntegerArray b(5);
		b.getElement(6);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}