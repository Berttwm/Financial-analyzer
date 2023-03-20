#pragma once
#include "MetricSY.h"
/*
* ReturnOnTotalAsset_SY - SingleYear_ReturnOnTotalAssets
*
* Description: Net earnings / total assets for efficiency of assets in generating income. 
* Above 5% is great, above 20% is very good
*
* Categories used:
*	1) Single
*	2) BalanceSheet
*
* Scoring:
*	High = >= 20%
*	Med = >= 12.5% 
*	Low =  >= 5%
*	Fail = < 5%
*/

class ReturnOnTotalAsset_SY : public MetricSY<MetricType::ReturnOnTotalAsset_SY, CategoryType::Single, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	ReturnOnTotalAsset_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances);
};