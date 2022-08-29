#include "../Header/Scorer.h"

Scorer::Scorer(Stock &stock)
	: stock(stock),
	stock_data_years(5) // TODO: Change this method
{

}

void Scorer::process()
{
	// TODO: Implement recursive calling on Metric classes
}

//void Scorer::process(const int num_years)
//{
//	// TODO: Implement Year on Year Scorer Metrics
//	int actual_years = std::min(num_years, this->stock_data_years);
//
//}