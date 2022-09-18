#include "../Header/Stock.h"
# include <iostream>
Stock::Stock(rapidjson::Document& d_inc_stmt, rapidjson::Document& d_bal_sheet, rapidjson::Document& d_cash_flow)
	: IS(new IncomeStatement(d_inc_stmt)),
	BS(new BalanceSheet(d_bal_sheet)),
	CF(new CashFlow(d_cash_flow))
{
	//// Step 1: instantiate IS (factory maybe)
	//this->IS = new IncomeStatement(d_inc_stmt);
	//// Step 2: instantiate BS
	//this->BS = new BalanceSheet(d_bal_sheet);
	//// Step 3: instantiate CF
	//this->CF = new CashFlow(d_cash_flow);
	//// Step 4: Infer number of years of data 
	this->num_years_data = this->IS->get_num_years_collected();
}

std::string Stock::get_IS_metric(IncomeStatementMetrics metric, int year_from) const
{
	return this->IS->getKeyFromMap(metric, year_from);
}

std::string Stock::get_BS_metric(BalanceSheetMetrics metric, int year_from) const
{
	return this->BS->getKeyFromMap(metric, year_from);
}

std::string Stock::get_CF_metric(CashFlowMetrics metric, int year_from) const
{
	return this->CF->getKeyFromMap(metric, year_from);
}

int Stock::get_num_years_data() const
{
	return this->num_years_data;
}
