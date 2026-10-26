
#include "Category.h"

//implementation of the default constructor
Category::Category() {
	id = -1;
	budgetPeriodId = -1;
	name = "";
	budgetAmount = 0.0;
}

//implementation of the class constructor
Category::Category(const std::string& n, double ba) {
	id = -1;
	budgetPeriodId = -1;
	name = n;
	budgetAmount = ba;
}

//class function implementation

//function to set the Id
void Category::setId(int newId) {

	//calls checkIdSet fucntion to verify if the id is set or not
	GuardClass::checkIdSet(id, newId, "Category ID");

	//if Id id not set, sets with new id
	id = newId;
}

//sets the budget period id
void Category::setBudgetPeriodId(int newBudgetPeriodId) {

	//calls checkIdSet function to verify if the id is already set or not
	GuardClass::checkIdSet(budgetPeriodId, newBudgetPeriodId, "Category BudgetPeriod Id");

	//if not set, sets it with new id
	budgetPeriodId = newBudgetPeriodId;
}

//sets the name
void Category::setName(const std::string& n) {
	name = n;
}

//sets the amount
void Category::setAmount(double ba) {
	budgetAmount = ba;
}

//gets the id
int Category::getId() const {
	return id;
}

//gets the budgetperiod id
int Category::getBudgetPeriodId() const {
	return budgetPeriodId;
}

//gets the name
std::string Category::getName() const {
	return name;
}

//gets the amount
double Category::getAmount() const {
	return budgetAmount;
}