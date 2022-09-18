#pragma once
#include "Statements.h"

class CashFlow : public Statements<CashFlowMetrics>
{
private:
	std::vector<std::string> statement_to_string_vect =
	{
		"date",
		"symbol",
		"reportedCurrency",
		"cik",
		"fillingDate",
		"acceptedDate",
		"calendarYear",
		"period",
		"netIncome",
		"depreciationAndAmortization",
		"deferredIncomeTax",
		"stockBasedCompensation",
		"changeInWorkingCapital",
		"accountsReceivables",
		"inventory",
		"accountsPayables",
		"otherWorkingCapital",
		"otherNonCashItems",
		"netCashProvidedByOperatingActivities",
		"investmentsInPropertyPlantAndEquipment",
		"acquisitionsNet",
		"purchasesOfInvestments",
		"salesMaturitiesOfInvestments",
		"otherInvestingActivites",
		"netCashUsedForInvestingActivites",
		"debtRepayment",
		"commonStockIssued",
		"commonStockRepurchased",
		"dividendsPaid",
		"otherFinancingActivites",
		"netCashUsedProvidedByFinancingActivities",
		"effectOfForexChangesOnCash",
		"netChangeInCash",
		"cashAtEndOfPeriod",
		"cashAtBeginningOfPeriod",
		"operatingCashFlow",
		"capitalExpenditure",
		"freeCashFlow",
		"link",
		"finalLink",
	};
public:
	CashFlow(rapidjson::Document& d_cash_flow);
	void addToMap(CashFlowMetrics metric, std::string);
	void addToMapInt(CashFlowMetrics metric, std::int64_t);
	void addToMapDouble(CashFlowMetrics metric, double);
	std::string getKeyFromMap(CashFlowMetrics statementMetric, int year_from) const;
	int get_num_years_collected() const;
};