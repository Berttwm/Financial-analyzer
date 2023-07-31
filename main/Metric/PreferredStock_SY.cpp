#include "../../Header/Metric/PreferredStock_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

PreferredStock_SY::PreferredStock_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double preferredStock = stock.get_BS_metric(BalanceSheetMetrics::preferredStock, 0);
	this->set_performance(preferredStock); 
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool PreferredStock_SY::highScore()
{
	return (this->performance == 0);
}

bool PreferredStock_SY::medScore()
{
	return false; // to give it 'fail' score
}

bool PreferredStock_SY::lowScore()
{
	return false; // to give it 'fail' score
}