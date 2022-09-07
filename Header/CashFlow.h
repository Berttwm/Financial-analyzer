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
	void addToMap(CashFlowMetrics metric, std::int64_t);
	void addToMap(CashFlowMetrics metric, double);
};