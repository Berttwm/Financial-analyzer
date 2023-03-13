#pragma once
#include "MetricMY.h"
/*
* TotalReceivablesOverRevenue_MY - MultiYear_TotalReceivablesOverRevenue
*
* Description: Good if low net receivables to gross sales compared to competitors consistently. Company does not need to offer flexible payment options and people would still purchase.
*	Accounts Receivable – refers to sales that have occurred on credit, meaning that the company has not yet collected the cash proceeds from these sales.
* 
* Categories used:
*	1) Multi
*	2) BalanceSheet
*
* Scoring:
*	High = 0 years below 30%
*	Med = 1 years below 30%
*	Low = 2 years below 30%
*	Fail = 3+ years below 30%
*/

class TotalReceivablesOverRevenue_MY : public MetricMY<MetricType::TotalReceivablesOverRevenue_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	TotalReceivablesOverRevenue_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};