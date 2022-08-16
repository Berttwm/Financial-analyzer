#pragma once

#include "ScorerUtils.h"
#include "Stock.h"

class Scorer
{
private:
	// Fixed variables
	const int MAX_SCORE = 0; // TODO: Change Max Score
	int CURR_SCORE = 0; // initial score
	
	// Derived variables
	Stock* stock;
	const int stock_data_years; // number of years of data available for the passed `Stock` object
	// process a current year score metrics. 
	void process(CurrentYearScorerMetrics);

	// process a year on year score metrics for `num_years` (or maximum recorded duration). 
	void process(YearOnYearScorerMetrics, const int num_years);
public:
	Scorer(Stock *stock);

};