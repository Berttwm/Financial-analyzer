#pragma once
#include "MetricSY.h"
/*
* CashFlowInvestingOperations_SY - SingleYear_CashFlowInvestingOperations
*
* Description: Calculates current cash flow from investing activities
*
* Categories used:
*	1) Single
*	2) CashFlow
*
* Scoring:
*	High = ?
*	Med = ?
*	Low = ?
*	Fail = ?
*/

class CashFlowInvestingOperations_SY : public MetricSY<MetricType::CashFlowInvestingOperations_SY, CategoryType::Single, CategoryType::CashFlow>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	CashFlowInvestingOperations_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores);
};