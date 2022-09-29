#include "../../Header/Metric/CapexMargin_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

CapexMargin_SY::CapexMargin_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double capitalExpenditure = abs(stock.get_CF_metric(CashFlowMetrics::capitalExpenditure, 0)); // Capex is always negative
	long double netIncome = stock.get_IS_metric(IncomeStatementMetrics::netIncome, 0);
	long double Capex_SY = capitalExpenditure / netIncome;
	this->set_performance(Capex_SY); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool CapexMargin_SY::highScore()
{
	return this->performance <= 0.25;
}

bool CapexMargin_SY::medScore()
{
	return this->performance <= 0.5;
}

bool CapexMargin_SY::lowScore()
{
	return this->performance <= 0.75;
}