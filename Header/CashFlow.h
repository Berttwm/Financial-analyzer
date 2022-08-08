#pragma once
#include "Statements.h"

class CashFlow : public Statements<IncomeStatementMetrics>
{
private:
public:
	CashFlow(rapidjson::Document& d_cash_flow);
	void addToMap(IncomeStatementMetrics metric, std::string value);
};