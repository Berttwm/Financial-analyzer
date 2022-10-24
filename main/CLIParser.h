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

	void parse_stock_only();
	void parse_all_scoring();
	void parse_select_score();

};