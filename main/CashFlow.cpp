#include "../Header/CashFlow.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

CashFlow::CashFlow(rapidjson::Document& d_cash_flow)
{
	for (int i = 0; i < d_cash_flow.GetStringLength(); i++) {
		for (auto metric_pair : CashFlowMetricsStrings) {
			CashFlowMetrics enum_metric = metric_pair.first;
			const char* metric = (metric_pair.second.c_str());
			if (d_cash_flow[i][metric].IsString()) {
				addToMap(enum_metric, d_cash_flow[i][metric].GetString());
			}
			else if (d_cash_flow[i][metric].IsInt64()) {
				addToMapInt(enum_metric, d_cash_flow[i][metric].GetInt64());
			}
			else if (d_cash_flow[i][metric].IsDouble()) {
				addToMapDouble(enum_metric, d_cash_flow[i][metric].GetDouble());
			}
			else {
				std::cout << "CashFlowError: No such data type." << std::endl;
				std::cout << metric << std::endl;
			}
		}
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

void CashFlow::addToMapInt(CashFlowMetrics metric, std::int64_t value)
{
	addToMap(metric, std::to_string(value));
}

void CashFlow::addToMapDouble(CashFlowMetrics metric, double value)
{
	// create stream to take in double variables and set to precision of 17
	std::ostringstream streamObj;
	streamObj << std::setprecision(17);
	streamObj << value;
	addToMap(metric, streamObj.str());
	streamObj.str("");
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

std::string CashFlow::getKeyFromMap(CashFlowMetrics statementMetric, int year_from) const
{
	return this->metrics_yearly_map.find(statementMetric)->second[year_from];
}

int CashFlow::get_num_years_collected() const
{
	return this->metrics_yearly_map.find(CashFlowMetrics::date)->second.size();
}