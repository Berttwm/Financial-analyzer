#include "../../Header/Metric/GrossProfitMargin_SY.h"

GrossProfitMargin_SY::GrossProfitMargin_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores)
{
	this->scoreMetric();
	stock.test_func();

}

bool GrossProfitMargin_SY::highScore()
{
	// reference stock's income statement
	//if(this->stock) ...
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