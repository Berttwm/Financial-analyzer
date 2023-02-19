#include "../../Header/Metric/TotalCurrentRatio_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

TotalCurrentRatio_MY::TotalCurrentRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int currentRatio_fail_count = 0;
	long double currentRatio_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double totalCurrentAssets = stock.get_BS_metric(BalanceSheetMetrics::totalCurrentAssets, 0);
		long double totalCurrentLiabilities = stock.get_BS_metric(BalanceSheetMetrics::totalCurrentLiabilities, 0);
		long double currentRatio_curr = totalCurrentAssets / totalCurrentLiabilities;
		if (i == this->year_count - 1)
		{
			currentRatio_prev = currentRatio_curr;
			// first iteration skips comparison
			continue;
		}
		if (currentRatio_curr < 1.2)
		{
			currentRatio_fail_count++;
		}
		currentRatio_prev = currentRatio_curr;
	}
	this->set_performance(currentRatio_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool TotalCurrentRatio_MY::highScore()
{
	return this->performance == 0.0;
}

bool TotalCurrentRatio_MY::medScore()
{
	return this->performance <= 1;
}

bool TotalCurrentRatio_MY::lowScore()
{
	return this->performance <= 2;
}