#pragma once
#include "MetricSY.h"
/*
* SGA_SY - SingleYear_SalesGeneralandAdmin
*
* Description: Calculates the current year SGA over gross profit margin
*
* Categories used:
*	1) Single
*	2) IncomeStatement
*
* Scoring:
*	High = <30%
*	Med = <20%
*	Low = <10%
*	Fail = <0%
*/

class SGA_SY : public MetricSY<MetricType::SGA_SY, CategoryType::Single, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	SGA_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores);
};