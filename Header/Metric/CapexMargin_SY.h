#pragma once
#include "MetricSY.h"
/*
* CapexMargin_SY - Capital Exchange over Net Income single year
*
* Description: Companies with durable advantage need to use less of the total earnings on Capex
*
* Categories used:
*	1) Single
*	2) CashFlow
*
* Scoring:
*	High = <=25% & +ve
*	Med = <=50% & +ve
*	Low = <=75% & +ve
*	Fail = >75% year or -ve
*/

class CapexMargin_SY : public MetricSY<MetricType::CapexMargin_SY, CategoryType::Single, CategoryType::CashFlow>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	CapexMargin_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances);
};
