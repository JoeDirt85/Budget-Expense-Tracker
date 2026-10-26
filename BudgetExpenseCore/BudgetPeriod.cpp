#include "BudgetPeriod.h"

/*
Look into adding setter methods for the month, year and income variables.
Once set, they should be non-mutable values and can only be changed once like 
id and if there are accidental inputs
*/

//default class constructor
BudgetPeriod::BudgetPeriod() {
	id = -1;
	month = 0;
	year = 0;
	income = 0.0; 
}

//class constructor
BudgetPeriod::BudgetPeriod(int m, int y, double in) {
	id = -1;
	month = m;
	year = y;
	income = in;
}

//function that adds category object to Category vector
void BudgetPeriod::addCategory(const Category& category) {
	categories.push_back(category);
}

//functions that adds expense object to Expense vector
void BudgetPeriod::addExpense(const Expense& expense) {
	expenses.push_back(expense);
}

//sets the id for the class
void BudgetPeriod::setId(int newId) {

	//calls checkIdSet functions to verify if id is set or not
	GuardClass::checkIdSet(id, newId, "BudgetPeriod ID");

	//sets id with new idI think once those 
	id = newId;
}

//gets the id 
int BudgetPeriod::getId() const {
	return id;
}

//gets the month
int BudgetPeriod::getMonth() const {
	return month;
}

//gets the year
int BudgetPeriod::getYear() const {
	return year;
}

//gets the income
double BudgetPeriod::getIncome() const {
	return income;
}

//gets category object from vector 
const std::vector<Category>& BudgetPeriod::getCategories() const {
	return categories;
};

//gets expense object from vector
const std::vector<Expense>& BudgetPeriod::getExpenses() const {
	return expenses;
}

//function that calculates the total expenses
double BudgetPeriod::getTotalExpenses() const {
	
	//variable declaration
	double total = 0.0;

	//loop that goes through and finds the sum of all expenses
	for (const auto& e : expenses) {
		total += e.getPrice();
	}
	//returns the total price
	return total;
}

//function that calculates the total budgeted amount
double BudgetPeriod::getTotalBudgeted() const {

	//variables declaration
	double total = 0.0;

	//loops through and finds the sum of all categories
	for (const auto& c : categories) {
		total += c.getAmount();
	}
	//returns the total amount
	return total;
}

//function that finds the remaining income
double BudgetPeriod::getRemainingIncome() const {
	return income - getTotalExpenses();
}

//function that finds the difference between the budgeted amount and total expenses
double BudgetPeriod::getDifference() const {
	return getTotalBudgeted() - getTotalExpenses();
}