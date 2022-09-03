#pragma once
#include "ScorerUtils.h"
#include "StockUtils.h"

/* Abstract class to be inherited by metric classes  */

template<MetricYearType YT> class Metric
{
private:
	int score; // score to return
	std::unordered_map<SheetType, int> *SheetTypeScore; // SheetTypeScore to be passed from scorer
	virtual bool highScore() = 0;
	virtual bool medScore() = 0;
	virtual bool lowScore() = 0;
public:
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