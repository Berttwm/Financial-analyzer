#include "../../Header/Metric/CapexMargin_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

CapexMargin_SY::CapexMargin_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double totalLiabilities = stock.get_BS_metric(BalanceSheetMetrics::totalLiabilities, 0);
	long double totalAssets = stock.get_BS_metric(BalanceSheetMetrics::totalAssets, 0);
	long double DebtRatio = totalLiabilities / totalAssets;
	this->set_performance(DebtRatio); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool CapexMargin_SY::highScore()
{
	return this->performance <= 0.3;
}

bool CapexMargin_SY::medScore()
{
	return this->performance <= 0.45;
}

bool CapexMargin_SY::lowScore()
{
	return this->performance <= 0.6;
}