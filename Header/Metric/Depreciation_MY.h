#pragma once
#include "MetricMY.h"
/*
* Depreciation_MY - MultiYear_depreciationAndAmortization
*
* Description: Depreciation And Amortization for current year. Should be consistently < 10% of gross profit
*
* Scoring:
*	High = 0 cross
*	Med = 1 cross
*	Low = 2 cross
*	Fail = >2 cross
*/

class Depreciation_MY : public MetricMY<MetricType::Depreciation_MY, CategoryType::Multi, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	Depreciation_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};