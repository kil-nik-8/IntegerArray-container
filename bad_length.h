#pragma once
#include <iostream>

class bad_length : public std::exception
{
public:
	bad_length(int);

	virtual const char* what() const noexcept override;

private:
	int _length;
};

