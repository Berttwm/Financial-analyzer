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

};