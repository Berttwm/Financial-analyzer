#include "../../Header/Metric/TotalCurrentRatio_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

TotalCurrentRatio_SY::TotalCurrentRatio_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double totalCurrentAssets = stock.get_BS_metric(BalanceSheetMetrics::totalCurrentAssets, 0);
	long double totalCurrentLiabilities = stock.get_BS_metric(BalanceSheetMetrics::totalCurrentLiabilities, 0);
	this->set_performance(totalCurrentAssets / totalCurrentLiabilities); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool TotalCurrentRatio_SY::highScore()
{
	return (this->performance >= 2.0);
}

bool TotalCurrentRatio_SY::medScore()
{
	return (this->performance >= 1.6);
}

bool TotalCurrentRatio_SY::lowScore()
{
	return (this->performance >= 1.2);
}