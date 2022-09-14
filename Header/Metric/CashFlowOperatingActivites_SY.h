#pragma once
#include "MetricSY.h"
/*
* SGA_SY - SingleYear_SalesGeneralandAdmin
*
* Description: Checks for current cash flow from operating activities
*
* Categories used:
*	1) Single
*	2) CashFlow
*
* Scoring:
*	High = ??
*	Med = ??
*	Low = ??
*	Fail = ??
*/

class CashFlowOperatingActivites_SY : public MetricSY<MetricType::CashFlowOperatingActivites_SY, CategoryType::Single, CategoryType::CashFlow>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	CashFlowOperatingActivites_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores);
};