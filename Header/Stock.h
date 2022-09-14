#pragma once
#include "IncomeStatement.h"
#include "BalanceSheet.h"
#include "CashFlow.h"

#include "rapidjson/document.h"


class Stock
{
public:
	Stock(rapidjson::Document& d_inc_stmt, rapidjson::Document& d_bal_sheet, rapidjson::Document& d_cash_flow); // Try to initialize the 3 Objects here
	void test_func() const;
private:
	int age;
	int num_years_data;
	IncomeStatement *IS;
	BalanceSheet *BS;
	CashFlow *CF;
};