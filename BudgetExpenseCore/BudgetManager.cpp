#include "BudgetManager.h"
#include <iostream>

//function used to add period to the vector, doesnt allow for duplicate objects
void BudgetManager::addPeriod(const BudgetPeriod& period) {

	//calls the findperiod function to verify the period already exists
	BudgetPeriod* existing = findPeriod(period.getMonth(), period.getYear());

	//calls the checkperiodExist function to handle if the period exists
	GuardClass::checkPeriodExists(existing, "Period");
	
	//adds period to the vector
	periods.push_back(period);
}

BudgetPeriod* BudgetManager::findPeriod(int month, int year) {

	for (auto& p : periods) {
		if (p.getMonth() == month && p.getYear() == year) {
			return &p;
		}
	}

	return nullptr;
}

void BudgetManager::removePeriod(int month, int year) {

	//calls the findPeriod function to verify if the period exists
	BudgetPeriod* existing = findPeriod(month, year);

	//calls the checkPeriodDoesNotExist() function to handle if period doesn't exist
	GuardClass::checkPeriodDoesNotExist(existing, "Period");

	//calculates the position of the existing pointer within the vector
	int position = existing - periods.data();

	//removes period from the vector
	periods.erase(periods.begin() + position);
	
}

//test function
const std::vector<BudgetPeriod>& BudgetManager::getPeriods() const {
	return periods;
}

