#include "../../Header/Metric/GrossProfitMargin_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

/*
* GrossProfitMargin_SY - SingleYear_GrossProfitMargin
*
* Description: Calculates the current year gross profit margin
*
* Categories used :
*1) Single
* 2) IncomeStatement
*
* Scoring:
*High = < 30 %
*Med = < 20 %
*Low = < 10 %
*Fail = < 0 %
*/

// This shall be our benchmark SY class.

GrossProfitMargin_SY::GrossProfitMargin_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double> *MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double grossProfitMargin = stock.get_IS_metric(IncomeStatementMetrics::grossProfitRatio, 0);
	this->set_performance(grossProfitMargin); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool GrossProfitMargin_SY::highScore()
{
	// reference stock's income statement
	//if(this->stock) ...

	long double grossProfitStr = stock.get_IS_metric(IncomeStatementMetrics::grossProfit, 0);
	long double revenueStr = stock.get_IS_metric(IncomeStatementMetrics::revenue, 0);
	int num_years = stock.get_num_years_data(); // Not needed for SY statements
	// TODO: turn above 2 string into the correct type and use it in highScore, medScore, and lowScore.
	//std::cout << std::setprecision(17) << "grossProfitStr = " << grossProfitStr << std::endl;
	//std::cout << std::setprecision(17) << "revenueStr = " << revenueStr << std::endl;

	//std::cout << std::setprecision(17) << "grossProfitMargin calculated = " << (1.0*(grossProfitStr)) / (1.0 *(revenueStr)) << std::endl;
	//std::cout << std::setprecision(17) << "grossProfitMargin = " << this->performance << std::endl;
	return this->performance >= 0.3;
}

bool GrossProfitMargin_SY::medScore()
{
	return this->performance >= 0.2;
}

bool GrossProfitMargin_SY::lowScore()
{
	return this->performance >= 0.1;
}