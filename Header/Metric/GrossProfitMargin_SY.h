#pragma once
#include "MetricSY.h"
/*
* GrossProfitMargin_SY - SingleYear_GrossProfitMargin
* 
* Description: Calculates the current year gross profit margin
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

// This shall be our benchmark SY class.

class GrossProfitMargin_SY : public MetricSY<MetricType::GrossProfitMargin_SY, CategoryType::Single, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	GrossProfitMargin_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double> *MetricPerformances);
};