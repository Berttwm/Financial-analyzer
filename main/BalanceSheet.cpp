#include "../Header/BalanceSheet.h"
#include <iostream>
BalanceSheet::BalanceSheet(rapidjson::Document& d_bal_sheet)
{
	for (int i = 0; i < d_bal_sheet.GetStringLength(); i++) {
		//std::cout << "this is " << i << " " << d_bal_sheet[i]["symbol"].GetString() << std::endl;
		addToMap(BalanceSheetMetrics::date, d_bal_sheet[i]["date"].GetString());
		addToMap(BalanceSheetMetrics::symbol, d_bal_sheet[i]["symbol"].GetString());
		addToMap(BalanceSheetMetrics::reportedCurrency, d_bal_sheet[i]["reportedCurrency"].GetString());
		addToMap(BalanceSheetMetrics::cik, d_bal_sheet[i]["cik"].GetString());
		addToMap(BalanceSheetMetrics::fillingDate, d_bal_sheet[i]["fillingDate"].GetString());
		addToMap(BalanceSheetMetrics::acceptedDate, d_bal_sheet[i]["acceptedDate"].GetString());
		addToMap(BalanceSheetMetrics::calendarYear, d_bal_sheet[i]["calendarYear"].GetString());
		addToMap(BalanceSheetMetrics::period, d_bal_sheet[i]["period"].GetString());
		addToMap(BalanceSheetMetrics::cashAndCashEquivalents, std::to_string(d_bal_sheet[i]["cashAndCashEquivalents"].GetInt64()));
		addToMap(BalanceSheetMetrics::shortTermInvestments, std::to_string(d_bal_sheet[i]["shortTermInvestments"].GetInt64()));
		addToMap(BalanceSheetMetrics::cashAndShortTermInvestments, std::to_string(d_bal_sheet[i]["cashAndShortTermInvestments"].GetInt64()));
		addToMap(BalanceSheetMetrics::netReceivables, std::to_string(d_bal_sheet[i]["netReceivables"].GetInt64()));
		addToMap(BalanceSheetMetrics::inventory, std::to_string(d_bal_sheet[i]["inventory"].GetInt64()));
		addToMap(BalanceSheetMetrics::otherCurrentAssets, std::to_string(d_bal_sheet[i]["otherCurrentAssets"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalCurrentAssets, std::to_string(d_bal_sheet[i]["totalCurrentAssets"].GetInt64()));
		addToMap(BalanceSheetMetrics::propertyPlantEquipmentNet, std::to_string(d_bal_sheet[i]["propertyPlantEquipmentNet"].GetInt64()));
		addToMap(BalanceSheetMetrics::goodwill, std::to_string(d_bal_sheet[i]["goodwill"].GetInt64()));
		addToMap(BalanceSheetMetrics::intangibleAssets, std::to_string(d_bal_sheet[i]["intangibleAssets"].GetInt64()));
		addToMap(BalanceSheetMetrics::goodwillAndIntangibleAssets, std::to_string(d_bal_sheet[i]["goodwillAndIntangibleAssets"].GetInt64()));
		addToMap(BalanceSheetMetrics::longTermInvestments, std::to_string(d_bal_sheet[i]["longTermInvestments"].GetInt64()));
		addToMap(BalanceSheetMetrics::taxAssets, std::to_string(d_bal_sheet[i]["taxAssets"].GetInt64()));
		addToMap(BalanceSheetMetrics::otherNonCurrentAssets, std::to_string(d_bal_sheet[i]["otherNonCurrentAssets"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalNonCurrentAssets, std::to_string(d_bal_sheet[i]["totalNonCurrentAssets"].GetInt64()));
		addToMap(BalanceSheetMetrics::otherAssets, std::to_string(d_bal_sheet[i]["otherAssets"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalAssets, std::to_string(d_bal_sheet[i]["totalAssets"].GetInt64()));
		addToMap(BalanceSheetMetrics::accountPayables, std::to_string(d_bal_sheet[i]["accountPayables"].GetInt64()));
		addToMap(BalanceSheetMetrics::shortTermDebt, std::to_string(d_bal_sheet[i]["shortTermDebt"].GetInt64()));
		addToMap(BalanceSheetMetrics::taxPayables, std::to_string(d_bal_sheet[i]["taxPayables"].GetInt64()));
		addToMap(BalanceSheetMetrics::deferredRevenue, std::to_string(d_bal_sheet[i]["deferredRevenue"].GetInt64()));
		addToMap(BalanceSheetMetrics::otherCurrentLiabilities, std::to_string(d_bal_sheet[i]["otherCurrentLiabilities"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalCurrentLiabilities, std::to_string(d_bal_sheet[i]["totalCurrentLiabilities"].GetInt64()));
		addToMap(BalanceSheetMetrics::longTermDebt, std::to_string(d_bal_sheet[i]["longTermDebt"].GetInt64()));
		addToMap(BalanceSheetMetrics::deferredRevenueNonCurrent, std::to_string(d_bal_sheet[i]["deferredRevenueNonCurrent"].GetInt64()));
		addToMap(BalanceSheetMetrics::deferredTaxLiabilitiesNonCurrent, std::to_string(d_bal_sheet[i]["deferredTaxLiabilitiesNonCurrent"].GetInt64()));
		addToMap(BalanceSheetMetrics::otherNonCurrentLiabilities, std::to_string(d_bal_sheet[i]["otherNonCurrentLiabilities"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalNonCurrentLiabilities, std::to_string(d_bal_sheet[i]["totalNonCurrentLiabilities"].GetInt64()));
		addToMap(BalanceSheetMetrics::otherLiabilities, std::to_string(d_bal_sheet[i]["otherLiabilities"].GetInt64()));
		addToMap(BalanceSheetMetrics::capitalLeaseObligations, std::to_string(d_bal_sheet[i]["capitalLeaseObligations"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalLiabilities, std::to_string(d_bal_sheet[i]["totalLiabilities"].GetInt64()));
		addToMap(BalanceSheetMetrics::preferredStock, std::to_string(d_bal_sheet[i]["preferredStock"].GetInt64()));
		addToMap(BalanceSheetMetrics::commonStock, std::to_string(d_bal_sheet[i]["commonStock"].GetInt64()));
		addToMap(BalanceSheetMetrics::retainedEarnings, std::to_string(d_bal_sheet[i]["retainedEarnings"].GetInt64()));
		addToMap(BalanceSheetMetrics::accumulatedOtherComprehensiveIncomeLoss, std::to_string(d_bal_sheet[i]["accumulatedOtherComprehensiveIncomeLoss"].GetInt64()));
		addToMap(BalanceSheetMetrics::othertotalStockholdersEquity, std::to_string(d_bal_sheet[i]["othertotalStockholdersEquity"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalStockholdersEquity, std::to_string(d_bal_sheet[i]["totalStockholdersEquity"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalLiabilitiesAndStockholdersEquity, std::to_string(d_bal_sheet[i]["totalLiabilitiesAndStockholdersEquity"].GetInt64()));
		addToMap(BalanceSheetMetrics::minorityInterest, std::to_string(d_bal_sheet[i]["minorityInterest"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalEquity, std::to_string(d_bal_sheet[i]["totalEquity"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalLiabilitiesAndTotalEquity, std::to_string(d_bal_sheet[i]["totalLiabilitiesAndTotalEquity"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalInvestments, std::to_string(d_bal_sheet[i]["totalInvestments"].GetInt64()));
		addToMap(BalanceSheetMetrics::totalDebt, std::to_string(d_bal_sheet[i]["totalDebt"].GetInt64()));
		addToMap(BalanceSheetMetrics::netDebt, std::to_string(d_bal_sheet[i]["netDebt"].GetInt64()));
		addToMap(BalanceSheetMetrics::link, d_bal_sheet[i]["link"].GetString());
		addToMap(BalanceSheetMetrics::finalLink, d_bal_sheet[i]["finalLink"].GetString());
		//std::cout << "END" << std::endl;
	}
}
void BalanceSheet::addToMap(BalanceSheetMetrics metric, std::string value)
{
	// TODO: Check if need to check if this current mapping is empty.
	//this->metrics_yearly_map[metric].push_back(value);
	// check if key-value pair in Map
	if (this->metrics_yearly_map.count(metric) == 0) {
		std::vector<std::string> vect;
		vect.push_back(value);
		this->metrics_yearly_map.insert({ metric, vect });
	}
	else {
		this->metrics_yearly_map[metric].push_back(value);
	}
}