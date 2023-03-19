#pragma once
#include <iostream>
#include <vector>
#include "../Header/Scorer.h"

using namespace std;

class Commands
{
protected:
	// limit maximum number of arguments per command
	const static int ARG_LIMIT = 10;
	std::vector<std::string> args;
	Scorer* scorer;


public:
	Commands(Scorer* scorer) : scorer(scorer) {}

	virtual void execute() {
		std::cout << std::endl << "COMMANDS PARENT EXECUTE." << std::endl;
	}

	void add_args(std::string input) {
		args.push_back(input);
	}
};