#pragma once
#include "MetricMY.h"
/*
* ShortLongTermDebtRatio_MY - MultiYear_ShortTermLongTermDebtRatio
*
* Description: Short term to Long term debt ratio year on year. Indication of how leveraged a company is. Durable companies tend to have a lower ratio. No need for leveraged operations.
* 
*
* Categories used:
*	1) Multi
*	2) BalanceSheet
*
* Scoring:
*	High = 0 years > 100%
*	Med = 1 years > 100%
*	Low = 2 years > 100%
*	Fail = 3 years > 100%
*/

class ShortLongTermDebtRatio_MY : public MetricMY<MetricType::ShortLongTermDebtRatio_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	ShortLongTermDebtRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};