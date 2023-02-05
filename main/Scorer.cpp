#include "../Header/Scorer.h"

Scorer::Scorer(const Stock &stock)
	: stock(stock)
{

}

void Scorer::process()
{
	//Initial Check: Ensure every metric initialized once - Uncomment when program ready
	//for (auto& metric_max_score : MaxMetricScores)
	//{
	//	if (metric_max_score.second > 10)
	//	{
	//		std::string error_msg = "[*] Error: metric `" + MetricTypeString.find(metric_max_score.first)->second + "` have been initialized more than one time. Please remove duplicated instance in `Scorer.cpp`";
	//		throw std::runtime_error(error_msg);
	//	}
	//	else if (metric_max_score.second < 10)
	//	{
	//		std::string error_msg = "[*] Error: metric `" + MetricTypeString.find(metric_max_score.first)->second + "` have not been initializes. Please initialize it in `Scorer.cpp`";
	//		throw std::runtime_error(error_msg);
	//	}
	//}
	int year_count = this->stock.get_num_years_data(); // To determine number of years to pass into MY (Multiyear metrics)

	// TODO: Implement recursive calling on Metric classes
	// Income Statements
	GrossProfitMargin_SY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances);
	SGA_SY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances);
	OperatingExpenses_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	SGA_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	RND_SY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances);
	RND_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	Depreciation_SY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances);
	Depreciation_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	InterestExpense_SY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances);
	InterestExpense_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	NetEarnings_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	NetEarningsOverRevenue_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	NegativeEarnings_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	EarningsGrowth_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	// Balance Sheets
	DebtRatio_SY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances);
	DebtRatio_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	TotalInventory_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);

	// CashFlows
	SellingAndBuyingStock_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);
	CapexMargin_SY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances);
	CapexMargin_MY(this->stock, CURR_SCORE, &CategoryScores, &MetricScores, &MaxCategoryScores, &MaxMetricScores, &MetricPerformances, year_count);

}

// GETTERS:
int Scorer::get_curr_score()
{
	return this->CURR_SCORE;
}


std::unordered_map<CategoryType, int> Scorer::get_categoryscores()
{
	return this->CategoryScores;
}

std::unordered_map<MetricType, int> Scorer::get_metricscores()
{
	return this->MetricScores;
}

std::unordered_map<CategoryType, int> Scorer::get_maxcategoryscores()
{
	return this->MaxCategoryScores;
}

std::unordered_map<MetricType, int> Scorer::get_maxmetricscores()
{
	return this->MaxMetricScores;
}

std::unordered_map<MetricType,long double> Scorer::get_metricperformance()
{
	return this->MetricPerformances;
}
