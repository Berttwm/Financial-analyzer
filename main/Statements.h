#pragma once
//#include "StockUtils.h"

template <class T> class Statements
{
protected:
	std::unordered_map<T, std::vector<std::string>> metrics_yearly_map;
public:
	// push back value to metrics_yearly_map assigned vector
	virtual void addToMap(T metric, std::string value) = 0;

};