#pragma once

#include "ScorerUtils.h"
#include "Stock.h"

// Include statements for metrics to be scored
#include "Metric/GrossProfitMargin_SY.h"

/* To take in a stock object and provide interface for scoring system */
class Scorer
{
private:
	// Fixed variables
	const int MAX_SCORE = 10; // TODO: Change Max Score
	int CURR_SCORE = 0; // initial score
	
	// Derived variables
	const Stock& stock;

	// Scoring variables
	std::unordered_map<CategoryType, int> CategoryScores = // Score of each CategoryType, each category starts from 0
	{
		{CategoryType::Single, 0},
		{CategoryType::Multi, 0},
		{CategoryType::IncomeStatement, 0},
		{CategoryType::BalanceSheet, 0},
		{CategoryType::CashFlow , 0}
	};
	std::unordered_map<MetricType, int> MetricScores = // Score of each SheetType, each starts from 0
	{
		{MetricType::GrossProfitMargin, 0},
	};
	std::unordered_map<CategoryType, int> MaxCategoryScores = // Max scores of each category. Incremented by 10 each time a category is added
	{
		{CategoryType::Single, 0},
		{CategoryType::Multi, 0},
		{CategoryType::IncomeStatement, 0},
		{CategoryType::BalanceSheet, 0},
		{CategoryType::CashFlow , 0}
	};
	std::unordered_map<MetricType, int> MaxMetricScores = // Max scores of each category. Incremented by 10 each time a category is added
	{
		{MetricType::GrossProfitMargin, 0},
	};

	// process a current year score metrics. 
	void process();

	// process a multi year score metrics for `num_years`, or maximum recorded duration (whichever is lower). 
	//void process(const int num_years);


public:
	Scorer(const Stock &stock);

};