#include "../../Header/Metric/Goodwill_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

Goodwill_MY::Goodwill_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int Goodwill_fail_count = 0;
	long double Goodwill_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double Goodwill_curr = stock.get_BS_metric(BalanceSheetMetrics::goodwill, i);
		if (i == this->year_count - 1)
		{
			Goodwill_prev = Goodwill_curr;
			// first iteration skips comparison
			continue;
		}
		if ((Goodwill_curr - Goodwill_prev) < 0) // if negative goodwill
		{
			Goodwill_fail_count++;
		}
		Goodwill_prev = Goodwill_curr;
	}
	this->set_performance(Goodwill_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool Goodwill_MY::highScore()
{
	return this->performance == 0.0;
}

bool Goodwill_MY::medScore()
{
	return this->performance <= 1;
}

bool Goodwill_MY::lowScore()
{
	return this->performance <= 2;
}