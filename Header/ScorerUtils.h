#pragma once
/* ScorerUtils - Utility class to support Scorer and Metric Classes
* Helper class for scorer
*	Single Year metrics measure only current year metrics
*	Multi Year metrics measure for stated amount of years (usually 10) or for the number of readily available statements, whichever is less.
*
*	SocringTier provides a scoring grade for each metric (HIGH = 10, FAIL =0)
* 
*	Different scorer for each (Inc Stmt, Bal Sht, CF) to obtain separate scoring grades for each category 
*/

// Metrics should either account for all categories, or simply HIGH/FAIL (pass/fail)
enum class ScoringTier
{
	HIGH = 10, // Higher points if hit the best category
	MED = 6,
	LOW = 3,
	FAIL = 0,
};

/* MetricYearType
* Determines if the metric being processed shall be processed as a single, or multi year entity.
*/
enum class MetricYearType
{
	Single,
	Multi
};

/* The following enum classes are simply for reference at this juncture. Meaning that they are not 
* actively called in the code (i.e. we will not be using `SingleYearIncomeStmtMetrics::SGA`)
* I intend to use the following table as a reference guide for an overview of the available methods
* 
* However, please utilize them if there is a way to integrate them for implementation of metric.
*/

/* Income statement score metrics */
enum class SingleYearIncomeStmtMetrics{
	GrossProfitMargin, // >30%
	SGA, // < 30%
};

enum class MultiYearIncomeStmtMetrics {
	OperatingExpenses, // consistency between years
	SGA, // year on year should never cross 100%
};


/* Balance sheet score metrics */
enum class SingleYearBalanceSheetMetrics {
	CashToDebtRatio, // check for cash > debt
};

enum class MultiYearBalanceSheetMetrics {
	Debt, // look at past 7 years for consistency of (cash > debt) ratio
};


/* Cash flow score metrics */
enum class SingleYearCashFlowMetrics {
	CashFlowOperatingActivites, // Check for current cash flow from operating activities
	CashFlowInvestingOperations, // Check for current cash flow from investing activities
};

enum class MultiYearCashFlowMetrics {
	CashFlowOperatingActivites, // Check for positive cash flow from operations
	CashFlowInvestingOperations, // Check for positive cash flow from investing
	SellingAndBuyingStock, // Check if company has bought or sold shares recently
};