#pragma once
#include "Stock.h"
#include "ScorerUtils.h"
#include "StockUtils.h"

/*  
* Abstract class to be inherited by metric classes 
* 
* The naming format of derived class should be `[SheetType]_[MetricYearType]_[MetricName]`
*	SheetType = [ IS, BS, CF ] (Income Statement, Balance Sheet, Cash Flow)
*	MetricYearType = [ SY, MY ] (Single Year, Multi Year)
*		i.e. `IS_SY_Debt` implies IncomeStatement_SingleYear_Debt
* 
*/
class Metric
{
private:
	int score; // score to return
	std::unordered_map<SheetType, int> *sheetTypeScore; // SheetTypeScore to be passed from scorer
	virtual bool highScore() = 0;
	virtual bool medScore() = 0;
	virtual bool lowScore() = 0;

	const Stock* stock;
public:
	Metric(std::unordered_map<SheetType, int>* sheetTypeScore);

	int scoreMetric()
	{
		if (this->highScore())
		{
			return static_cast<int>(ScoringTier::HIGH);
		}
		else if (this->medScore())
		{
			return static_cast<int>(ScoringTier::MED);
		}
		else if (this->lowScore())
		{
			return static_cast<int>(ScoringTier::LOW);
		}
		else
		{
			return static_cast<int>(ScoringTier::FAIL);
		}
	}
};