#pragma once
#include "MetricMY.h"
/*
* SGA_MY - MultiYear_DebtRatio
*
* Description: Year on year debt to cash ratio
*	Look at past 7 years of balance sheets, this will reveal if cash was generated in a one time event
*
* Categories used:
*	1) Multi
*	2) BalanceSheet
*
* Scoring:
*	High = Debt:Cash Ratio < 30% for all years
*	Med = Debt:Cash Ratio < 30% for all years (with 1 spike)
*	Low = Debt:Cash Ratio < 30% for all years (with 2 spike)
*	Fail = Debt:Cash Ratio < 30% for all years (with >2 spike)
*/

class DebtRatio_MY : public MetricMY<MetricType::DebtRatio_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	DebtRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double> *MetricPerformances, int year_count);
};