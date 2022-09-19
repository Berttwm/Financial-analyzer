#pragma once
#include "Statements.h"

class IncomeStatement : public Statements<IncomeStatementMetrics>
{
protected:
	void processDocumentObject(rapidjson::Document& doc) override;
	void addToMap(IncomeStatementMetrics metric, std::string) override;

public:
	IncomeStatement(rapidjson::Document& d_inc_stmt);
	std::string getKeyFromMap(IncomeStatementMetrics statementMetric, int year_from) const;
	int get_num_years_collected() const;
};