#include "../../Header/Metric/PreferredStock_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

PreferredStock_MY::PreferredStock_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int PreferredStock_fail_count = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double preferredStock = stock.get_BS_metric(BalanceSheetMetrics::preferredStock, i);

		if (preferredStock > 0)
		{
			PreferredStock_fail_count++;
		}
	}
	this->set_performance(PreferredStock_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool PreferredStock_MY::highScore()
{
	return this->performance == 0.0;
}

bool PreferredStock_MY::medScore()
{
	return this->performance <= 1;
}

bool PreferredStock_MY::lowScore()
{
	return this->performance <= 2;
}