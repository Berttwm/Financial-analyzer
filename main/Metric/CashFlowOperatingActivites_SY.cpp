#include "../../Header/Metric/CashFlowOperatingActivites_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

CashFlowOperatingActivites_SY::CashFlowOperatingActivites_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double grossProfitMargin = stock.get_IS_metric(IncomeStatementMetrics::grossProfitRatio, 0);
	this->set_performance(grossProfitMargin); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool CashFlowOperatingActivites_SY::highScore()
{
	//return this->performance >= 0.3;
	return false;
}

bool CashFlowOperatingActivites_SY::medScore()
{
	return false;
}

bool CashFlowOperatingActivites_SY::lowScore()
{
	return false;
}