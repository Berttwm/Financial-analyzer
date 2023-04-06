#pragma once
#include <algorithm>

#include "../Header/Scorer.h"

class CLIParser
{
public:
	// Constructor for CLI
	CLIParser(int num_args, char** argv);
	void parse_input();

private:
	const int num_args;
	char** argv;

	Scorer* get_scorer();

};
