#pragma once
#include <iostream>
#include <vector>

#include "Commands.h"

class ParseCategoryCmd : public Commands
{
public:
	// Constructor for ParseCategoryCmd
	ParseCategoryCmd(Scorer* scorer);

	void execute() override;

	void get_help() override;
};