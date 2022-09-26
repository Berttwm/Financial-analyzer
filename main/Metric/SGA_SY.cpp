#include "../../Header/Metric/SGA_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

SGA_SY::SGA_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double grossProfitMargin = stock.get_IS_metric(IncomeStatementMetrics::grossProfitRatio, 0);
	this->set_performance(grossProfitMargin); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool SGA_SY::highScore()
{
	//return this->performance >= 0.3;
	return false;
}

bool SGA_SY::medScore()
{
	return false;
}

bool SGA_SY::lowScore()
{
	return false;
}