#include "../../Header/Metric/CapexMargin_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

CapexMargin_MY::CapexMargin_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	long double totalLiabilities = stock.get_BS_metric(BalanceSheetMetrics::totalLiabilities, 0);
	long double totalAssets = stock.get_BS_metric(BalanceSheetMetrics::totalAssets, 0);
	long double DebtRatio = totalLiabilities / totalAssets;
	this->set_performance(DebtRatio); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool CapexMargin_MY::highScore()
{
	return this->performance <= 0.3;
}

bool CapexMargin_MY::medScore()
{
	return this->performance <= 0.45;
}

bool CapexMargin_MY::lowScore()
{
	return this->performance <= 0.6;
}