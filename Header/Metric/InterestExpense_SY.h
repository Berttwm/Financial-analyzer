#pragma once
#include "MetricSY.h"
/*
* InterestExpense_SY - SingleYear_InterestExpense
*
* Description: Calculates the current year InterestExpense  (i.e. cost of loan)
* over operating costs
*
* Categories used:
*	1) Single
*	2) IncomeStatement
*
* Scoring:
*	High = <= 15%
*	Med = <= 30%
*	Low =  <= 45%
*	Fail = > 50%
*/

class InterestExpense_SY : public MetricSY<MetricType::InterestExpense_SY, CategoryType::Single, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	InterestExpense_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances);
};
