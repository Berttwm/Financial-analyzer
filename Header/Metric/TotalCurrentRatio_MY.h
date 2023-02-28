#pragma once
#include "MetricMY.h"
/*
* TotalCurrentRatio_MY - MultiYear_TotalCurrentRatio
*
* Description: Good if current ratio consistently is between above 2
*
* Categories used:
*	1) Multi
*	2) BalanceSheet
*
* Scoring:
*	High = 0 years below 1.2
*	Med = 1 years below 1.2
*	Low = 2 years below 1.2
*	Fail = 3+ years below 1.2
*/

class TotalCurrentRatio_MY : public MetricMY<MetricType::TotalCurrentRatio_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	TotalCurrentRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};