#include "../Header/Scorer.h"

Scorer::Scorer(Stock &stock)
	: stock(stock),
	stock_data_years(5) // TODO: Change this method
{

}

void Scorer::process(SingleYearIncomeStmtMetrics)
{
	// TODO: Implement Current Year Scorer Metrics
}

void Scorer::process(MultiYearIncomeStmtMetrics, const int num_years)
{
	// TODO: Implement Year on Year Scorer Metrics
	int actual_years = std::min(num_years, this->stock_data_years);

}

void Scorer::process(SingleYearBalanceSheetMetrics)
{
	// TODO: Implement Current Year Scorer Metrics
}

void Scorer::process(MultiYearBalanceSheetMetrics, const int num_years)
{
	// TODO: Implement Year on Year Scorer Metrics
	int actual_years = std::min(num_years, this->stock_data_years);

}

void Scorer::process(SingleYearCashFlowMetrics)
{
	// TODO: Implement Current Year Scorer Metrics
}

void Scorer::process(MultiYearCashFlowMetrics, const int num_years)
{
	// TODO: Implement Year on Year Scorer Metrics
	int actual_years = std::min(num_years, this->stock_data_years);

}