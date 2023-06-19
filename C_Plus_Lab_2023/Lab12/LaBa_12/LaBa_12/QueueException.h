#pragma once
#include "stdexcept"

using namespace std;
class StackEmptyException : public exception
{
public:
	StackEmptyException(const char* msg) : exception(msg)
	{
	}
};