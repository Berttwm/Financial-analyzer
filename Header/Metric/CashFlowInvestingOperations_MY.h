#pragma once
#include "MetricMY.h"
/*
* CashFlowInvestingOperations_MY - MultiYear_CashFlowInvestingOperations
*
* Description: Calculates the consistency of positive cash flow from Investing Operations
*
* Categories used:
*	1) Multi
*	2) CashFlow
*
* Scoring:
*	High = consistently positive
*	Med = 1 year negative
*	Low = 2 year negative
*	Fail = >2 year negative
*/

class CashFlowInvestingOperations_MY : public MetricMY<MetricType::CashFlowInvestingOperations_MY, CategoryType::Multi, CategoryType::CashFlow>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	CashFlowInvestingOperations_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};
