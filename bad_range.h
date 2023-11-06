#pragma once
#include <iostream>

class bad_range : public std::exception
{
public:
	bad_range(int*);

	virtual const char* what() const noexcept override;

private:
	int* _data;
};

