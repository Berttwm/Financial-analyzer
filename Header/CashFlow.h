#pragma once
#include "Statements.h"

class CashFlow : public Statements<CashFlowMetrics>
{
private:
public:
	CashFlow(rapidjson::Document& d_cash_flow);
	void addToMap(CashFlowMetrics metric, std::string);
};