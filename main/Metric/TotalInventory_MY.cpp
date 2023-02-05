#include "../../Header/Metric/TotalInventory_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

TotalInventory_MY::TotalInventory_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int TotalInventory_fail_count = 0;
	long double TotalInventory_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double TotalInventory_curr = stock.get_BS_metric(BalanceSheetMetrics::inventory, i);
		if (i == this->year_count - 1)
		{
			TotalInventory_prev = TotalInventory_curr;
			// first iteration skips comparison
			continue;
		}
		long double TotalInventory_diff = TotalInventory_curr - TotalInventory_prev;
		if ((TotalInventory_diff < 0) && (abs(TotalInventory_diff/TotalInventory_prev) > 0.3))
		{
			TotalInventory_fail_count++;
		}
		TotalInventory_prev = TotalInventory_curr;
	}
	this->set_performance(TotalInventory_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool TotalInventory_MY::highScore()
{
	return this->performance == 0.0;
}

bool TotalInventory_MY::medScore()
{
	return this->performance <= 1;
}

bool TotalInventory_MY::lowScore()
{
	return this->performance <= 2;
}