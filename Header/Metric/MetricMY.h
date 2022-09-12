#pragma once
#include "Metric.h"
/*
* Abstract `Multi Year` class to be inherited by concrete metric classes. The `MY` classes, unlike
* the `SY` classes, will additionally compute the number of years for which the metric will be calculated for
* The number of years will be the minimum of 1) number of years of data available, 2) specified number of years
* 
*
* The naming format of derived class should be `[MetricName]_[MetricYearType]`
*	MetricYearType = [ SY, MY ] (Single Year, Multi Year)
*		i.e. `Debt_MY` implies Debt_MultiYear
*
*/

template<MetricType MT, CategoryType... CTs>
class MetricMY : public Metric
{
private:
	int year_count; // Simply pass in desired testing period, constructor will decide actual number of years to use

	virtual bool highScore() = 0;
	virtual bool medScore() = 0;
	virtual bool lowScore() = 0;
	template<CategoryType... CTs>
	void updateCategoryScores()
	{
		this->categoryvector = { CTs... };
	};
	template<MetricType MT>
	void updateMetricScores()
	{
		this->metricvector = { MT };
	};
public:

	MetricMY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, int year_count)
		: Metric(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores),
		year_count(year_count) // TODO: Initialize this by comparing minimum of 1) number of years for testing period, number of years of data collected 
	{
		this->updateCategoryScores();
		this->updateMetricScores<MT>();
	};
};
