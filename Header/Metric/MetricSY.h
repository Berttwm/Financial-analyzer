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
	void updateCategoryScores()
	{
		this->categoryvector = { CTs... };
	};
	void updateMetricScores()
	{
		this->metricvector = { MT };
	};
protected:
	/* updateMetricPerformance() - Only called **AFTER** performance has been set!
	*	Updates the std::unordered_map MetricPerformances with the performance score of current metric.
	*/
	void updateMetricPerformances()
	{
		auto it = this->MetricPerformances->find(MT); // TODO FIX THIS
		if (it != this->MetricPerformances->end())
			//std::cout << this->MetricPerformances << std::endl;
		it->second = this->performance;
	};
public:

	MetricSY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double> *MetricPerformances)
		: Metric(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
	{
		this->updateCategoryScores();
		this->updateMetricScores();
	};
};
