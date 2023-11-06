#include "bad_length.h"

bad_length::bad_length(int length) : _length(length) {}

const char* bad_length::what() const noexcept
{
	return "ERROR: Wrong Value Of Length";
}