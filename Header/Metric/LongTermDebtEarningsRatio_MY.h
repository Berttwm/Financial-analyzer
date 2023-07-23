#pragma once
#include "MetricMY.h"
/*
* LongTermDebtEarningsRatio_MY - MultiYear_LongTermDebtToEarningsRatio
*
* Description: LongTermDebt to Earnings Ratio should be consistently <3 over 10 years
*	This shows that the company is able to pay back its long term debt within 3 years
*
* Categories used:
*	1) Multi
*	2) BalanceSheet
*
* Scoring:
*	High = 0 failed years
*	Med = 1 failed years
*	Low = 2 failed years
*	Fail = >2 failed years
*/

class LongTermDebtEarningsRatio_MY : public MetricMY<MetricType::LongTermDebtEarningsRatio_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	LongTermDebtEarningsRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};
