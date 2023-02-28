#include "../../Header/Metric/PPEDebtRatio_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

PPEDebtRatio_SY::PPEDebtRatio_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double propertyPlantEquipmentNet = stock.get_BS_metric(BalanceSheetMetrics::propertyPlantEquipmentNet, 0);
	long double totalDebt = stock.get_BS_metric(BalanceSheetMetrics::totalDebt, 0);
	this->set_performance(propertyPlantEquipmentNet / totalDebt); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool PPEDebtRatio_SY::highScore()
{
	return (this->performance <= 1.0);
}

bool PPEDebtRatio_SY::medScore()
{
	return (this->performance <= 1.5);
}

bool PPEDebtRatio_SY::lowScore()
{
	return (this->performance <= 2);
}