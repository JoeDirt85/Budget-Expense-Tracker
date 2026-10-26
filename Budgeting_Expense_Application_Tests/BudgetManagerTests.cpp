#include "pch.h"
#include "CppUnitTest.h"
#include "../BudgetExpenseCore/BudgetManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BudgetingExpenseApplicationTests
{
	TEST_CLASS(BudgetManagerTests) {

	public:

		//test that checks the method for adding BudgetPeriod object to the class vector
		TEST_METHOD(AddPeriod_AddsToVector)
		{
			BudgetManager budgetManager;

			//constructs the budgetperiod object
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//calls the method for adding object to the vector
			budgetManager.addPeriod(budgetPeriod);

			//assertion that compares the expected vector size to the actual size
			Assert::AreEqual((size_t)1, budgetManager.getPeriods().size());

			//assertion that compares the values are the same as the expected values
			Assert::AreEqual(budgetPeriod.getId(), budgetManager.getPeriods().at(0).getId());
			Assert::AreEqual(budgetPeriod.getMonth(), budgetManager.getPeriods().at(0).getMonth());
			Assert::AreEqual(budgetPeriod.getYear(), budgetManager.getPeriods().at(0).getYear());
			Assert::AreEqual(budgetPeriod.getIncome(), budgetManager.getPeriods().at(0).getIncome());
		}

		TEST_METHOD(AddPeriod_PeriodExistsGuardCheck)
		{
			BudgetManager budgetManager;

			//constructs the budgetperiod object
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//calls the method for adding the object to the vector
			budgetManager.addPeriod(budgetPeriod);

			//assertion that tries to call and add duplicate object to vector
			Assert::ExpectException<std::logic_error>([&]() {budgetManager.addPeriod(budgetPeriod); });
		}

		TEST_METHOD(RemovePeriod_RemoveFromVector)
		{
			BudgetManager budgetManager;

			//constructs the budgetPeriod Object
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//calls the method for adding the object to the vector
			budgetManager.addPeriod(budgetPeriod);

			//assertion that compares the expected vector size to the actual size
			Assert::AreEqual((size_t)1, budgetManager.getPeriods().size());

			//calls the method for removing the object from the vector
			budgetManager.removePeriod(8, 2026);

			//assertion that compares the expected size to the actual size
			Assert::AreEqual((size_t)0, budgetManager.getPeriods().size());

		}

		TEST_METHOD(RemovePeriod_PeriodDoesNotExistGuardCheck)
		{
			BudgetManager budgetManager;

			//constructs the budgetPeriod Object
			BudgetPeriod budgetPeriod(8, 2026, 4200.0);

			//calls the method for adding the object to the vector
			budgetManager.addPeriod(budgetPeriod);

			//assertion that compares the expected vector size to the actual size
			Assert::AreEqual((size_t)1, budgetManager.getPeriods().size());

			//assertion that attempts to remove non-existant period
			Assert::ExpectException<std::logic_error>([&]() {budgetManager.removePeriod(7, 2026); });
		}
	};

}