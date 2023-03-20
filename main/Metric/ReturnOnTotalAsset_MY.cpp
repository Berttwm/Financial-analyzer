#include "../../Header/Metric/ReturnOnTotalAsset_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

ReturnOnTotalAsset_MY::ReturnOnTotalAsset_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int ReturnOnTotalAsset_fail_count = 0;
	long double ReturnOnTotalAsset_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double netIncome = stock.get_IS_metric(IncomeStatementMetrics::netIncome, 0);
		long double totalAssets = stock.get_BS_metric(BalanceSheetMetrics::totalAssets, 0);
		long double ReturnOnTotalAsset_curr = netIncome / totalAssets;
		if (i == this->year_count - 1)
		{
			ReturnOnTotalAsset_prev = ReturnOnTotalAsset_curr;
			// first iteration skips comparison
			continue;
		}
		if (ReturnOnTotalAsset_curr <= 0.20)
		{
			ReturnOnTotalAsset_fail_count++;
		}
		ReturnOnTotalAsset_prev = ReturnOnTotalAsset_curr;
	}
	this->set_performance(ReturnOnTotalAsset_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool ReturnOnTotalAsset_MY::highScore()
{
	return this->performance == 0.0;
}

bool ReturnOnTotalAsset_MY::medScore()
{
	return this->performance <= 1;
}

bool ReturnOnTotalAsset_MY::lowScore()
{
	return this->performance <= 2;
}