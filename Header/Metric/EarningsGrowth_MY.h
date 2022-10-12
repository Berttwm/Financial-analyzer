#pragma once
#include "MetricMY.h"
/*
* EarningsGrowth_MY - MultiYear_EarningsGrowth
*
* Description: Year on year net earnings should be growing by 2.9%
*
* Categories used:
*	1) Multi
*	2) IncomeStatement
*
* Scoring:
*	High = 0 years below 2.9%
*	Med = 1 years below 2.9%
*	Low = 2 years below 2.9%
*	Fail = >2 years below 2.9%
*/

class EarningsGrowth_MY : public MetricMY<MetricType::EarningsGrowth_MY, CategoryType::Multi, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	EarningsGrowth_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};