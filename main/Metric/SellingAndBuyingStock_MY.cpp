#include "../../Header/Metric/SellingAndBuyingStock_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

SellingAndBuyingStock_MY::SellingAndBuyingStock_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int stockbuyback_fail_count = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double commonStockRepurchased = stock.get_CF_metric(CashFlowMetrics::commonStockRepurchased, i);
		if (i == this->year_count - 1)
		{
			continue;
		}
		if (commonStockRepurchased <= 0)
		{
			stockbuyback_fail_count++;
		}
	}
	this->set_performance(stockbuyback_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool SellingAndBuyingStock_MY::highScore()
{
	//return this->performance >= 0.3;
	return false;
}

bool SellingAndBuyingStock_MY::medScore()
{
	return false;
}

bool SellingAndBuyingStock_MY::lowScore()
{
	return false;
}