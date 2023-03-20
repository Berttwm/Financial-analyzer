#pragma once
#include "MetricMY.h"
/*
* ReturnOnTotalAsset_MY - MultiYear_ReturnOnTotalAsset
*
* Description: Multi year efficiency of assets in generating income. 
* How many years can sustain >=20% efficiency
* 
* Categories used:
*	1) Multi
*	2) BalanceSheet
*
* Scoring:
*	High = 0 years below 20%
*	Med = 1 years below 20%
*	Low = 2 years below 20%
*	Fail = 3+ years below 20%
*/

class ReturnOnTotalAsset_MY : public MetricMY<MetricType::ReturnOnTotalAsset_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	ReturnOnTotalAsset_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};