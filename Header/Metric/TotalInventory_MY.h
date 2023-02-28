#pragma once
#include "MetricMY.h"
/*
* TotalInventory_MY - MultiYear_TotalInventory
*
* Description: Consistently rising, if rises fast and fast drop implies field they are competing in is too competitive
*
* Categories used:
*	1) Multi
*	2) BalanceSheet
*
* Scoring:
*	High = 0 years fall by >30%
*	Med = 1 years fall by >30%
*	Low = 2 years fall by >30%
*	Fail = 3+ years fall by >30%
*/

class TotalInventory_MY : public MetricMY<MetricType::TotalInventory_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	TotalInventory_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};