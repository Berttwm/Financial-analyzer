#include "../../Header/Metric/LongTermDebtEarningsRatio_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

LongTermDebtEarningsRatio_MY::LongTermDebtEarningsRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int LONGTERMDEBTTOEARNINGS_fail_count = 0;
	long double LONGTERMDEBTTOEARNINGS_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double NETEARNINGS_curr = stock.get_IS_metric(IncomeStatementMetrics::netIncome, i);
		long double LONGTERMDEBT_curr = stock.get_BS_metric(BalanceSheetMetrics::longTermDebt, i);
		if (LONGTERMDEBT_curr/NETEARNINGS_curr > 3.0) // LongTermDebt is more than 3 times of Net Earnings
		{
			LONGTERMDEBTTOEARNINGS_fail_count++;
		}
	}
	this->set_performance(LONGTERMDEBTTOEARNINGS_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool LongTermDebtEarningsRatio_MY::highScore()
{
	return this->performance == 0.0;
}

bool LongTermDebtEarningsRatio_MY::medScore()
{
	return this->performance <= 1;
}

bool LongTermDebtEarningsRatio_MY::lowScore()
{
	return this->performance <= 2;
}