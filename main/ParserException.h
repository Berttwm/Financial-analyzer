#pragma once
#include <iostream>
#include <stdio.h>
#include "FAException.h"

using namespace std;

class ParserException : public FAException
{

public:
	ParserException(std::string msg) : FAException("[Parser Exception Error]: " + msg) {}

};