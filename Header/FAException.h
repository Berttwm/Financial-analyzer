#pragma once
#include <iostream>

using namespace std;

class FAException : public std::exception
{
private:
	std::string default_msg = "Type '--help' for more information.";

protected:
	std::string message;

public:
	FAException(std::string msg) : message(msg) {}

	std::string what()
	{
		std::cout << message << std::endl;
		return default_msg;
	}
};