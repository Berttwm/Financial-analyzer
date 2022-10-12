#pragma once
#include "MetricSY.h"
/*
* Depreciation_SY - SingleYear_depreciationAndAmortization
*
* Description: Depreciation And Amortization for current year. Should be below 10% of gross profit
*
* Categories used:
*	1) Single
*	2) IncomeStatement
*
* Scoring:
*	High = <= 10%
*	Med = <= 20%
*	Low =  <= 30%
*	Fail = > 30% or negative
*/

class Depreciation_SY : public MetricSY<MetricType::Depreciation_SY, CategoryType::Single, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	Depreciation_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances);
};