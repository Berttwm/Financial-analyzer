#pragma once

#include "ScorerUtils.h"
#include "Stock.h"

/* To take in a stock object and provide interface for scoring system */
class Scorer
{
private:
	// Fixed variables
	const int MAX_SCORE = 0; // TODO: Change Max Score
	int CURR_SCORE = 0; // initial score
	
	// Derived variables
	const Stock& stock;
	const int stock_data_years; // number of years of data available for the passed `Stock` object

	// variables
	std::unordered_map<SheetType, int> SheetTypeScore = // Score of each SheetType, each starts from 0
	{
		{SheetType::IncomeStatement, 0},
		{SheetType::BalanceSheet, 0},
		{SheetType::CashFlow , 0}
	};


	// process a current year score metrics. 
	void process();

	// process a multi year score metrics for `num_years`, or maximum recorded duration (whichever is lower). 
	//void process(const int num_years);


public:
	Scorer(const Stock &stock);

};