#include "pch.h"
#include "CppUnitTest.h"
#include "../BudgetExpenseCore/BudgetPeriod.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BudgetingExpenseApplicationTests
{
	TEST_CLASS(BudgetPeriodTests)
	{
	public:

		//tests the implementation of the default constructor
		TEST_METHOD(DefaultConstructor_ReturnDefaultValues)
		{
			//declares the default constructor
			BudgetPeriod budgetPeriod;

			//assertions that compare the given values with the default values
			Assert::AreEqual(-1, budgetPeriod.getId());
			Assert::AreEqual(0, budgetPeriod.getMonth());
			Assert::AreEqual(0, budgetPeriod.getYear());
			Assert::AreEqual(0.0, budgetPeriod.getIncome());
		}

		//tests the implementation of the class constructor and verifies it fills with the correct values
		TEST_METHOD(ParameterizedConstructor_GetValues)
		{
			//declares the constructor values that will be compared
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//assertions that compare the given values with the set constructor values
			Assert::AreEqual(-1, budgetPeriod.getId());
			Assert::AreEqual(8, budgetPeriod.getMonth());
			Assert::AreEqual(2026, budgetPeriod.getYear());
			Assert::AreEqual(4200.0, budgetPeriod.getIncome());
		}

		//tests the function for adding a category object into the vector
		TEST_METHOD(AddCategory_AddsToVector)
		{
			//creates the constructor for a budgetperiod object
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//creates the constructor for a category object
			Category category("Rent", 1500.0);

			//adds the category to the Category vector
			budgetPeriod.addCategory(category);
			
			//assertion that compares the expected vector size with the actual size
			Assert::AreEqual((size_t)1, budgetPeriod.getCategories().size());

			//assertions to compare the expected fields against the set fields
			Assert::AreEqual(category.getId(), budgetPeriod.getCategories().at(0).getId());
			Assert::AreEqual(category.getBudgetPeriodId(), budgetPeriod.getCategories().at(0).getBudgetPeriodId());
			Assert::AreEqual(category.getName(), budgetPeriod.getCategories().at(0).getName());
			Assert::AreEqual(category.getAmount(), budgetPeriod.getCategories().at(0).getAmount());
		}

		//tests the function for adding an expense item into the vector
		TEST_METHOD(AddExpense_AddsToVector)
		{
			//creates the constructor for a budgetPeriod object
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//creates the constructor for an expense object
			Expense expense("Rent", 1500.0, 1, "8-01-2026", "Monthly Rent");

			//adds the expense to the Expense vector
			budgetPeriod.addExpense(expense);

			//assertion that compares the expected vector size to the actual vector size
			Assert::AreEqual((size_t)1, budgetPeriod.getExpenses().size());

			//assertions that compare the expected fields against the set fields 
			Assert::AreEqual(expense.getId(), budgetPeriod.getExpenses().at(0).getId());
			Assert::AreEqual(expense.getCategoryId(), budgetPeriod.getExpenses().at(0).getCategoryId());
			Assert::AreEqual(expense.getName(), budgetPeriod.getExpenses().at(0).getName());
			Assert::AreEqual(expense.getPrice(), budgetPeriod.getExpenses().at(0).getPrice());
			Assert::AreEqual(expense.getDate(), budgetPeriod.getExpenses().at(0).getDate());
			Assert::AreEqual(expense.getDescription(), budgetPeriod.getExpenses().at(0).getDescription());
		}

		//tests the function for setting the new class id
		TEST_METHOD(SetId_UpdateIdValue)
		{
			//declares the default constructor
			BudgetPeriod budgetPeriod;

			//assertion to compare the expected value against the default value
			Assert::AreEqual(-1, budgetPeriod.getId());

			//calls the setId function
			budgetPeriod.setId(0);

			//assertion to verify the setId worked
			Assert::AreEqual(0, budgetPeriod.getId());
		}

		//tests the id guard check for the class id
		TEST_METHOD(SetId_IdGuardCheck)
		{
			//declares the default constructor
			BudgetPeriod budgetPeriod;

			//calls the setId function
			budgetPeriod.setId(0);

			//assertion that attempts to call the setId again
			Assert::ExpectException<std::logic_error>([&]() {budgetPeriod.setId(1); });

		}
		
		//tests that the calculations for the method of finding the sum of expenses
		TEST_METHOD(GetTotalExpense_ReturnTotal)
		{
			//declares a constructor for the budgetperiod object 
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//declares multiple expnese objects
			Expense expense1("Rent", 1500.0, 1, "8-01-26", "monthly rent");
			Expense expense2("Water", 120.13, 2, "8-01-26", "monthly water bill"); 
			Expense expense3("Electric", 118.78, 2, "8-01-26", "monthly electric bill");

			//adds the expenses to the vector
			budgetPeriod.addExpense(expense1);
			budgetPeriod.addExpense(expense2);
			budgetPeriod.addExpense(expense3);

			//assertion that compares the expected value against the total price
			Assert::AreEqual(1738.91, budgetPeriod.getTotalExpenses(), 0.001);
		}

		//testst the calculations for the method that returns the total amount budgeted
		TEST_METHOD(GetTotalBudgeted_ReturnTotal)
		{
			//declares the constructor for the budgetperiod object
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//declares multiple category objects
			Category category1("Housing", 1300.0);
			Category category2("Utilities", 250.0);
			Category category3("Food", 300.0);

			//adds the category objects to the vector
			budgetPeriod.addCategory(category1);
			budgetPeriod.addCategory(category2);
			budgetPeriod.addCategory(category3);

			//assertion that compares the expected value against the total budgeted amount
			Assert::AreEqual(1850.0, budgetPeriod.getTotalBudgeted(), 0.001);
		}

		//tests the calculations for the method that returns the remaining amount of icome for the month
		TEST_METHOD(GetRemainingIncome_ReturnIncomeValue)
		{
			//declares the constructor for the budgetperiod object
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//declares multiple expnese objects
			Expense expense1("Rent", 1500.0, 1, "8-01-26", "monthly rent");
			Expense expense2("Water", 120.13, 2, "8-01-26", "monthly water bill");
			Expense expense3("Electric", 118.78, 2, "8-01-26", "monthly electric bill");

			//adds the expenses to the vector
			budgetPeriod.addExpense(expense1);
			budgetPeriod.addExpense(expense2);
			budgetPeriod.addExpense(expense3);

			//assertion that compares the expected value with the remaining income
			Assert::AreEqual(2461.09, budgetPeriod.getRemainingIncome(), 0.001);
		}

		//tests the method that returns the difference between the budgeted amount and the total expenses
		TEST_METHOD(GetDifference_ReturnBudgetDifference)
		{
			//declares the constructor for the budgetperiod object
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//declares multiple expnese objects
			Expense expense1("Rent", 1500.0, 1, "8-01-26", "monthly rent");
			Expense expense2("Water", 120.13, 2, "8-01-26", "monthly water bill");
			Expense expense3("Electric", 118.78, 2, "8-01-26", "monthly electric bill");

			//adds the expenses to the vector
			budgetPeriod.addExpense(expense1);
			budgetPeriod.addExpense(expense2);
			budgetPeriod.addExpense(expense3);

			//declares multiple category objects
			Category category1("Housing", 1300.0);
			Category category2("Utilities", 250.0);
			Category category3("Food", 300.0);

			//adds the category objects to the vector
			budgetPeriod.addCategory(category1);
			budgetPeriod.addCategory(category2);
			budgetPeriod.addCategory(category3);

			//assertion that compares the expected value and the actual value of the difference of budgeted vs expenses
			Assert::AreEqual(111.09, budgetPeriod.getDifference(), 0.001);
		}
	};
}