#include "../Header/Scorer.h"

Scorer::Scorer(const Stock &stock)
	: stock(stock)
{

}

void Scorer::process()
{
	// TODO: Implement recursive calling on Metric classes
	GrossProfitMargin_SY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores);
}

// GETTERS:
int Scorer::get_curr_score()
{
	return this->CURR_SCORE;
}


std::unordered_map<CategoryType, int> Scorer::get_categoryscores()
{
	return this->CategoryScores;
}

std::unordered_map<MetricType, int> Scorer::get_metricscores()
{
	return this->MetricScores;
}

std::unordered_map<CategoryType, int> Scorer::get_maxcategoryscores()
{
	return this->MaxCategoryScores;
}

std::unordered_map<MetricType, int> Scorer::get_maxmetricscores()
{
	return this->MaxMetricScores;
}