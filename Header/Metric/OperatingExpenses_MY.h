#pragma once
#include "MetricMY.h"
/*
* OperatingExpenses_MY - MultiYear_OperatingExpense
*
* Description: Calculates the consistency of Operating Expenses over the years
*
* Categories used:
*	1) Multi
*	2) IncomeStatement
*
* Scoring:
*	High = consistently increasing over years
*	Med = 1 year drop
*	Low = 2 year drop
*	Fail = >2 year drop
*/

class OperatingExpenses_MY : public MetricMY<MetricType::OperatingExpenses_MY, CategoryType::Multi, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	OperatingExpenses_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
}; 
