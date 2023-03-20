#include "../../Header/Metric/ReturnOnTotalAsset_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

ReturnOnTotalAsset_SY::ReturnOnTotalAsset_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double netIncome = stock.get_IS_metric(IncomeStatementMetrics::netIncome, 0);
	long double totalAssets = stock.get_BS_metric(BalanceSheetMetrics::totalAssets, 0);
	this->set_performance(netIncome / totalAssets); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool ReturnOnTotalAsset_SY::highScore()
{
	return (this->performance >= 20.0);
}

bool ReturnOnTotalAsset_SY::medScore()
{
	return (this->performance >= 12.5);
}

bool ReturnOnTotalAsset_SY::lowScore()
{
	return (this->performance >= 5);
}