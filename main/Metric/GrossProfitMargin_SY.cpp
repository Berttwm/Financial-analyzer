#include "../../Header/Metric/GrossProfitMargin_SY.h"

GrossProfitMargin_SY::GrossProfitMargin_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores)
{
	this->scoreMetric();
}

bool GrossProfitMargin_SY::highScore()
{
	// reference stock's income statement
	//if(this->stock) ...

	std::string grossProfitStr = stock.get_IS_metric(IncomeStatementMetrics::grossProfit, 0);
	std::string revenueStr = stock.get_IS_metric(IncomeStatementMetrics::revenue, 0);
	int num_years = stock.get_num_years_data(); // Not needed for SY statements
	// TODO: turn above 2 string into the correct type and use it in highScore, medScore, and lowScore.
	std::cout << "grossProfitStr = " << grossProfitStr << std::endl;
	std::cout << "revenueStr = " << revenueStr << std::endl;
	std::cout << "num_years = " << num_years << std::endl;
	return true;
}

bool GrossProfitMargin_SY::medScore()
{
	// reference stock's income statement
	//if(this->stock) ...
	return true;
}

bool GrossProfitMargin_SY::lowScore()
{
	// reference stock's income statement
	//if(this->stock) ...
	return true;
}