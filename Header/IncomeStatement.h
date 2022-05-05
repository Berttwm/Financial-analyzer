#pragma once

#include "StockUtils.h"
#include "Statements.h"

class IncomeStatement : public Statements<IncomeStatementMetrics>
{
private:

public:
	void addToMap(IncomeStatementMetrics metric, std::string value);

};