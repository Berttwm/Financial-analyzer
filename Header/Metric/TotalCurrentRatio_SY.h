#pragma once
#include "MetricSY.h"
/*
* TotalCurrentRatio_SY - SingleYear_TotalCurrentRatio
*
* Description: High current ratio (Current Asset/Current Liabilities) means good ability
* to pay off debt 
*
* Categories used:
*	1) Single
*	2) BalanceSheet
*
* Scoring:
*	High = >= 2
*	Med = >= 1.6
*	Low =  >= 1.2
*	Fail = < 1.2
*/

class TotalCurrentRatio_SY : public MetricSY<MetricType::TotalCurrentRatio_SY, CategoryType::Single, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	TotalCurrentRatio_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances);
};