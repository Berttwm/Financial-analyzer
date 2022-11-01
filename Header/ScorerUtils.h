#pragma once
#include <unordered_map>
#include <string>
/* ScorerUtils - Utility class to support Scorer and Metric Classes
* Helper class for scorer
*	Single Year metrics measure only current year metrics
*	Multi Year metrics measure for stated amount of years (usually 10) or for the number of readily available statements, whichever is less.
*
*	SocringTier provides a scoring grade for each metric (HIGH = 10, FAIL =0)
* 
*	Multiple Metrics will include multiple CategoryTypes. This is intended to allow multiple category scoring for each metric 
*	Single Metric will include single MetricType. This is intended to collate every metrics individual score.
*/

// Metrics should either account for all categories, or simply HIGH/FAIL (pass/fail)
enum class ScoringTier
{
	HIGH = 10, // Higher points if hit the best category
	MED = 6,
	LOW = 3,
	FAIL = 0,
};
/* CategoryType
* Determines the categories that can be scored and reported back to user.
*/
enum class CategoryType
{
	Single,
	Multi,
	IncomeStatement,
	BalanceSheet,
	CashFlow,
};
/* CategoryTypeString 
* Provides a string form of all available CategoryTypes
*/
const std::unordered_map<CategoryType, std::string> CategoryTypeString =
{
	{CategoryType::Single, "Single"},
	{CategoryType::Multi, "Multi"},
	{CategoryType::IncomeStatement, "IncomeStatement"},
	{CategoryType::BalanceSheet, "BalanceSheet"},
	{CategoryType::CashFlow, "CashFlow"}
};
/* MetricType
* Determines the Metrics that are currently being tracked scored
* Every new metric template added should be included inside
*/
enum class MetricType
{
	// Income Statements
	GrossProfitMargin_SY,
	SGA_SY,
	OperatingExpenses_MY,
	SGA_MY,
	
	// NEW
	RND_SY, // done
	RND_MY, // done
	Depreciation_SY,
	Depreciation_MY,
	InterestExpense_SY,
	InterestExpense_MY,
	// SalesOfAssets_SY/MY // money earned over sales of assets
	NetEarnings_MY,
	NetEarningsOverRevenue_MY,
	// SalesFigure, // Over 700M
	NegativeEarnings_MY,
	EarningsGrowth_MY,
	// NEW
	
	// Balance Sheets
	DebtRatio_SY,
	DebtRatio_MY,
	// Cash Flows
	SellingAndBuyingStock_MY,
	CapexMargin_SY,
	CapexMargin_MY,




};
/* MetricTypeString
* Provides a string form of all available CategoryTypes
*/
const std::unordered_map<MetricType, std::string> MetricTypeString =
{
	// Income Statements
	{MetricType::GrossProfitMargin_SY, "GrossProfitMargin_SY"},
	{MetricType::SGA_SY, "SGA_SY"},
	{MetricType::OperatingExpenses_MY, "OperatingExpenses_MY"},
	{MetricType::SGA_MY, "SGA_MY"},
	{MetricType::RND_SY, "RND_SY"},
	{MetricType::RND_MY, "RND_MY"},
	{MetricType::Depreciation_SY, "Depreciation_SY"},
	{MetricType::Depreciation_MY, "Depreciation_MY"},
	{MetricType::InterestExpense_SY, "InterestExpense_SY"},
	{MetricType::InterestExpense_MY, "InterestExpense_MY"},
	{MetricType::NetEarnings_MY, "NetEarnings_MY"},
	{MetricType::NetEarningsOverRevenue_MY, "NetEarningsOverRevenue_MY"},
	{MetricType::NegativeEarnings_MY, "NegativeEarnings_MY"},
	{MetricType::EarningsGrowth_MY, "EarningsGrowth_MY"},
	// Balance Sheets
	{MetricType::DebtRatio_SY, "DebtRatio_SY"},
	{MetricType::DebtRatio_MY, "DebtRatio_MY"},
	// Cash Flows
	{MetricType::SellingAndBuyingStock_MY, "SellingAndBuyingStock_MY"},
	{MetricType::CapexMargin_SY, "CapexMargin_SY"},
	{MetricType::CapexMargin_MY, "CapexMargin_MY"},
};
