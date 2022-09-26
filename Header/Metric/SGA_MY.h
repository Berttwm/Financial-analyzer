#pragma once
#include "MetricMY.h"
/*
* SGA_MY - MultiYear_SalesGeneralandAdmin
*
* Description: Year on year SGA over profit should never cross 100%
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

class SGA_MY : public MetricMY<MetricType::SGA_MY, CategoryType::Multi, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	SGA_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double> *MetricPerformances, int year_count);
};