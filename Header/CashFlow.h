#pragma once
#include "Statements.h"

class CashFlow : public Statements<CashFlowMetrics>
{
protected:
	void processDocumentObject(rapidjson::Document& doc) override;
	void addToMap(CashFlowMetrics metric, std::string) override;

public:
	CashFlow(rapidjson::Document& d_cash_flow);
	long double getKeyFromMap(CashFlowMetrics statementMetric, int year_from) const;
	int get_num_years_collected() const;
};