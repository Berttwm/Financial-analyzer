#pragma once
//#include "StockUtils.h"
/* Statements Class 
* Abstract class to support IncomeStatement, BalanceSheet and CashFlow class
*/
template <class T> class Statements
{
protected:
	/* Metrics yearly map -
	* Key: Metrics enum class (i.e. enum class IncomeStatementMetrics)
	* Value: vector of corresponding metric values yearly
	*	as idx increases, the number of years apart increases
	*	example when latest year on statements is 2021: 
	*		vector[0] = 2021 <value> (latest year)
	*		vector[5] = 2016 <value> (Year 2021 - 5 = Year 2016)
	* 
	* Use Cases:
	*	metrics_yearly_map["revenue"][0] gives you the latest value for "revenue" in the latest year
	*	metrics_yearly_map["grossProfit"][2] gives you the latest value for "grossProfit" for 2 years prior
	*/
	std::unordered_map<T, std::vector<std::string>> metrics_yearly_map;
public:
	// push back value to metrics_yearly_map assigned vector
	virtual void addToMap(T metric, std::string value) = 0;

};