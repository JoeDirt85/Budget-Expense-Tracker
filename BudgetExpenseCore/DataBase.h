#ifndef DATABASE_H
#define DATABASE_H
#include "BudgetPeriod.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <string>

class DataBase
{
private: 
	SQLite::Database db;

public: 

	DataBase(const std::string& dbPath);

	//query fucntions for the expense table 
	void createExpenseTable();
	int insertExpense(const Expense& expense);
	void deleteExpense(int id);
	Expense getExpenseById(int id);
	const std::vector<Expense> getExpenseByDateRange(const std::string& startDate, const std::string& endDate);

	//query functions for the category table
	void createCategorytable();
	int insertCategory(const Category& category);
	void deleteCategory(int id);
	Category getCategoryById(int id);
	const std::vector<Category> getCategoriesByBudgetPeriodId(int budgetPeriodId);

	//query functions for the budget period table
	void createBudgetPeriodTable();
	int insertBudgetPeriod(const BudgetPeriod& period);
	void deleteBudgetPeriod(int id);
	BudgetPeriod getBudgetPeriodById(int id);
	const std::vector<BudgetPeriod> getBudgetPeriodByDateRange(const std::string& startDate, const std::string& endDate);

};

#endif 
