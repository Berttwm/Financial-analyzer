#pragma once

#include "ScorerUtils.h"
#include "Stock.h"

// Include statements for metrics to be scored
#include "Metric/GrossProfitMargin_SY.h"
#include "Metric/SGA_SY.h"
#include "Metric/OperatingExpenses_MY.h"
#include "Metric/SGA_MY.h"
#include "Metric/RND_SY.h"
#include "Metric/RND_MY.h"
#include "Metric/Depreciation_SY.h"
#include "Metric/Depreciation_MY.h"
#include "Metric/InterestExpense_SY.h"
#include "Metric/InterestExpense_MY.h"
#include "Metric/NetEarnings_MY.h"
#include "Metric/NetEarningsOverRevenue_MY.h"
#include "Metric/NegativeEarnings_MY.h"
#include "Metric/EarningsGrowth_MY.h"
#include "Metric/DebtRatio_SY.h"
#include "Metric/DebtRatio_MY.h"
#include "Metric/TotalInventory_MY.h"
#include "Metric/SellingAndBuyingStock_MY.h"
#include "Metric/CapexMargin_SY.h"
#include "Metric/CapexMargin_MY.h"

/* To take in a stock object and provide interface for scoring system */
class Scorer
{
private:
	// Fixed variables
	const int MAX_SCORE = 10; // TODO: Change Max Score
	int CURR_SCORE = 0; // initial score
	
	// Derived variables
	const Stock& stock;

	// Scoring variables
	std::unordered_map<CategoryType, int> CategoryScores = // Score of each CategoryType, each category starts from 0
	{
		{CategoryType::Single, 0},
		{CategoryType::Multi, 0},
		{CategoryType::IncomeStatement, 0},
		{CategoryType::BalanceSheet, 0},
		{CategoryType::CashFlow , 0}
	};
	std::unordered_map<MetricType, int> MetricScores = // Score of each SheetType, each starts from 0
	{
		{MetricType::GrossProfitMargin_SY, 0},
	};
	std::unordered_map<CategoryType, int> MaxCategoryScores = // Max scores of each category. Incremented by 10 each time a category is added
	{
		{CategoryType::Single, 0},
		{CategoryType::Multi, 0},
		{CategoryType::IncomeStatement, 0},
		{CategoryType::BalanceSheet, 0},
		{CategoryType::CashFlow , 0}
	};
	std::unordered_map<MetricType, int> MaxMetricScores = // Max scores of each category. Incremented by 10 each time a category is added
	{
		// Income Statements
		{MetricType::GrossProfitMargin_SY, 0},
		{MetricType::SGA_SY, 0},
		{MetricType::OperatingExpenses_MY, 0},
		{MetricType::SGA_MY, 0},

		{MetricType::RND_SY, 0},
		{MetricType::RND_MY, 0},
		{MetricType::Depreciation_SY, 0},
		{MetricType::Depreciation_MY, 0},
		{MetricType::InterestExpense_SY, 0},
		{MetricType::InterestExpense_MY, 0},
		{MetricType::NetEarnings_MY, 0},
		{MetricType::NetEarningsOverRevenue_MY, 0},
		{MetricType::NegativeEarnings_MY, 0},
		{MetricType::EarningsGrowth_MY, 0},

		// Balance Sheets
		{MetricType::DebtRatio_SY, 0},
		{MetricType::DebtRatio_MY, 0},
		{MetricType::TotalInventory_MY, 0},
		// Cash Flows
		{MetricType::SellingAndBuyingStock_MY, 0},
		{MetricType::CapexMargin_SY, 0},
		{MetricType::CapexMargin_MY, 0},

	};

	std::unordered_map<MetricType, long double> MetricPerformances = // The actual datapoint collected from the metric. Percentages are represented as ratio (30% = 0.3)
	{
		// Income Statements
		{MetricType::GrossProfitMargin_SY, 0}, // GrossProfit/totalRevenue
		{MetricType::SGA_SY, 0},
		{MetricType::OperatingExpenses_MY, 0},
		{MetricType::SGA_MY, 0},

		{MetricType::RND_SY, 0},
		{MetricType::RND_MY, 0},
		{MetricType::Depreciation_SY, 0},
		{MetricType::Depreciation_MY, 0},
		{MetricType::InterestExpense_SY, 0},
		{MetricType::InterestExpense_MY, 0},
		{MetricType::NetEarnings_MY, 0},
		{MetricType::NetEarningsOverRevenue_MY, 0},
		{MetricType::NegativeEarnings_MY, 0},
		{MetricType::EarningsGrowth_MY, 0},
		// Balance Sheets
		{MetricType::DebtRatio_SY, 0},
		{MetricType::DebtRatio_MY, 0},
		{MetricType::TotalInventory_MY, 0},
		// Cash Flows
		{MetricType::SellingAndBuyingStock_MY, 0},
		{MetricType::CapexMargin_SY, 0},
		{MetricType::CapexMargin_MY, 0},
	};
	// process a multi year score metrics for `num_years`, or maximum recorded duration (whichever is lower). 
	//void process(const int num_years);

public:
	Scorer(const Stock &stock);

	// process a current year score metrics. 
	void process();

	// GETTERS:
	int get_curr_score();

	std::unordered_map<CategoryType, int> get_categoryscores();

	std::unordered_map<MetricType, int> get_metricscores();

	std::unordered_map<CategoryType, int> get_maxcategoryscores();

	std::unordered_map<MetricType, int> get_maxmetricscores();

	std::unordered_map<MetricType,long double> get_metricperformance();

};