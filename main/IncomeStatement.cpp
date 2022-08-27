#include "../Header/IncomeStatement.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

IncomeStatement::IncomeStatement(rapidjson::Document& d_inc_stmt)
{
	//std::cout << "INCOME STATEMENT TEST = " << d_inc_stmt.GetStringLength() << std::endl;

	for (int i = 0; i < d_inc_stmt.GetStringLength(); i++) {
		//std::cout << "this is " << i << " " << d_inc_stmt[i]["date"].GetString() << std::endl;
		// create stream to take in double variables and set to precision of 17
		std::ostringstream streamObj;
		streamObj << std::setprecision(17);
		addToMap(IncomeStatementMetrics::date, d_inc_stmt[i]["date"].GetString());
		addToMap(IncomeStatementMetrics::symbol, d_inc_stmt[i]["symbol"].GetString());
		addToMap(IncomeStatementMetrics::reportedCurrency, d_inc_stmt[i]["reportedCurrency"].GetString());
		addToMap(IncomeStatementMetrics::cik, d_inc_stmt[i]["cik"].GetString());
		addToMap(IncomeStatementMetrics::fillingDate, d_inc_stmt[i]["fillingDate"].GetString());
		addToMap(IncomeStatementMetrics::acceptedDate, d_inc_stmt[i]["acceptedDate"].GetString());
		addToMap(IncomeStatementMetrics::calendarYear, d_inc_stmt[i]["calendarYear"].GetString());
		addToMap(IncomeStatementMetrics::period, d_inc_stmt[i]["period"].GetString());
		addToMap(IncomeStatementMetrics::revenue, std::to_string(d_inc_stmt[i]["revenue"].GetInt64()));
		addToMap(IncomeStatementMetrics::costOfRevenue, std::to_string(d_inc_stmt[i]["costOfRevenue"].GetInt64()));
		addToMap(IncomeStatementMetrics::grossProfit, std::to_string(d_inc_stmt[i]["grossProfit"].GetInt64()));
		// change precision gross profit ratio
		streamObj << d_inc_stmt[i]["grossProfitRatio"].GetDouble();
		addToMap(IncomeStatementMetrics::grossProfitRatio, streamObj.str());
		streamObj.str("");
		addToMap(IncomeStatementMetrics::researchAndDevelopmentExpenses, std::to_string(d_inc_stmt[i]["researchAndDevelopmentExpenses"].GetInt64()));
		addToMap(IncomeStatementMetrics::generalAndAdministrativeExpenses, std::to_string(d_inc_stmt[i]["generalAndAdministrativeExpenses"].GetInt64()));
		addToMap(IncomeStatementMetrics::sellingAndMarketingExpenses, std::to_string(d_inc_stmt[i]["sellingAndMarketingExpenses"].GetInt64()));
		addToMap(IncomeStatementMetrics::sellingGeneralAndAdministrativeExpenses, std::to_string(d_inc_stmt[i]["sellingGeneralAndAdministrativeExpenses"].GetInt64()));
		addToMap(IncomeStatementMetrics::otherExpenses, std::to_string(d_inc_stmt[i]["otherExpenses"].GetInt64()));
		addToMap(IncomeStatementMetrics::operatingExpenses, std::to_string(d_inc_stmt[i]["operatingExpenses"].GetInt64()));
		addToMap(IncomeStatementMetrics::costAndExpenses, std::to_string(d_inc_stmt[i]["costAndExpenses"].GetInt64()));
		addToMap(IncomeStatementMetrics::interestIncome, std::to_string(d_inc_stmt[i]["interestIncome"].GetInt64()));
		addToMap(IncomeStatementMetrics::interestExpense, std::to_string(d_inc_stmt[i]["interestExpense"].GetInt64()));
		addToMap(IncomeStatementMetrics::depreciationAndAmortization, std::to_string(d_inc_stmt[i]["depreciationAndAmortization"].GetInt64()));
		addToMap(IncomeStatementMetrics::ebitda, std::to_string(d_inc_stmt[i]["ebitda"].GetInt64()));
		// change precision ebita ratio
		streamObj << d_inc_stmt[i]["ebitdaratio"].GetDouble();
		addToMap(IncomeStatementMetrics::ebitdaratio, streamObj.str());
		streamObj.str("");
		addToMap(IncomeStatementMetrics::operatingIncome, std::to_string(d_inc_stmt[i]["operatingIncome"].GetInt64()));
		// change precision operating income ratio
		streamObj << d_inc_stmt[i]["operatingIncomeRatio"].GetDouble();
		addToMap(IncomeStatementMetrics::operatingIncomeRatio, streamObj.str());
		streamObj.str("");
		addToMap(IncomeStatementMetrics::totalOtherIncomeExpensesNet, std::to_string(d_inc_stmt[i]["totalOtherIncomeExpensesNet"].GetInt64()));
		addToMap(IncomeStatementMetrics::incomeBeforeTax, std::to_string(d_inc_stmt[i]["incomeBeforeTax"].GetInt64()));
		// change precision income before tax ratio
		streamObj << d_inc_stmt[i]["incomeBeforeTaxRatio"].GetDouble();
		addToMap(IncomeStatementMetrics::incomeBeforeTaxRatio, streamObj.str());
		streamObj.str("");
		addToMap(IncomeStatementMetrics::incomeTaxExpense, std::to_string(d_inc_stmt[i]["incomeTaxExpense"].GetInt64()));
		addToMap(IncomeStatementMetrics::netIncome, std::to_string(d_inc_stmt[i]["netIncome"].GetInt64()));
		// change precision net income ratio
		streamObj << d_inc_stmt[i]["netIncomeRatio"].GetDouble();
		addToMap(IncomeStatementMetrics::netIncomeRatio, streamObj.str());
		streamObj.str("");
		addToMap(IncomeStatementMetrics::eps, std::to_string(d_inc_stmt[i]["eps"].GetDouble()));
		addToMap(IncomeStatementMetrics::epsdiluted, std::to_string(d_inc_stmt[i]["epsdiluted"].GetDouble()));
		addToMap(IncomeStatementMetrics::weightedAverageShsOut, std::to_string(d_inc_stmt[i]["weightedAverageShsOut"].GetInt64()));
		addToMap(IncomeStatementMetrics::weightedAverageShsOutDil, std::to_string(d_inc_stmt[i]["weightedAverageShsOutDil"].GetInt64()));
		addToMap(IncomeStatementMetrics::link, d_inc_stmt[i]["link"].GetString());
		addToMap(IncomeStatementMetrics::finalLink, d_inc_stmt[i]["finalLink"].GetString());	
		//std::cout << "END" << std::endl;
	}

	// print test
	for (auto& it : this->metrics_yearly_map)
	{
		std::cout << "IncomeStatementMetrics::" << this->statement_to_string_vect[static_cast<int>(it.first)] << " :\t";
		for (auto &x : it.second)
		{
			std::cout << x << ",";
		}
		std::cout << std::endl;
	}
}


void IncomeStatement::addToMap(IncomeStatementMetrics metric, std::string value)
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