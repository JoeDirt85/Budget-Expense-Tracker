#ifndef BUDGETPERIOD_H
#define BUDGETPERIOD_H

#include<string>
#include<vector>
#include"Category.h"
#include"Expense.h"
#include"GuardClass.h"

class BudgetPeriod
{
private: 
	//declaration of class variables
	int id;
	int month;
	int year;
	double income;
	
	//declaration of class vectors
	std::vector<Category> categories;
	std::vector<Expense> expenses;

public:

	//class functions

	//declaration of default constructor
	BudgetPeriod();

	//declaration of class constructor
	BudgetPeriod(int m, int y, double in);

	//functions to add objects to vectors
	void addCategory(const Category& category);
	void addExpense(const Expense& expense);

	//setter functions
	void setId(int newId);

	//getter functions
	int getId() const;
	int getMonth() const;
	int getYear() const;
	double getIncome() const;

	//functions to get class objects from vectors
	const std::vector<Category>& getCategories() const;
	const std::vector<Expense>& getExpenses() const;

	//functions that perform calculations
	double getTotalExpenses() const;
	double getTotalBudgeted() const;
	double getRemainingIncome() const;
	double getDifference() const;
};

#endif