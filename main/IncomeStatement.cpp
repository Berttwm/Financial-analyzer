#include "../Header/IncomeStatement.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

IncomeStatement::IncomeStatement(rapidjson::Document& d_inc_stmt)
{
	this->processDocumentObject(d_inc_stmt);
}

void IncomeStatement::processDocumentObject(rapidjson::Document& doc)
{
	for (int i = 0; i < doc.GetStringLength(); i++) {
		for (auto metric_pair : IncomeStatementMetricsStrings) {
			IncomeStatementMetrics enum_metric = metric_pair.first;
			const char* metric = (metric_pair.second.c_str());
			if (doc[i][metric].IsString()) {
				addToMap(enum_metric, doc[i][metric].GetString());
			}
			else if (doc[i][metric].IsInt64()) {		
				addToMap(enum_metric, std::to_string(doc[i][metric].GetInt64()));
			}
			else if (doc[i][metric].IsDouble()) {
				std::ostringstream streamObj;
				streamObj << std::setprecision(17);
				streamObj << doc[i][metric].GetDouble();;
				addToMap(enum_metric, streamObj.str());
				streamObj.str("");
			}
			else {
				std::cout << "IncStmtError: No such data type." << std::endl;
				std::cout << metric << std::endl;
			}
		}
	}
	for (auto& it : this->metrics_yearly_map)
	{
		std::cout << IncomeStatementMetricsStrings.find(it.first)->second << ": ";
		for (auto& x : it.second)
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

long double IncomeStatement::getKeyFromMap(IncomeStatementMetrics statementMetric, int year_from) const
{
	long double key = std::stold(this->metrics_yearly_map.find(statementMetric)->second[0]);
	std::cout << std::setprecision(17) << "IncStmt getKeyFromMap = " << key << std::endl;
	return key;
}

int IncomeStatement::get_num_years_collected() const
{
	return this->metrics_yearly_map.find(IncomeStatementMetrics::date)->second.size();
}
