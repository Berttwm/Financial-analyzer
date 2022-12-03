#pragma once
#include <iostream>

using namespace std;

class FAException : public std::exception
{

private:
	const char* message;

public:
	FAException(char* msg) : message(msg) {}

	const char* error() {
		return message;
	}
};