#pragma once
#include "MetricMY.h"
/*
* NegativeEarnings_MY - MultiYear_NegativeEarnings
*
* Description: Year on year there should be no negative earnings
*
* Categories used:
*	1) Multi
*	2) IncomeStatement
*
* Scoring:
*	High = 0 negative earnings
*	Med = 1 negative earnings
*	Low = 2 negative earnings
*	Fail = >2 negative earnings
*/

class NegativeEarnings_MY : public MetricMY<MetricType::NegativeEarnings_MY, CategoryType::Multi, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	NegativeEarnings_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};