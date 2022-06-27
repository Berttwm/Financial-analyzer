#pragma once
#include "Statements.h"

class BalanceSheet : public Statements<IncomeStatementMetrics>
{
private:
public:
	BalanceSheet(rapidjson::Document& d_bal_sheet);
	void addToMap(IncomeStatementMetrics metric, std::string value);
};