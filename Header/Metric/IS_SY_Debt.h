#pragma once
#include "../Metric.h"
/*
* IS_SY_Debt - IncomeStatement_SingleYear_Debt
*/

//template class<>
class IS_SY_Debt : public Metric
{
private:
	bool highScore() override;
	bool medScore() override;
	bool lowScore() override;
public:
	IS_SY_Debt(std::unordered_map<SheetType, int>* sts);
};