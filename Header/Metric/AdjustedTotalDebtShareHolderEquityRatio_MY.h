#pragma once
#include "MetricMY.h"
/*
* AdjustedTotalDebtShareHolderEquityRatio_SY - SingleYear_TotalDebtToAdjustedShareholderEquityRatio
*
* Description: Debt to adjusted shareholder equity ratio over multiple years to determine how consistent does the company uses earning power to service debts.
*	Durable companies will use its earning power to service debts. (Ratio<=0.8)
*	Adjusted Debt to Equity Ratio = (Total liabilities / (Shareholders Equity + Stock Repurchased))
*
* Categories used:
*	1) Single
*	2) BalanceSheet
*
* Scoring:
*	High = 0 years > 80%
*	Med = 1 years > 80%
*	Low = 2 years > 80%
*	Fail = (>2) years > 80%
*/

class AdjustedTotalDebtShareHolderEquityRatio_MY : public MetricMY<MetricType::AdjustedTotalDebtShareHolderEquityRatio_MY, CategoryType::Multi, CategoryType::BalanceSheet>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	AdjustedTotalDebtShareHolderEquityRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count);
};