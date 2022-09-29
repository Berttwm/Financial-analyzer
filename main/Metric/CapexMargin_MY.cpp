#include "../../Header/Metric/CapexMargin_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

CapexMargin_MY::CapexMargin_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int capex_fail_count = 0;
	long double capex_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double capitalExpenditure = abs(stock.get_CF_metric(CashFlowMetrics::capitalExpenditure, i)); // Capex is always negative
		long double netIncome = stock.get_IS_metric(IncomeStatementMetrics::netIncome, i);
		long double Capex_curr = capitalExpenditure / netIncome;
		if (i == this->year_count - 1)
		{
			capex_prev = Capex_curr;
			// first iteration skips comparison
			continue;
		}
		if (Capex_curr < capex_prev)
		{
			capex_fail_count++;
		}
		capex_prev = Capex_curr;
	}
	this->set_performance(capex_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool CapexMargin_MY::highScore()
{
	return this->performance == 0.0;
}

bool CapexMargin_MY::medScore()
{
	return this->performance <= 1;
}

bool CapexMargin_MY::lowScore()
{
	return this->performance <= 2;
}