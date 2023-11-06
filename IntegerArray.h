#pragma once
#include <iostream>

class IntegerArray : public std::exception
{
public:

	IntegerArray();
	IntegerArray(int);

	IntegerArray(const IntegerArray&);

	int getElement(int) const;
	void setLength(int);
	void insertBefore(int, int);
	void push_front(int);
	void push_back(int);
	void remove(int);
	void pop_front();
	void pop_back();
	int getLength() const;
	bool find(int) const;
	void erase();

	int& operator[](int);
	IntegerArray& operator=(const IntegerArray&);

	~IntegerArray();

private:
	int _length{};
	int* _data{};
};

