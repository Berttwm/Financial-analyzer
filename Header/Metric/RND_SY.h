#pragma once
#include "MetricSY.h"
/*
* RND_SY - SingleYear_ResearchAndDevelopment
*
* Description: Calculates the current year RND over gross profit margin
*
* Categories used:
*	1) Single
*	2) IncomeStatement
*
* Scoring:
*	High = <= 30%
*	Med = <= 40%
*	Low =  <= 50%
*	Fail = > 50% or negative
*/

class RND_SY : public MetricSY<MetricType::RND_SY, CategoryType::Single, CategoryType::IncomeStatement>
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	RND_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
		std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances);
};