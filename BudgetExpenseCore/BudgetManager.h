#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <vector>
#include "BudgetPeriod.h"
#include "GuardClass.h"

class BudgetManager
{
private: 
	std::vector<BudgetPeriod> periods;

public: 
	//Will make it so I can add only one copy of each period and make it so current ones can be editted throughout month and add expenses as they come.
	void addPeriod(const BudgetPeriod& period);
	void removePeriod(int month, int year);
	BudgetPeriod* findPeriod(int month, int year);
	//test functions 
	const std::vector<BudgetPeriod>& getPeriods() const;
	

};
#endif
