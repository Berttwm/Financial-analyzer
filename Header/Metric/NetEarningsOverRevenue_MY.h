#pragma once
#include "MetricMY.h"
/*
* NetEarningsOverRevenue_MY - MultiYear_NetEarningsOverRevenue
*
* Description: Year on year net earnings/total revenue. >10% consistently
*
* Categories used:
*	1) Multi
*	2) IncomeStatement
*
* Scoring:
*	High = 0 dip
*	Med = 1 dip
*	Low = 2 dip
*	Fail = >2 dip
*/

class NetEarningsOverRevenue_MY : public MetricMY<MetricType::NetEarningsOverRevenue_MY, CategoryType::Multi, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	NetEarningsOverRevenue_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};