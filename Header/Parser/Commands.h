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
	Scorer* scorer;


public:
	std::vector<std::string> args;

	Commands(Scorer* scorer) : scorer(scorer) {
		args.reserve(ARG_LIMIT);
	}

	virtual void execute() {
		std::cout << std::endl << "COMMANDS PARENT EXECUTE." << std::endl;
	}

	void add_args(std::string input) {
		std::cout << "********* ADDing ARGS IN COMMANDS " << input << " ===================" << std::endl;
		std::string arg(input);
		std::cout << "********* ADDing ARGS IN COMMANDS " << " ===================" << std::endl;
		args.push_back(input);
		std::cout << "=============== ADDED ARGS IN COMMANDS " << " ===================" << std::endl;
	}
};