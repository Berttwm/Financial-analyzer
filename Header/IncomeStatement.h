#pragma once
#include "Statements.h"

class IncomeStatement : public Statements<IncomeStatementMetrics>
{
private:
	// Need to make sure vector ordering follows the enum class
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
		"revenue",
		"costOfRevenue",
		"grossProfit",
		"grossProfitRatio",
		"researchAndDevelopmentExpenses",
		"generalAndAdministrativeExpenses",
		"sellingAndMarketingExpenses",
		"sellingGeneralAndAdministrativeExpenses",
		"otherExpenses",
		"operatingExpenses",
		"costAndExpenses",
		"interestIncome",
		"interestExpense",
		"depreciationAndAmortization",
		"ebitda",
		"ebitdaratio",
		"operatingIncome",
		"operatingIncomeRatio",
		"totalOtherIncomeExpensesNet",
		"incomeBeforeTax",
		"incomeBeforeTaxRatio",
		"incomeTaxExpense",
		"netIncome",
		"netIncomeRatio",
		"eps",
		"epsdiluted",
		"weightedAverageShsOut",
		"weightedAverageShsOutDil",
		"link",
		"finalLink",
	};
public:
	IncomeStatement(rapidjson::Document& d_inc_stmt);
	void addToMap(IncomeStatementMetrics metric, std::string);
	void addToMap(IncomeStatementMetrics metric, std::int64_t);
	void addToMap(IncomeStatementMetrics metric, double);
};