#include "../../Header/Metric/EarningsGrowth_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

EarningsGrowth_MY::EarningsGrowth_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int EARNINGS_fail_count = 0;
	long double EARNINGS_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double EARNINGS_curr = stock.get_IS_metric(IncomeStatementMetrics::netIncome, i);
		if (i == this->year_count - 1)
		{
			EARNINGS_prev = EARNINGS_curr;
			// first iteration skips comparison
			continue;
		}
		//std::cout << "(EARNINGS_curr - EARNINGS_prev) /EARNINGS_prev" << (EARNINGS_curr - EARNINGS_prev) / EARNINGS_prev << std::endl;
		if (((EARNINGS_curr - EARNINGS_prev) /EARNINGS_prev) < 0.029)
		{
			EARNINGS_fail_count++;
		}
		EARNINGS_prev = EARNINGS_curr;
	}
	this->set_performance(EARNINGS_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool EarningsGrowth_MY::highScore()
{
	return this->performance == 0.0;
}

bool EarningsGrowth_MY::medScore()
{
	return this->performance <= 1;
}

bool EarningsGrowth_MY::lowScore()
{
	return this->performance <= 2;
}