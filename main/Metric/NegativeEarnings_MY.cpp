#include "../../Header/Metric/NegativeEarnings_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

NegativeEarnings_MY::NegativeEarnings_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int NEGATIVEEARNINGS_fail_count = 0;
	long double NEGATIVEEARNINGS_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double NEGATIVEEARNINGS_curr = stock.get_IS_metric(IncomeStatementMetrics::netIncome, i);
		if (i == this->year_count - 1)
		{
			NEGATIVEEARNINGS_prev = NEGATIVEEARNINGS_curr;
			// first iteration skips comparison
			// continue;
		}
		if (NEGATIVEEARNINGS_curr < 0)
		{
			NEGATIVEEARNINGS_fail_count++;
		}
		NEGATIVEEARNINGS_prev = NEGATIVEEARNINGS_curr;
	}
	this->set_performance(NEGATIVEEARNINGS_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool NegativeEarnings_MY::highScore()
{
	return this->performance == 0.0;
}

bool NegativeEarnings_MY::medScore()
{
	return this->performance <= 1;
}

bool NegativeEarnings_MY::lowScore()
{
	return this->performance <= 2;
}