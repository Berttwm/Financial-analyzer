#pragma once
#include <cpr/cpr.h>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "../Header/Scorer.h"

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

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

	void parse_entire_stock();
	void parse_whole_category();
	void parse_specified_category();

	void get_metrics_performances(Scorer*, std::string = "");
	void get_category_scores(Scorer*, std::string = "");
	void get_metric_scores(Scorer*);
	void get_max_category_scores(Scorer*);
	void get_max_metric_scores(Scorer*);


};