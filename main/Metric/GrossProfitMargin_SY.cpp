#include "../../Header/Metric/GrossProfitMargin_SY.h"
GrossProfitMargin_SY::GrossProfitMargin_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores)
{
	
}

bool GrossProfitMargin_SY::highScore()
{
	// reference stock's income statement
	//if(this->stock) ...
}

bool GrossProfitMargin_SY::medScore()
{
	// reference stock's income statement
	//if(this->stock) ...
}

bool GrossProfitMargin_SY::lowScore()
{
	// reference stock's income statement
	//if(this->stock) ...
}
std::vector<CategoryType> GrossProfitMargin_SY::updateCategoryScores()
{
	// cycle through template arguments and update category accordingly
	//std::vector<CategoryType> vec = { args... };
	//for (CategoryType cat: vec) {
	//	std::cout << cat << std::endl;
	//}
	//return vec;
}

std::vector<MetricType> GrossProfitMargin_SY::updateMetricScores()
{
	// cycle through template arguments and update metrics accordingly
}