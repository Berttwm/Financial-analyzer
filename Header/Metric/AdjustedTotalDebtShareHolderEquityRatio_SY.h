#pragma once
#include "MetricSY.h"
/*
* AdjustedTotalDebtShareHolderEquityRatio_SY - SingleYear_TotalDebtToAdjustedShareholderEquityRatio
*
* Description: Debt to adjusted shareholder equity ratio to determine whether the company is using debt or equity to finance its debts
*	Durable companies will use its earning power to service debts. (Ratio<=0.8)
*	Adjusted Debt to Equity Ratio = (Total liabilities / (Shareholders Equity + Stock Repurchased))
* 
* Categories used:
*	1) Single
*	2) BalanceSheet
*
* Scoring:
*	High = <= 80%
*	Med = <= 90%
*	Low =  <= 100%
*	Fail > 100%
*/

class AdjustedTotalDebtShareHolderEquityRatio_SY : public MetricSY<MetricType::AdjustedTotalDebtShareHolderEquityRatio_SY, CategoryType::Single, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	AdjustedTotalDebtShareHolderEquityRatio_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances);
};
