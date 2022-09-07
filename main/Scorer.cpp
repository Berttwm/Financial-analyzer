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

//void Scorer::process(const int num_years)
//{
//	// TODO: Implement Year on Year Scorer Metrics
//	int actual_years = std::min(num_years, this->stock_data_years);
//
//}