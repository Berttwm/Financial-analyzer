#pragma once
#include <iostream>
#include <stdio.h>
#include "FAException.h"

using namespace std;

class InputException : public FAException
{

public:
	InputException(std::string msg) : FAException("[Input Exception Error]: " + msg) {}

};