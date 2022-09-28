#pragma once
#include "MetricMY.h"
/*
* CapexMargin_MY - Capital Exchange over Net Income over multiple years
*
* Description: Companies with durable advantage need to use less of the total earnings on Capex
*
* Categories used:
*	1) Multi
*	2) CashFlow
*
* Scoring:
*	High = consistently increasing over years
*	Med = 1 year drop
*	Low = 2 year drop
*	Fail = >2 year drop
*/

class CapexMargin_MY : public MetricMY<MetricType::CapexMargin_MY, CategoryType::Multi, CategoryType::CashFlow>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	CapexMargin_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};
