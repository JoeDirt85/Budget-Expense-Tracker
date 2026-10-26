#include "pch.h"
#include "CppUnitTest.h"
#include "../BudgetExpenseCore/Category.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BudgetingExpenseApplicationTests
{
	TEST_CLASS(CategoryTests)
	{
	public:

		//tests that checks the default constructor fills with the correct values
		TEST_METHOD(DefualtConstructor_ReturnDefaultValues) 
		{
			//declares the default constructor
			Category category;

			//assertions to compare if the given values are equal to the default values
			Assert::AreEqual(-1, category.getId());
			Assert::AreEqual(-1, category.getBudgetPeriodId());
			Assert::AreEqual(std::string(""), category.getName());
			Assert::AreEqual(0.0, category.getAmount());
		}

		//test to check if the constructor gets the correct values
		TEST_METHOD(ParameterizedConstructor_GetValues)
		{
			//declares the constructor values that will be compared
			Category category("Rent", 1500.0);


			//assertions to compare if the given values are equal to the constructor values
			Assert::AreEqual(-1, category.getId());
			Assert::AreEqual(-1, category.getBudgetPeriodId());
			Assert::AreEqual(std::string("Rent"), category.getName());
			Assert::AreEqual(1500.0, category.getAmount());
		}

		//test to check if the setId method works corrctly
		TEST_METHOD(SetId_UpdateIdValue)
		{
			//declares default constructor 
			Category category;

			//checks if the given value is equal to the default value
			Assert::AreEqual(-1, category.getId());

			//calls the setId method
			category.setId(0);

			//checks if the setId method updated the id properly
			Assert::AreEqual(0, category.getId());
		}

		//test to check  if the setId guard is working correctly
		TEST_METHOD(SetId_IdGuardCheck)
		{
			//declares default constructor
			Category category;

			//calls the setId method
			category.setId(0);

			//attempts to call the setId a second time
			Assert::ExpectException<std::logic_error>([&]() {category.setId(1); });
		}

		//test to check if the setBudgetPeriodId method works 
		TEST_METHOD(SetBudgetPeriodId_UpdateBudgetPeriodIdValue)
		{
			//declares default constructor
			Category category;

			//checks if the given value is equal to the default value
			Assert::AreEqual(-1, category.getBudgetPeriodId());

			//calls the setBudgetPeriodId Method
			category.setBudgetPeriodId(0);

			//verifies the setBudgetPeriodId method worked
			Assert::AreEqual(0, category.getBudgetPeriodId());
		}

		//tests to see if the setBudgetPeriodId guard is working correctly

		TEST_METHOD(SetBudgetPeriodId_BudgetPeriodIdGuardCheck)
		{
			//declares default constructor
			Category category;

			//calls the setBudgetPeriodId method
			category.setBudgetPeriodId(0);

			//attempts to set the budgetPeriodId again
			Assert::ExpectException<std::logic_error>([&]() {category.setBudgetPeriodId(1); });
		}

		//test to check if the setName method works correctly
		TEST_METHOD(SetName_UpdateNameValue)
		{
			//declares default constructor
			Category category;

			//checks if the given value is equal to the defualt value
			Assert::AreEqual(std::string(""), category.getName());

			//calls the setName method 
			category.setName("Rent");

			//checks to see if the setName method updated the name correctly
			Assert::AreEqual(std::string("Rent"), category.getName());
		}

		//Test to check if the setAmount method works correctly
		TEST_METHOD(SetAmount_UpdateAmountValue)
		{
			//declares the default constructor
			Category category;

			//checks is the given value is equal to the defaul value
			Assert::AreEqual(0.0, category.getAmount());

			//sets the new value for amount
			category.setAmount(1500.0);

			//checks to see if the setAmount method updated the amount correctly
			Assert::AreEqual(1500.0, category.getAmount());
		}
};
}