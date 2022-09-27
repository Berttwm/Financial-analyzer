#pragma once
#include "MetricSY.h"
/*
* SGA_SY - SingleYear_DebtRatio
*
* Description: Calculates the current year Debt Ratio. (i.e. Total Liabilities / Total Assets)
*
* Categories used:
*	1) Single
*	2) BalanceSheet
*
* Scoring:
*	High = <30% (Recheck)
*	Med = <45%
*	Low = <60%
*	Fail = >60%
*/

class DebtRatio_SY : public MetricSY<MetricType::DebtRatio_SY, CategoryType::Single, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	DebtRatio_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double> *MetricPerformances);
};