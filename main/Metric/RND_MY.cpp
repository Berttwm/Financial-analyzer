#include "../../Header/Metric/RND_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

RND_MY::RND_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int RND_fail_count = 0;
	long double RND_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double RnDexpenditure = stock.get_IS_metric(IncomeStatementMetrics::researchAndDevelopmentExpenses, i);
		long double grossProfit = stock.get_IS_metric(IncomeStatementMetrics::grossProfit, i);
		long double RND_curr = RnDexpenditure / grossProfit;
		if (i == this->year_count - 1)
		{
			RND_prev = RND_curr;
			// first iteration skips comparison
			//continue;
		}
		if (RND_curr > 1)
		{
			RND_fail_count++;
		}
		RND_prev = RND_curr;
	}
	this->set_performance(RND_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool RND_MY::highScore()
{
	return this->performance == 0.0;
}

bool RND_MY::medScore()
{
	return this->performance <= 1;
}

bool RND_MY::lowScore()
{
	return this->performance <= 2;
}