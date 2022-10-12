#include "../../Header/Metric/NetEarnings_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

NetEarnings_MY::NetEarnings_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	//int SGA_fail_count = 0;
	//long double SGA_prev = 0;
	//// iterate from earliest date available (year_count) to latest date
	//for (int i = this->year_count - 1; i >= 0; i--)
	//{
	//	long double sellingGeneralAndAdministrativeExpenses = stock.get_IS_metric(IncomeStatementMetrics::sellingGeneralAndAdministrativeExpenses, i);
	//	long double grossProfit = stock.get_IS_metric(IncomeStatementMetrics::grossProfit, i);
	//	long double SGA_curr = sellingGeneralAndAdministrativeExpenses / grossProfit;
	//	if (i == this->year_count - 1)
	//	{
	//		SGA_prev = SGA_curr;
	//		// first iteration skips comparison
	//		continue;
	//	}
	//	if (SGA_curr > SGA_prev)
	//	{
	//		SGA_fail_count++;
	//	}
	//	SGA_prev = SGA_curr;
	//}
	//this->set_performance(SGA_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
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