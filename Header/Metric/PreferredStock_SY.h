#pragma once
#include "MetricSY.h"
/*
* PreferredStock_SY - SingleYear_PreferredStock
*
* Description: Checking for presence of preferred stock on balance sheet for current year
*	Absence of preferred stock means durable company
*   Preferred stockholders have no voting rights but right to fixed/adjustable dividend
*
* Categories used:
*	1) Single
*	2) BalanceSheet
*
* Scoring:
*	High == 0 
*	Med > 0
*	Low > 0
*	Fail > 0
*/

class PreferredStock_SY : public MetricSY<MetricType::PreferredStock_SY, CategoryType::Single, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	PreferredStock_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances);
};
#pragma once
