#include "../Header/Stock.h"
# include <iostream>
Stock::Stock(rapidjson::Document& d_inc_stmt, rapidjson::Document& d_bal_sheet, rapidjson::Document& d_cash_flow)
{
	// Step 1: instantiate IS (factory maybe)
	this->IS = new IncomeStatement(d_inc_stmt);
	// Step 2: instantiate BS
	this->BS = new BalanceSheet(d_bal_sheet);
	// Step 3: instantiate CF
	this->CF = new CashFlow(d_cash_flow);

}
void Stock::test_func() const
{
	std::cout << "test func" << std::endl;
}
