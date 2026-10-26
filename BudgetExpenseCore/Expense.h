#ifndef	EXPENSE_H
#define EXPENSE_H

#include <string>
#include "GuardClass.h"


class Expense
{
private:
	//declaration of class variables
	int id;
	int categoryId;
	std::string name;
	double price;
	std::string date;
	std::string description;
	

public:
	//class defualt constructor 
	Expense();

	//declaration of constructor
	//n = name, p = price, ci = category Id, d = date, desc = description
	Expense(const std::string& n, double p, int ci, const std::string& d, const std::string& desc);

	//declaration of class functions
	//setter functions for the expense class
	void setName(const std::string& n);
	void setPrice(double p);
	void setDate(const std::string& d);
	void setDescription(const std::string& desc);
	void setCategoryId(int ci);
	void setId(int newId);

	//getter functions for the expense class
	int getId() const;
	int getCategoryId() const;
	std::string getName() const;
	double getPrice() const;
	std::string getDate() const;
	std::string getDescription() const;

};

#endif