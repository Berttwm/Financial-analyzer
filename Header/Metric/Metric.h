#pragma once
#include <iostream>

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
	int& score; // score to return
	std::unordered_map<CategoryType, int>* CategoryScores; // CategoryScores DS to store scores of different categories
	std::unordered_map<MetricType, int>* MetricScores; // MetricScores DS to store scores of different metrics
	std::unordered_map<CategoryType, int>* MaxCategoryScores; // CategoryScores DS to store scores of different categories
	std::unordered_map<MetricType, int>* MaxMetricScores; // MetricScores DS to store scores of different metrics

	/* highScore() / medScore() / lowScore() 
	* Conditions for highScore, medScore and lowScore. Returns a boolean of whether the condition has been met
	* Used in `scoreMetric()` function which first checks for highScore, medScore, then lowScore.
	*/
	const Stock& stock;

	virtual bool highScore() = 0;
	virtual bool medScore() = 0;
	virtual bool lowScore() = 0;
	//virtual std::vector<CategoryType> updateCategoryScores() = 0;
	//virtual std::vector<MetricType> updateMetricScores() = 0;

protected:
	std::vector<CategoryType> categoryvector;
	std::vector<MetricType> metricvector;

public:
	Metric(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores, 
				std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores)
		:stock(stock),
		score(score),
		CategoryScores(CategoryScores),
		MetricScores(MetricScores),
		MaxCategoryScores(MaxCategoryScores),
		MaxMetricScores(MaxMetricScores)
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