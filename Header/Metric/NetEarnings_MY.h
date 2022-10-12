#pragma once
#include "MetricMY.h"
/*
* NetEarnings_MY - MultiYear_NetEarnings
*
* Description: (Historical upward trend, not necessarily year on year) of
*	Net Earnings.
*
* Categories used:
*	1) Multi
*	2) IncomeStatement
*
* Scoring:
*	High = 0 
*	Med = 1 dip
*	Low = 2 dip
*	Fail = >2 dip
*/

class NetEarnings_MY : public MetricMY<MetricType::NetEarnings_MY, CategoryType::Multi, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	NetEarnings_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};