#pragma once
#include "MetricMY.h"
/*
* PPEDebtRatio_MY - MultiYear_PropertyPlantEquipment_Debt_Ratio
*
* Description: Good if PPE over Debt ratio is consistently low (lower than 2)
*
* Categories used:
*	1) Multi
*	2) BalanceSheet
*
* Scoring:
*	High = 0 years above 2
*	Med = 1 years above 2
*	Low = 2 years above 2
*	Fail = 3+ years above 2
*/

class PPEDebtRatio_MY : public MetricMY<MetricType::PPEDebtRatio_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	PPEDebtRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};