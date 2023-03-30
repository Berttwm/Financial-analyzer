#include "../../Header/Metric/ShortLongTermDebtRatio_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

ShortLongTermDebtRatio_MY::ShortLongTermDebtRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int ShortLongTermDebtRatio_fail_count = 0;
	long double ShortLongTermDebtRatio_prev = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double shortTermDebt = stock.get_BS_metric(BalanceSheetMetrics::shortTermDebt, 0);
		long double longTermDebt = stock.get_BS_metric(BalanceSheetMetrics::longTermDebt, 0);
		long double ShortLongTermDebtRatio_curr = shortTermDebt / longTermDebt;
		if (i == this->year_count - 1)
		{
			ShortLongTermDebtRatio_prev = ShortLongTermDebtRatio_curr;
			// first iteration skips comparison
			continue;
		}
		if (ShortLongTermDebtRatio_curr > 1)
		{
			ShortLongTermDebtRatio_fail_count++;
		}
		ShortLongTermDebtRatio_prev = ShortLongTermDebtRatio_curr;
	}
	this->set_performance(ShortLongTermDebtRatio_fail_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool ShortLongTermDebtRatio_MY::highScore()
{
	return this->performance == 0.0;
}

bool ShortLongTermDebtRatio_MY::medScore()
{
	return this->performance <= 1;
}

bool ShortLongTermDebtRatio_MY::lowScore()
{
	return this->performance <= 2;
}