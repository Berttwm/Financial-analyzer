#pragma once
#include "Statements.h"

class IncomeStatement : public Statements<IncomeStatementMetrics>
{
private:

public:
	IncomeStatement(rapidjson::Document& d_inc_stmt);
	void addToMap(IncomeStatementMetrics metric, std::string value);

};