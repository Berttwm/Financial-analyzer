#pragma once
#include "MetricMY.h"
/*
* InterestExpense_MY - Multi_InterestExpense
*
* Description: Calculates the year on year InterestExpense  (i.e. cost of loan)
* over operating costs. Ideally should be consistently below 15%.
*
* Categories used:
*	1) Multi
*	2) IncomeStatement
*
* Scoring:
*	High = 0 cross
*	Med = 1 cross
*	Low = 2 cross
*	Fail = >2 cross
*/

class InterestExpense_MY : public MetricMY<MetricType::InterestExpense_MY, CategoryType::Multi, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	InterestExpense_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};