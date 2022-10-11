#include "../../Header/Metric/DebtRatio_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

DebtRatio_MY::DebtRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int DebtRatio_fail_count = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double totalDebt = stock.get_BS_metric(BalanceSheetMetrics::totalDebt, 0);
		long double totalAssets = stock.get_BS_metric(BalanceSheetMetrics::totalAssets, 0);
		long double DebtRatio = totalDebt / totalAssets;
		if (i == this->year_count - 1)
		{
			// first iteration skips comparison
			continue;
		}
		if (DebtRatio > 1)
		{
			DebtRatio_fail_count++;
		}
	}
	this->set_performance(DebtRatio_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool DebtRatio_MY::highScore()
{
	return this->performance == 0.0;
}

bool DebtRatio_MY::medScore()
{
	return this->performance <= 1;
}

bool DebtRatio_MY::lowScore()
{
	return this->performance <= 2;
}