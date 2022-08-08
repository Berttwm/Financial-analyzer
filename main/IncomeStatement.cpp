#include "../Header/IncomeStatement.h"

IncomeStatement::IncomeStatement(rapidjson::Document& d_inc_stmt)
{

}


void IncomeStatement::addToMap(IncomeStatementMetrics metric, std::string value)
{
	// TODO: Check if need to check if this current mapping is empty.
	//this->metrics_yearly_map[metric].push_back(value);
}