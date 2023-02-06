#include "../../Header/Metric/TotalReceivablesOverRevenue_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

TotalReceivablesOverRevenue_MY::TotalReceivablesOverRevenue_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int TotalReceivablesOverRevenue_fail_count = 0;
	long double TotalReceivablesOverRevenue_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double revenue = stock.get_IS_metric(IncomeStatementMetrics::revenue, i);
		long double netReceivables = stock.get_BS_metric(BalanceSheetMetrics::netReceivables, i);
		long double TotalReceivablesOverRevenue_curr = netReceivables / revenue;
		if (i == this->year_count - 1)
		{
			TotalReceivablesOverRevenue_prev = TotalReceivablesOverRevenue_curr;
			// first iteration skips comparison
			continue;
		}
		if (TotalReceivablesOverRevenue_curr > 0.3)
		{
			TotalReceivablesOverRevenue_fail_count++;
		}
		TotalReceivablesOverRevenue_prev = TotalReceivablesOverRevenue_curr;
	}
	this->set_performance(TotalReceivablesOverRevenue_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool TotalReceivablesOverRevenue_MY::highScore()
{
	return this->performance == 0.0;
}

bool TotalReceivablesOverRevenue_MY::medScore()
{
	return this->performance <= 1;
}

bool TotalReceivablesOverRevenue_MY::lowScore()
{
	return this->performance <= 2;
}