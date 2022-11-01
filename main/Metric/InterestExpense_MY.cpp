#include "../../Header/Metric/InterestExpense_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

InterestExpense_MY::InterestExpense_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int DEPRECIATION_fail_count = 0;
	long double DEPRECIATION_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double sellingGeneralAndAdministrativeExpenses = stock.get_IS_metric(IncomeStatementMetrics::sellingGeneralAndAdministrativeExpenses, i);
		long double grossProfit = stock.get_IS_metric(IncomeStatementMetrics::grossProfit, i);
		long double DEPRECIATION_curr = sellingGeneralAndAdministrativeExpenses / grossProfit;
		if (i == this->year_count - 1)
		{
			DEPRECIATION_prev = DEPRECIATION_curr;
			// first iteration skips comparison
			// continue;
		}
		if (DEPRECIATION_curr > 0.15)
		{
			DEPRECIATION_fail_count++;
		}
		DEPRECIATION_prev = DEPRECIATION_curr;
	}
	this->set_performance(DEPRECIATION_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool InterestExpense_MY::highScore()
{
	return this->performance == 0.0;
}

bool InterestExpense_MY::medScore()
{
	return this->performance <= 1;
}

bool InterestExpense_MY::lowScore()
{
	return this->performance <= 2;
}