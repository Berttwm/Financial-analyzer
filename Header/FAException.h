#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;

class FAException : public std::exception
{

protected:
	std::string message;

public:
	FAException(std::string msg) : message(msg) {}

	std::string what()
	{

		return message;
	}
};