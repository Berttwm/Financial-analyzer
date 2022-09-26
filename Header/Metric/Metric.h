#pragma once
#include <iostream>
#include <unordered_map>

#include "../Stock.h"
#include "../ScorerUtils.h"
#include "../StockUtils.h"

/*  
* Abstract class to be inherited by metric classes 
* 
* The naming format of derived class should be `[MetricName]_[MetricYearType]`
*	MetricYearType = [ SY, MY ] (Single Year, Multi Year)
*		i.e. `Debt_SY` implies Debt_SingleYear
* 
*/
class Metric
{
private:
	std::unordered_map<CategoryType, int>* CategoryScores; // CategoryScores DS to store scores of different categories
	std::unordered_map<MetricType, int>* MetricScores; // MetricScores DS to store scores of different metrics
	std::unordered_map<CategoryType, int>* MaxCategoryScores; // CategoryScores DS to store scores of different categories
	std::unordered_map<MetricType, int>* MaxMetricScores; // MetricScores DS to store scores of different metrics
	/* highScore() / medScore() / lowScore() 
	* Conditions for highScore, medScore and lowScore. Returns a boolean of whether the condition has been met
	* Used in `scoreMetric()` function which first checks for highScore, medScore, then lowScore.
	*/

	virtual bool highScore() = 0;
	virtual bool medScore() = 0;
	virtual bool lowScore() = 0;

protected: // category/metric vector placed in protected to allow child class access, yet prevent public classes access.
	int& score; // score to return
	long double performance; // performance of the stock (i.e. GrossProfitMargin performance = actual gross profit margin the stock has)
	std::vector<CategoryType> categoryvector;
	std::vector<MetricType> metricvector;
	const Stock& stock;

	std::unordered_map<MetricType, long double>* MetricPerformances; // MetricPerformances to store performance result of metric
	void set_performance(long double performance)
	{
		this->performance = performance;
	}

public:
	Metric(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores, 
				std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType,long double>* MetricPerformances)
		:stock(stock),
		score(score),
		CategoryScores(CategoryScores),
		MetricScores(MetricScores),
		MaxCategoryScores(MaxCategoryScores),
		MaxMetricScores(MaxMetricScores),
		MetricPerformances(MetricPerformances)
	{
	};

	int scoreMetric()
	{
		// Step 1: Derive score
		if (this->highScore())
		{
			this->score = static_cast<int>(ScoringTier::HIGH);
		}
		else if (this->medScore())
		{
			this->score = static_cast<int>(ScoringTier::MED);
		}
		else if (this->lowScore())
		{
			this->score = static_cast<int>(ScoringTier::LOW);
		}
		else
		{
			this->score = static_cast<int>(ScoringTier::FAIL);
		}
		// Step 2: Update Category Types affected by this score
		for (auto category : this->categoryvector)
		{
			(*this->CategoryScores)[category] += this->score;
			(*this->MaxCategoryScores)[category] += static_cast<int>(ScoringTier::HIGH); // Each Category added increments category score by 10
		}

		for (auto metric : this->metricvector)
		{
			(*this->MetricScores)[metric] += this->score;
			(*this->MaxMetricScores)[metric] += static_cast<int>(ScoringTier::HIGH); // Each Metric added increments metric score by 10
		}

		return this->score;
	}
};