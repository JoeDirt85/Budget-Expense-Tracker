#include "pch.h"
#include "CppUnitTest.h"
#include "../BudgetExpenseCore/Expense.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BudgetingExpenseApplicationTests
{
	TEST_CLASS(ExpenseTests)
	{
	public:
		
		//test used to check if the default constructor fills with the correct values
		TEST_METHOD(DefaultConstructor_ReturnDefaultValues)
		{
			//declares a defualt constructor
			Expense expense;

			//assertions to compare if the given value and corresponding defualt values are equal
			Assert::AreEqual(-1, expense.getId());
			Assert::AreEqual(-1, expense.getCategoryId());
			Assert::AreEqual(std::string(""), expense.getName());
			Assert::AreEqual(0.0, expense.getPrice());
			Assert::AreEqual(std::string(""), expense.getDate());
			Assert::AreEqual(std::string(""), expense.getDescription());
		}

		//checks if constructor gets the corrrect values
		TEST_METHOD(ParameterizedConstructor_GetValues)
		{
			//declares a parameterized constructor
			Expense expense("Rent", 1500.0, 1, "8-01-26", "Monthly rent");

			//assertions used to compare if the given values are equal to those in the constructor
			Assert::AreEqual(-1, expense.getId());
			Assert::AreEqual(std::string("Rent"), expense.getName());
			Assert::AreEqual(1500.0, expense.getPrice());
			Assert::AreEqual(1, expense.getCategoryId());
			Assert::AreEqual(std::string("8-01-26"), expense.getDate());
			Assert::AreEqual(std::string("Monthly rent"), expense.getDescription());
		}

		//checks if the setId method works correctly
		TEST_METHOD(SetId_UpdateIdValue)
		{
			//decalres default constructor
			Expense expense;

			//assertion to see if the given and default value are equal
			Assert::AreEqual(-1, expense.getId());

			//sets a new value for the id
			expense.setId(0);

			//verifies the setId method worked
			Assert::AreEqual(0, expense.getId());
		}

		//checks if the setId gaurd works correctly
		TEST_METHOD(SetId_IdGuardCheck)
		{
			//decalres defualt constructor
			Expense expense;

			//sets a new value for the id
			expense.setId(0);

			//attempts to call setID a second time
			Assert::ExpectException<std::logic_error>([&]() {expense.setId(1); });
		}

		//tests if the setName method works correctly
		TEST_METHOD(SetName_UpdateNameValue)
		{
			//declares default constructor
			Expense expense;

			//assertion to see if the given and default value are equal
			Assert::AreEqual(std::string(""), expense.getName());

			//sets a new value for the name
			expense.setName("Rent");
			
			//verifies setName method worked
			Assert::AreEqual(std::string("Rent"), expense.getName());
		}

		//tests if the setPrice method works correctly
		TEST_METHOD(SetPrice_UpdatePriceValue)
		{
			//declares default constructor
			Expense expense;

			//assertion to compare default constructor and expected value
			Assert::AreEqual(0.0, expense.getPrice());

			//sets a new value for the price
			expense.setPrice(1500.0);

			//assertion to verify the setPrice method worked
			Assert::AreEqual(1500.0, expense.getPrice());
		}

		//tests if the setCategoryId method works correctly
		TEST_METHOD(SetCategoryId_UpdateCategoryIdValue)
		{
			//declares default constructor
			Expense expense;

			//assertion to compare default constructor and expected value
			Assert::AreEqual(-1, expense.getCategoryId());

			//sets a new value for categoryId
			expense.setCategoryId(1);

			//assertion to verify the setCategoryId method worked
			Assert::AreEqual(1, expense.getCategoryId());
		}

		//tests if the setDate method works correctly
		TEST_METHOD(SetDate_UpdateDateValue)
		{
			//declares default constructor
			Expense expense;

			//assertion to compare default constructor and expected value are equal
			Assert::AreEqual(std::string(""), expense.getDate());

			//sets a new value for the date
			expense.setDate("8-01-26");

			//assertion to verify setDate method works correctly
			Assert::AreEqual(std::string("8-01-26"), expense.getDate());
		}

		//tests if the setDescription method works correctly
		TEST_METHOD(SetDescription_UpdateDescriptionValue)
		{
			//declares default constructor
			Expense expense;

			//assertion to compare default constructor and expected value are equal
			Assert::AreEqual(std::string(""), expense.getDescription());

			//sets a new value for the description
			expense.setDescription("Monthly rent");

			//assertion to verify the setDescription method works correctly
			Assert::AreEqual(std::string("Monthly rent"), expense.getDescription());
		}

	};
}
