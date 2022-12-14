#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;

class ParserException : public std::exception
{

private:
	std::string message;

public:
	ParserException(std::string msg) : message(msg) {}

	std::string what()
	{

		return std::string("[Parser Exception Error]: ") + message;
	}
};