#include "../../Header/Metric/InterestExpense_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

InterestExpense_SY::InterestExpense_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double interestExpense = stock.get_IS_metric(IncomeStatementMetrics::interestExpense, 0);
	long double operatingExpenses = stock.get_IS_metric(IncomeStatementMetrics::operatingExpenses, 0);
	this->set_performance(interestExpense / operatingExpenses); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool InterestExpense_SY::highScore()
{
	return (this->performance >= 0 && this->performance <= 0.15);
}

bool InterestExpense_SY::medScore()
{
	return (this->performance >= 0 && this->performance <= 0.3);
}

bool InterestExpense_SY::lowScore()
{
	return (this->performance >= 0 && this->performance <= 0.45);
}