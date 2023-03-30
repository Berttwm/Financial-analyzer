#include "../../Header/Metric/ShortLongTermDebtRatio_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

ShortLongTermDebtRatio_SY::ShortLongTermDebtRatio_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double shortTermDebt = stock.get_BS_metric(BalanceSheetMetrics::shortTermDebt, 0);
	long double longTermDebt = stock.get_BS_metric(BalanceSheetMetrics::longTermDebt, 0);
	this->set_performance(shortTermDebt / longTermDebt); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool ShortLongTermDebtRatio_SY::highScore()
{
	return (this->performance <= 1/3);
}

bool ShortLongTermDebtRatio_SY::medScore()
{
	return (this->performance <= 2/3);
}

bool ShortLongTermDebtRatio_SY::lowScore()
{
	return (this->performance <= 1);
}