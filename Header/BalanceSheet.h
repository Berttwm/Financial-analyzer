#pragma once
#include "Statements.h"

class BalanceSheet : public Statements<BalanceSheetMetrics>
{
protected:
	void processDocumentObject(rapidjson::Document& doc) override;
	void addToMap(BalanceSheetMetrics metric, std::string) override;

public:
	BalanceSheet(rapidjson::Document& d_bal_sheet);
	long double getKeyFromMap(BalanceSheetMetrics statementMetric, int year_from) const;
	int get_num_years_collected() const;
};