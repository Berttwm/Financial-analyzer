#include "../../Header/Metric/NetEarningsOverRevenue_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

NetEarningsOverRevenue_MY::NetEarningsOverRevenue_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int NETEARNINGS_OVER_REVENUE_fail_count = 0;
	long double NETEARNINGS_OVER_REVENUE_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double netIncome = stock.get_IS_metric(IncomeStatementMetrics::netIncome, i);
		long double revenue = stock.get_IS_metric(IncomeStatementMetrics::revenue, i);
		long double NETEARNINGS_OVER_REVENUE_curr = netIncome / revenue;
		if (i == this->year_count - 1)
		{
			NETEARNINGS_OVER_REVENUE_prev = NETEARNINGS_OVER_REVENUE_curr;
			// first iteration skips comparison
			//continue;
		}
		if (NETEARNINGS_OVER_REVENUE_curr < 0.1)
		{
			//std::cout << "NETEARNINGS_OVER_REVENUE_curr: " << NETEARNINGS_OVER_REVENUE_curr << std::endl;
			NETEARNINGS_OVER_REVENUE_fail_count++;
		}
		NETEARNINGS_OVER_REVENUE_prev = NETEARNINGS_OVER_REVENUE_curr;
	}
	this->set_performance(NETEARNINGS_OVER_REVENUE_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool NetEarningsOverRevenue_MY::highScore()
{
	return this->performance == 0.0;
}

bool NetEarningsOverRevenue_MY::medScore()
{
	return this->performance <= 1;
}

bool NetEarningsOverRevenue_MY::lowScore()
{
	return this->performance <= 2;
}