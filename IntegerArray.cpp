#include "IntegerArray.h"
#include "bad_range.h"
#include "bad_length.h"

IntegerArray::IntegerArray()
{
	_length = 0;
	_data = nullptr;
}

IntegerArray::IntegerArray(int length)
{
	_length = length;
	_data = nullptr;
	if (length < 0)
	{
		throw bad_length(length);
	}

	if (length > 0)
	{
		_length = length;
		_data = new int[length] {};
	}
}

IntegerArray::IntegerArray(const IntegerArray& copy)
{
	_length = copy._length;
	_data = nullptr;

	if (copy._length < 0)
		throw bad_length(copy._length);

	if (copy._length > 0)
	_data = copy._data;
}

IntegerArray::~IntegerArray()
{
	delete[] _data;
}

int IntegerArray::getElement(int index) const
{
	if (index < 0 || index >= _length)
		throw bad_range(_data + index);

		return _data[index];
}

void IntegerArray::insertBefore(int value, int index)
{
	if (index < 0 || index > _length)
	{
		throw bad_range(_data + index);
	}

	int* data = new int[_length + 1] {};

	for (int i = 0; i < index; i++)
	{
		data[i] = _data[i];
	}

	data[index] = value;

	for (int i = index + 1; i < _length + 1; i++)
	{
		data[i] = _data[i - 1];
	}

	delete[] _data;

	_data = data;
	++_length;
}

void IntegerArray::push_front(int value) { insertBefore(value, 0); }
void IntegerArray::push_back(int value) { insertBefore(value, _length); }

void IntegerArray::setLength(int length)
{
	if (length < 0)
		throw bad_length(length);

	if (length == _length)
	{
		return;
	}

	int* data;

	if (length == 0)
	{
		erase();
		return;
	}
	else
		data = new int[length] {};

	int copyCount{ (length > _length) ? _length : length };

	for (int i = 0; i < copyCount; i++)
	{
		data[i] = _data[i];
	}

	delete[] _data;

	_data = data;
	_length = length;
}

void IntegerArray::remove(int index)
{
	if (index < 0 || index >= _length)
	{
		throw bad_range(_data + index);
	}

	int* data = new int[_length - 1];

	for (int i = 0; i < index; i++)
	{
		data[i] = _data[i];
	}
	for (int i = index; i < _length - 1; i++)
	{
		data[i] = _data[i + 1];
	}

	delete[] _data;
	_data = data;
	_length--;
}

void IntegerArray::pop_front() { remove(0); }
void IntegerArray::pop_back() { remove(_length - 1); }

int IntegerArray::getLength() const { return _length; }

int& IntegerArray::operator[](int index)
{
	if (index < 0 || index > _length)
		throw bad_range(_data + index);

	return _data[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a)
{
	if (&a == this)
		return *this;

	if (a._length < 0)
		throw bad_length(a._length);

	erase();

	if (a._length > 0)
	{
		this->_data = new int[a._length];
		this->_length = a._length;
	}
	
	for (int i = 0; i < a._length; i++)
	{
		_data[i] = a._data[i];
	}

	return *this;
}

bool IntegerArray::find(int value) const
{
	for (int i = 0; i < _length; i++)
	{
		if (_data[i] == value)
		{
			return true;
		}
	}
	return false;
}

void IntegerArray::erase()
{
	delete[] _data;
	_data = nullptr;
	_length = 0;
}