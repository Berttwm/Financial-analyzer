#pragma once
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

/* Stock Utils
*
*/

/* Income Statement Utils
*
*/
enum class IncomeStatementMetrics {
	date,
	symbol,
	reportedCurrency,
	cik,
	fillingDate,
	acceptedDate,
	calendarYear,
	period,
	revenue,
	costOfRevenue,
	grossProfit,
	grossProfitRatio,
	researchAndDevelopmentExpenses,
	generalAndAdministrativeExpenses,
	sellingAndMarketingExpenses,
	sellingGeneralAndAdministrativeExpenses,
	otherExpenses,
	operatingExpenses,
	costAndExpenses,
	interestIncome,
	interestExpense,
	depreciationAndAmortization,
	ebitda,
	ebitdaratio,
	operatingIncome,
	operatingIncomeRatio,
	totalOtherIncomeExpensesNet,
	incomeBeforeTax,
	incomeBeforeTaxRatio,
	incomeTaxExpense,
	netIncome,
	netIncomeRatio,
	eps,
	epsdiluted,
	weightedAverageShsOut,
	weightedAverageShsOutDil,
	link,
	finalLink,
};
/* Map holding the income statement metrics to a vector of the corresponding metric (from newest=idx0 to oldest=idxLast) */
const std::unordered_map<IncomeStatementMetrics, std::vector<std::string>> incomestatementmetrics_yearly_map = {

};



/* Balance Sheet Utils
*
*/
enum class BalanceSheetMetrics {
	date,
	symbol,
	reportedCurrency,
	cik,
	fillingDate,
	acceptedDate,
	calendarYear,
	period,
	cashAndCashEquivalents,
	shortTermInvestments,
	cashAndShortTermInvestments,
	netReceivables,
	inventory,
	otherCurrentAssets,
	totalCurrentAssets,
	propertyPlantEquipmentNet,
	goodwill,
	intangibleAssets,
	goodwillAndIntangibleAssets,
	longTermInvestments,
	taxAssets,
	otherNonCurrentAssets,
	totalNonCurrentAssets,
	otherAssets,
	totalAssets,
	accountPayables,
	shortTermDebt,
	taxPayables,
	deferredRevenue,
	otherCurrentLiabilities,
	totalCurrentLiabilities,
	longTermDebt,
	deferredRevenueNonCurrent,
	deferredTaxLiabilitiesNonCurrent,
	otherNonCurrentLiabilities,
	totalNonCurrentLiabilities,
	otherLiabilities,
	capitalLeaseObligations,
	totalLiabilities,
	preferredStock,
	commonStock,
	retainedEarnings,
	accumulatedOtherComprehensiveIncomeLoss,
	othertotalStockholdersEquity,
	totalStockholdersEquity,
	totalLiabilitiesAndStockholdersEquity,
	minorityInterest,
	totalEquity,
	totalLiabilitiesAndTotalEquity,
	totalInvestments,
	totalDebt,
	netDebt,
	link,
	finalLink
};
/* Map holding the Balance Sheet metrics to a vector of the corresponding metric (from newest=idx0 to oldest=idxLast) */
const std::unordered_map<BalanceSheetMetrics, std::vector<std::string>> balancesheetmetrics_yearly_map = {

};

/* Cash Flow Utils
*
*/
enum class CashFlowMetrics {
	date,
	symbol,
	reportedCurrency,
	cik,
	fillingDate,
	acceptedDate,
	calendarYear,
	period,
	netIncome,
	depreciationAndAmortization,
	deferredIncomeTax,
	stockBasedCompensation,
	changeInWorkingCapital,
	accountsReceivables,
	inventory,
	accountsPayables,
	otherWorkingCapital,
	otherNonCashItems,
	netCashProvidedByOperatingActivities,
	investmentsInPropertyPlantAndEquipment,
	acquisitionsNet,
	purchasesOfInvestments,
	salesMaturitiesOfInvestments,
	otherInvestingActivites,
	netCashUsedForInvestingActivites,
	debtRepayment,
	commonStockIssued,
	commonStockRepurchased,
	dividendsPaid,
	otherFinancingActivites,
	netCashUsedProvidedByFinancingActivities,
	effectOfForexChangesOnCash,
	netChangeInCash,
	cashAtEndOfPeriod,
	cashAtBeginningOfPeriod,
	operatingCashFlow,
	capitalExpenditure,
	freeCashFlow,
	link,
	finalLink,
};

const std::unordered_map<CashFlowMetrics, std::vector<std::string>> cashflowmetrics_yearly_map = {

};