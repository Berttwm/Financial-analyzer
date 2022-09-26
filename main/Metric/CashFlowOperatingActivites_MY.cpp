#include "../../Header/Metric/CashFlowOperatingActivites_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

CashFlowOperatingActivites_MY::CashFlowOperatingActivites_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	long double grossProfitMargin = stock.get_IS_metric(IncomeStatementMetrics::grossProfitRatio, 0);
	this->set_performance(grossProfitMargin); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool CashFlowOperatingActivites_MY::highScore()
{
	//return this->performance >= 0.3;
	return false;
}

bool CashFlowOperatingActivites_MY::medScore()
{
	return false;
}

bool CashFlowOperatingActivites_MY::lowScore()
{
	return false;
}