#include "../../Header/Metric/AdjustedTotalDebtShareHolderEquityRatio_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

AdjustedTotalDebtShareHolderEquityRatio_SY::AdjustedTotalDebtShareHolderEquityRatio_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double totalLiabilities = stock.get_BS_metric(BalanceSheetMetrics::totalLiabilities, 0);
	long double totalStockholdersEquity = stock.get_BS_metric(BalanceSheetMetrics::totalStockholdersEquity, 0);
	long double commonStockRepurchased = stock.get_CF_metric(CashFlowMetrics::commonStockRepurchased, 0);
	this->set_performance(totalLiabilities / (totalStockholdersEquity + commonStockRepurchased)); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool AdjustedTotalDebtShareHolderEquityRatio_SY::highScore()
{
	return (this->performance <= 0.8);
}

bool AdjustedTotalDebtShareHolderEquityRatio_SY::medScore()
{
	return (this->performance <= 0.9);
}

bool AdjustedTotalDebtShareHolderEquityRatio_SY::lowScore()
{
	return (this->performance <= 1);
}