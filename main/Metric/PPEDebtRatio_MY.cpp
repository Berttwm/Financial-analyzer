#include "../../Header/Metric/PPEDebtRatio_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

PPEDebtRatio_MY::PPEDebtRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int PPEDebtRatio_fail_count = 0;
	long double PPEDebtRatio_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double propertyPlantEquipmentNet = stock.get_BS_metric(BalanceSheetMetrics::propertyPlantEquipmentNet, 0);
		long double totalDebt = stock.get_BS_metric(BalanceSheetMetrics::totalDebt, 0);
		long double PPEDebtRatio_curr = propertyPlantEquipmentNet / totalDebt;
		if (i == this->year_count - 1)
		{
			PPEDebtRatio_prev = PPEDebtRatio_curr;
			// first iteration skips comparison
			continue;
		}
		if (PPEDebtRatio_curr > 2)
		{
			PPEDebtRatio_fail_count++;
		}
		PPEDebtRatio_prev = PPEDebtRatio_curr;
	}
	this->set_performance(PPEDebtRatio_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool PPEDebtRatio_MY::highScore()
{
	return this->performance == 0.0;
}

bool PPEDebtRatio_MY::medScore()
{
	return this->performance <= 1;
}

bool PPEDebtRatio_MY::lowScore()
{
	return this->performance <= 2;
}