#pragma once
#include "IncomeStatement.h"
#include "BalanceSheet.h"
#include "CashFlow.h"

#include "rapidjson/document.h"


class Stock
{
public:
	Stock(rapidjson::Document& d_inc_stmt, rapidjson::Document& d_bal_sheet, rapidjson::Document& d_cash_flow); // Try to initialize the 3 Objects here
	/* get_IS_metric() = getting the string result from the input IncomeStatementMetric.
	 * year_from = number of years from the latest year(i.e.year_from = 3 implies 3 years from the latest statement date)
	*/
	long double get_IS_metric(IncomeStatementMetrics metric, int year_from) const;
	
	/* get_BS_metric() = getting the string result from the input BalanceSheetMetrics.
	* year_from = number of years from the latest year(i.e.year_from = 3 implies 3 years from the latest statement date)
	*/
	long double get_BS_metric(BalanceSheetMetrics metric, int year_from) const;
	
	/* get_CF_metric() = getting the string result from the input CashFlowMetrics.
	* year_from = number of years from the latest year(i.e.year_from = 3 implies 3 years from the latest statement date)
	*/
	long double get_CF_metric(CashFlowMetrics metric, int year_from) const;

	int get_num_years_data() const;
private:
	int age;
	int num_years_data;
	IncomeStatement *IS;
	BalanceSheet *BS;
	CashFlow *CF;
};