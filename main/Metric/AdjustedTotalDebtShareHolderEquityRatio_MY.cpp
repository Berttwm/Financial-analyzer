#include "../../Header/Metric/AdjustedTotalDebtShareHolderEquityRatio_MY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

AdjustedTotalDebtShareHolderEquityRatio_MY::AdjustedTotalDebtShareHolderEquityRatio_MY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances, int year_count)
	: MetricMY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances, year_count)
{
	int AdjustedTotalDebtShareHolderEquityRatio_count = 0;
	// iterate from earliest date available (year_count) to latest date
	for (int i = this->year_count - 1; i >= 0; i--)
	{
		long double totalLiabilities = stock.get_BS_metric(BalanceSheetMetrics::totalLiabilities, i);
		long double totalStockholdersEquity = stock.get_BS_metric(BalanceSheetMetrics::totalStockholdersEquity, i);
		long double commonStockRepurchased = stock.get_CF_metric(CashFlowMetrics::commonStockRepurchased, i);
		long double AdjustedTotalDebtShareHolderEquityRatio_curr = totalLiabilities / (totalStockholdersEquity + commonStockRepurchased);

		if (AdjustedTotalDebtShareHolderEquityRatio_curr > 0.8)
		{
			AdjustedTotalDebtShareHolderEquityRatio_count++;
		}
	}
	this->set_performance(AdjustedTotalDebtShareHolderEquityRatio_count); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool AdjustedTotalDebtShareHolderEquityRatio_MY::highScore()
{
	return this->performance == 0.0;
}

bool AdjustedTotalDebtShareHolderEquityRatio_MY::medScore()
{
	return this->performance <= 1;
}

bool AdjustedTotalDebtShareHolderEquityRatio_MY::lowScore()
{
	return this->performance <= 2;
}