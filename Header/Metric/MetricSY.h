#pragma once
#include "Metric.h"
/*
* Abstract `Single Year` class to be inherited by concrete metric classes. The `SY` classes
* offer no additional details from the `Metric.h` abstraction. It servers as a distinction between 
* the `MetricMY` abstract classes.
*
* The naming format of derived class should be `[MetricName]_[MetricYearType]`
*	MetricYearType = [ SY, MY ] (Single Year, Multi Year)
*		i.e. `Debt_SY` implies Debt_SingleYear
*
*/

template<MetricType MT, CategoryType... CTs>
class MetricSY : public Metric
{
private:
	virtual bool highScore() = 0;
	virtual bool medScore() = 0;
	virtual bool lowScore() = 0;
	template<CategoryType... CT>
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

	MetricSY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, double>* MetricPerformance)
		: Metric(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformance)
	{
		this->updateCategoryScores();
		this->updateMetricScores<MT>();
		// Step 3: Update Performance for this metric
		auto it = this->MetricPerformance->find(MT);
		if (it != this->MetricPerformance->end())
			it->second = this->performance;
	};
};
