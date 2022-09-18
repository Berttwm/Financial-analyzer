#pragma once
#include "Statements.h"

class BalanceSheet : public Statements<BalanceSheetMetrics>
{
private:
	// Need to make sure vector ordering follows the enum metrics
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
		"cashAndCashEquivalents",
		"shortTermInvestments",
		"cashAndShortTermInvestments",
		"netReceivables",
		"inventory",
		"otherCurrentAssets",
		"totalCurrentAssets",
		"propertyPlantEquipmentNet",
		"goodwill",
		"intangibleAssets",
		"goodwillAndIntangibleAssets",
		"longTermInvestments",
		"taxAssets",
		"otherNonCurrentAssets",
		"totalNonCurrentAssets",
		"otherAssets",
		"totalAssets",
		"accountPayables",
		"shortTermDebt",
		"taxPayables",
		"deferredRevenue",
		"otherCurrentLiabilities",
		"totalCurrentLiabilities",
		"longTermDebt",
		"deferredRevenueNonCurrent",
		"deferredTaxLiabilitiesNonCurrent",
		"otherNonCurrentLiabilities",
		"totalNonCurrentLiabilities",
		"otherLiabilities",
		"capitalLeaseObligations",
		"totalLiabilities",
		"preferredStock",
		"commonStock",
		"retainedEarnings",
		"accumulatedOtherComprehensiveIncomeLoss",
		"othertotalStockholdersEquity",
		"totalStockholdersEquity",
		"totalLiabilitiesAndStockholdersEquity",
		"minorityInterest",
		"totalEquity",
		"totalLiabilitiesAndTotalEquity",
		"totalInvestments",
		"totalDebt",
		"netDebt",
		"link",
		"finalLink"
	};
public:
	BalanceSheet(rapidjson::Document& d_bal_sheet);
	void addToMap(BalanceSheetMetrics metric, std::string);
	void addToMapInt(BalanceSheetMetrics metric, std::int64_t);
	void addToMapDouble(BalanceSheetMetrics metric, double);
	std::string getKeyFromMap(BalanceSheetMetrics statementMetric, int year_from) const;
	int get_num_years_collected() const;
};