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

	void parse_entire_stock();

	void get_metrics_performances(Scorer*, std::string = "");
	void get_category_scores(Scorer*, std::string = "");
	void get_metric_scores(Scorer*);
	void get_max_category_scores(Scorer*);
	void get_max_metric_scores(Scorer*);


};