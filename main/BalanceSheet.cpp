#include "../Header/BalanceSheet.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

BalanceSheet::BalanceSheet(rapidjson::Document& d_bal_sheet)
{
	for (int i = 0; i < d_bal_sheet.GetStringLength(); i++) {
		for (int j = 0; j < statement_to_string_vect.size(); j++) {
			// Need to make sure stmt vector has the same ordering as metrics enum
			const char* metric = (statement_to_string_vect[j].c_str());
			BalanceSheetMetrics enum_metric = BalanceSheetMetrics(j);
			if (d_bal_sheet[i][metric].IsString()) {
				addToMap(enum_metric, d_bal_sheet[i][metric].GetString());
			}
			else if (d_bal_sheet[i][metric].IsInt64()) {
				addToMap(enum_metric, d_bal_sheet[i][metric].GetInt64());
			}
			else if (d_bal_sheet[i][metric].IsDouble()) {
				addToMap(enum_metric, d_bal_sheet[i][metric].GetDouble());
			}
			else {
				printf("Error: No such data type.");
			}
		}
	}

	// print test
	for (auto& it : this->metrics_yearly_map)
	{
		std::cout << "BalanceSheetMetrics::" << this->statement_to_string_vect[static_cast<int>(it.first)] << " :\t";
		for (auto& x : it.second)
		{
			std::cout << x << ",";
		}
		std::cout << std::endl;
	}
}

void BalanceSheet::addToMap(BalanceSheetMetrics metric, std::int64_t value) 
{
	addToMap(metric, std::to_string(value));
}

void BalanceSheet::addToMap(BalanceSheetMetrics metric, double value)
{
	// create stream to take in double variables and set to precision of 17
	std::ostringstream streamObj;
	streamObj << std::setprecision(17);
	streamObj << value;
	addToMap(metric, streamObj.str());
	streamObj.str("");
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

std::string BalanceSheet::getKeyFromMap(BalanceSheetMetrics statementMetric, int year_from) const
{
	return this->metrics_yearly_map.find(statementMetric)->second[year_from];
}

int BalanceSheet::get_num_years_collected() const
{
	return this->metrics_yearly_map.find(BalanceSheetMetrics::date)->second.size();
}