#pragma once
#include "Statements.h"

class BalanceSheet : public Statements<BalanceSheetMetrics>
{
private:
public:
	BalanceSheet(rapidjson::Document& d_bal_sheet);
	void addToMap(BalanceSheetMetrics metric, std::string);
};