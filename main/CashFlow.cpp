#include "../Header/CashFlow.h"
#include <iostream>
CashFlow::CashFlow(rapidjson::Document& d_cash_flow)
{
	for (int i = 0; i < d_cash_flow.GetStringLength(); i++) {
		//std::cout << "this is " << i << " " << d_cash_flow[i]["cik"].GetString() << std::endl;
		addToMap(CashFlowMetrics::date, d_cash_flow[i]["date"].GetString());
		addToMap(CashFlowMetrics::symbol, d_cash_flow[i]["symbol"].GetString());
		addToMap(CashFlowMetrics::reportedCurrency, d_cash_flow[i]["reportedCurrency"].GetString());
		addToMap(CashFlowMetrics::cik, d_cash_flow[i]["cik"].GetString());
		addToMap(CashFlowMetrics::fillingDate, d_cash_flow[i]["fillingDate"].GetString());
		addToMap(CashFlowMetrics::acceptedDate, d_cash_flow[i]["acceptedDate"].GetString());
		addToMap(CashFlowMetrics::calendarYear, d_cash_flow[i]["calendarYear"].GetString());
		addToMap(CashFlowMetrics::period, d_cash_flow[i]["period"].GetString());
		addToMap(CashFlowMetrics::netIncome, std::to_string(d_cash_flow[i]["netIncome"].GetInt64()));
		addToMap(CashFlowMetrics::depreciationAndAmortization, std::to_string(d_cash_flow[i]["depreciationAndAmortization"].GetInt64()));
		addToMap(CashFlowMetrics::deferredIncomeTax, std::to_string(d_cash_flow[i]["deferredIncomeTax"].GetInt64()));
		addToMap(CashFlowMetrics::stockBasedCompensation, std::to_string(d_cash_flow[i]["stockBasedCompensation"].GetInt64()));
		addToMap(CashFlowMetrics::changeInWorkingCapital, std::to_string(d_cash_flow[i]["changeInWorkingCapital"].GetInt64()));
		addToMap(CashFlowMetrics::accountsReceivables, std::to_string(d_cash_flow[i]["accountsReceivables"].GetInt64()));
		addToMap(CashFlowMetrics::inventory, std::to_string(d_cash_flow[i]["inventory"].GetInt64()));
		addToMap(CashFlowMetrics::accountsPayables, std::to_string(d_cash_flow[i]["accountsPayables"].GetInt64()));
		addToMap(CashFlowMetrics::otherWorkingCapital, std::to_string(d_cash_flow[i]["otherWorkingCapital"].GetInt64()));
		addToMap(CashFlowMetrics::otherNonCashItems, std::to_string(d_cash_flow[i]["otherNonCashItems"].GetInt64()));
		addToMap(CashFlowMetrics::netCashProvidedByOperatingActivities, std::to_string(d_cash_flow[i]["netCashProvidedByOperatingActivities"].GetInt64()));
		addToMap(CashFlowMetrics::investmentsInPropertyPlantAndEquipment, std::to_string(d_cash_flow[i]["investmentsInPropertyPlantAndEquipment"].GetInt64()));
		addToMap(CashFlowMetrics::acquisitionsNet, std::to_string(d_cash_flow[i]["acquisitionsNet"].GetInt64()));
		addToMap(CashFlowMetrics::purchasesOfInvestments, std::to_string(d_cash_flow[i]["purchasesOfInvestments"].GetInt64()));
		addToMap(CashFlowMetrics::salesMaturitiesOfInvestments, std::to_string(d_cash_flow[i]["salesMaturitiesOfInvestments"].GetInt64()));
		addToMap(CashFlowMetrics::otherInvestingActivites, std::to_string(d_cash_flow[i]["otherInvestingActivites"].GetInt64()));
		addToMap(CashFlowMetrics::netCashUsedForInvestingActivites, std::to_string(d_cash_flow[i]["netCashUsedForInvestingActivites"].GetInt64()));
		addToMap(CashFlowMetrics::debtRepayment, std::to_string(d_cash_flow[i]["debtRepayment"].GetInt64()));
		addToMap(CashFlowMetrics::commonStockIssued, std::to_string(d_cash_flow[i]["commonStockIssued"].GetInt64()));
		addToMap(CashFlowMetrics::commonStockRepurchased, std::to_string(d_cash_flow[i]["commonStockRepurchased"].GetInt64()));
		addToMap(CashFlowMetrics::dividendsPaid, std::to_string(d_cash_flow[i]["dividendsPaid"].GetInt64()));
		addToMap(CashFlowMetrics::otherFinancingActivites, std::to_string(d_cash_flow[i]["otherFinancingActivites"].GetInt64()));
		addToMap(CashFlowMetrics::netCashUsedProvidedByFinancingActivities, std::to_string(d_cash_flow[i]["netCashUsedProvidedByFinancingActivities"].GetInt64()));
		addToMap(CashFlowMetrics::effectOfForexChangesOnCash, std::to_string(d_cash_flow[i]["effectOfForexChangesOnCash"].GetInt64()));
		addToMap(CashFlowMetrics::netChangeInCash, std::to_string(d_cash_flow[i]["netChangeInCash"].GetInt64()));
		addToMap(CashFlowMetrics::cashAtEndOfPeriod, std::to_string(d_cash_flow[i]["cashAtEndOfPeriod"].GetInt64()));
		addToMap(CashFlowMetrics::cashAtBeginningOfPeriod, std::to_string(d_cash_flow[i]["cashAtBeginningOfPeriod"].GetInt64()));
		addToMap(CashFlowMetrics::operatingCashFlow, std::to_string(d_cash_flow[i]["operatingCashFlow"].GetInt64()));
		addToMap(CashFlowMetrics::capitalExpenditure, std::to_string(d_cash_flow[i]["capitalExpenditure"].GetInt64()));
		addToMap(CashFlowMetrics::freeCashFlow, std::to_string(d_cash_flow[i]["freeCashFlow"].GetInt64()));
		addToMap(CashFlowMetrics::link, d_cash_flow[i]["link"].GetString());
		addToMap(CashFlowMetrics::finalLink, d_cash_flow[i]["finalLink"].GetString());
		//std::cout << "END" << std::endl;
	}

	// print test
	for (auto& it : this->metrics_yearly_map)
	{
		std::cout << "CashFlowMetrics::" << this->statement_to_string_vect[static_cast<int>(it.first)] << " :\t";
		for (auto& x : it.second)
		{
			std::cout << x << ",";
		}
		std::cout << std::endl;
	}
}
void CashFlow::addToMap(CashFlowMetrics metric, std::string value)
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