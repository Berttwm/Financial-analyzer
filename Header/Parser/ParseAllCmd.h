#pragma once
#include <iostream>
#include <vector>

#include "Commands.h"

class ParseAllCmd : public Commands
{
public:
	// Constructor for ParseMetricCmd
	ParseAllCmd(Scorer* scorer);

	void execute() override;

private:
	void get_category_scores(Scorer* scorer);
	void get_max_category_scores(Scorer* scorer);
	void get_metrics_performances(Scorer* scorer);
	void get_metric_scores(Scorer* scorer);
	void get_max_metric_scores(Scorer* scorer);

};

