#pragma once
#include "MetricMY.h"
/*
* Goodwill_MY - MultiYear_Goodwill
*
* Description: Good if increasing year on year goodwill. Increasing goodwill over years imply more acquisitions.
*	Goodwill - Price excess from value in acquiring companies vs price actually paid
*
* Categories used:
*	1) Multi
*	2) BalanceSheet
*
* Scoring:
*	High = 0 years dip
*	Med = 1 years dip
*	Low = 2 years dip
*	Fail = 3+ years dip
*/

class Goodwill_MY : public MetricMY<MetricType::Goodwill_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	Goodwill_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};