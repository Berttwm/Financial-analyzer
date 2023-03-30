#pragma once
#include "MetricSY.h"
/*
* ShortLongTermDebtRatio_SY - SingleYear_ShortTermLongTermDebtRatio
*
* Description: Short term to Long term debt ratio. Indication of how leveraged a company is. Durable companies tend to have a lower ratio. No need for leveraged operations.
* Short term debt = Money owed by the corporation and due within current year
*
* Categories used:
*	1) Single
*	2) BalanceSheet
*
* Scoring:
*	High = <= 33.333%
*	Med = <= 66.667%
*	Low =  <= 100%
*	Fail > 100%
*/

class ShortLongTermDebtRatio_SY : public MetricSY<MetricType::ShortLongTermDebtRatio_SY, CategoryType::Single, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	ShortLongTermDebtRatio_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances);
}; 
