#pragma once
#include "MetricMY.h"
/*
* PreferredStock_MY - MultiYear_PreferredStock
*
Checking for presence of preferred stock on balance sheet over multiple years
*	Absence of preferred stock means durable company
*
* Categories used:
*	1) Multi
*	2) BalanceSheet
*
* Scoring:
*	High = 0 years > 0
*	Med = <= 1 years > 0
*	Low = <= 2 years > 0
*	Fail = > 2 years > 0
*/

class PreferredStock_MY : public MetricMY<MetricType::PreferredStock_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	PreferredStock_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};