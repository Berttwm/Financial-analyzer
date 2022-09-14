#pragma once
#include "MetricMY.h"
/*
* SellingAndBuyingStock_MY - MultiYear_SellingAndBuyingStock
*
* Description: Calculates the consistency in company buying back shares
*
* Categories used:
*	1) Multi
*	2) CashFlow
*
* Scoring:
*	High = consistently buying back
*	Med = 1 year no buy back
*	Low = 2 year no buy back
*	Fail = >2 year no buy back
*/

class SellingAndBuyingStock_MY : public MetricMY<MetricType::SellingAndBuyingStock_MY, CategoryType::Multi, CategoryType::CashFlow>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	SellingAndBuyingStock_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, int year_count);
};
