#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>
#include "GuardClass.h"

class Category
{
private:
	//declaration of class variables 
	int id;
	int budgetPeriodId;
	std::string name;
	double budgetAmount;

public:
	//decalrs the default constructor
	Category();

	//decalres the constructor
	Category(const std::string& n, double ba);

	//class funcitons
	//setter functions for the category class
	void setAmount(double ba);
	void setName(const std::string& n);
	void setId(int newId);
	void setBudgetPeriodId(int newBudgetPeriodId);

	//getter functions for the category class
	int getId() const;
	int getBudgetPeriodId() const;
	std::string getName() const;
	double getAmount() const;
};

#endif
