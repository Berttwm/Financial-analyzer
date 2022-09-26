#include "../../Header/Metric/CashFlowInvestingOperations_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

CashFlowInvestingOperations_MY::CashFlowInvestingOperations_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	long double grossProfitMargin = stock.get_IS_metric(IncomeStatementMetrics::grossProfitRatio, 0);
	this->set_performance(grossProfitMargin); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool CashFlowInvestingOperations_MY::highScore()
{
	//return this->performance >= 0.3;
	return false;
}

bool CashFlowInvestingOperations_MY::medScore()
{
	return false;
}

bool CashFlowInvestingOperations_MY::lowScore()
{
	return false;
}