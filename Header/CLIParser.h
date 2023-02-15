#pragma once
#include <cpr/cpr.h>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
//#include "CLI/App.hpp"
//#include "CLI/Formatter.hpp"
//#include "CLI/Config.hpp"

class CLIParser
{
public:
	// Constructor for CLI
	CLIParser(int num_args, char** argv);
	void parse_input();

private:
	const int num_args;
	char** argv;

	void parse_entire_stock();
	void parse_whole_category();
	void parse_specified_category();

};