#include "../../Header/Metric/OperatingExpenses_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

OperatingExpenses_MY::OperatingExpenses_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int OpExp_fail_count = 0;
	long double OpExp_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double OpExp_curr = stock.get_IS_metric(IncomeStatementMetrics::operatingIncome, i);
		if (i == this->year_count - 1)
		{
			OpExp_prev = OpExp_curr;
			// first iteration skips comparison
			continue;
		}
		if (OpExp_curr < OpExp_prev)
		{
			OpExp_fail_count++;
		}
		OpExp_prev = OpExp_curr;
	}
	this->set_performance(OpExp_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool OperatingExpenses_MY::highScore()
{
	return this->performance == 0.0;
}

bool OperatingExpenses_MY::medScore()
{
	return this->performance <= 1;
}

bool OperatingExpenses_MY::lowScore()
{
	return this->performance <= 2;
}