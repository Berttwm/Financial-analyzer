#pragma once
#include <iostream>
#include <vector>

#include "Commands.h"

class ParseHelpCmd : public Commands
{
public:
	// Constructor for ParseHelpCmd
	ParseHelpCmd(Scorer* scorer);

	void execute() override;

	void add_prev_cmd(Commands*);

private:
	Commands* prev_cmd;
};


