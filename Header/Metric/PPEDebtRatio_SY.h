#pragma once
#include "MetricSY.h"
/*
* PPEDebtRatio_SY - SingleYear_PropertyPlantEquipment_Debt_Ratio
*
* Description: The cost of Property, Plant and Equipment over Debt. Competive Durable companies are able to pay of PPE debt with relative ease
* PPE cost as a proportion of total debt has to be relatively low
*
* Categories used:
*	1) Single
*	2) BalanceSheet
*
* Scoring:
*	High = <= 1
*	Med = <= 1.5
*	Low =  <= 2
*	Fail = > 2
*/

class PPEDebtRatio_SY : public MetricSY<MetricType::PPEDebtRatio_SY, CategoryType::Single, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	PPEDebtRatio_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances);
};