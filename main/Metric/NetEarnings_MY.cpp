#include "../../Header/Metric/NetEarnings_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

NetEarnings_MY::NetEarnings_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int NETEARNINGS_fail_count = 0;
	long double NETEARNINGS_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double NETEARNINGS_curr = stock.get_IS_metric(IncomeStatementMetrics::netIncome, i);
		if (i == this->year_count - 1)
		{
			NETEARNINGS_prev = NETEARNINGS_curr;
			// first iteration skips comparison
			continue;
		}
		if (NETEARNINGS_curr < NETEARNINGS_prev)
		{
			NETEARNINGS_fail_count++;
		}
		NETEARNINGS_prev = NETEARNINGS_curr;
	}
	this->set_performance(NETEARNINGS_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool NetEarnings_MY::highScore()
{
	return this->performance == 0.0;
}

bool NetEarnings_MY::medScore()
{
	return this->performance <= 1;
}

bool NetEarnings_MY::lowScore()
{
	return this->performance <= 2;
}