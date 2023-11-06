#include "bad_range.h"

bad_range::bad_range(int* data) : _data(data) {}

const char* bad_range::what() const noexcept
{
	if (_data == nullptr)
		return "ERROR: Trying to remove element from empty container";
	else
		return "ERROR: Out Of Range";
}