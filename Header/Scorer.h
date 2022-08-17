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
	Stock& stock;
	const int stock_data_years; // number of years of data available for the passed `Stock` object

	// process a current year score metrics. 
	void process(SingleYearIncomeStmtMetrics);

	// process a multi year score metrics for `num_years`, or maximum recorded duration (whichever is lower). 
	void process(MultiYearIncomeStmtMetrics, const int num_years);

	// process a current year score metrics. 
	void process(SingleYearBalanceSheetMetrics);

	// process a multi year score metrics for `num_years`, or maximum recorded duration (whichever is lower). 
	void process(MultiYearBalanceSheetMetrics, const int num_years);

	// process a current year score metrics. 
	void process(SingleYearCashFlowMetrics);

	// process a multi year score metrics for `num_years`, or maximum recorded duration (whichever is lower). 
	void process(MultiYearCashFlowMetrics, const int num_years);


public:
	Scorer(Stock &stock);

};