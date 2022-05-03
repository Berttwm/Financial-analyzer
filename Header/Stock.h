#pragma once
#include "IncomeStatement.h"
#include "BalanceSheet.h"
#include "CashFlow.h"

class Stock
{
public:
	Stock(); // Try to initialize the 3 Objects

private:
	int age;
	int num_years_data;
	IncomeStatement *IS;
	BalanceSheet *BS;
	CashFlow *CF;

};