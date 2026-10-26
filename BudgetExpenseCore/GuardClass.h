#ifndef GUARDCLASS_H
#define GUARDCLASS_H


#include <string>
#include <stdexcept>

class BudgetPeriod;

class GuardClass
{
public:

	//function used to check if id is set or not and throws exception if needed
	static void checkIdSet(int currentId, int newId, const std::string& fieldName);

	//function used to check if a period already exists and throws exception if needed
	static void checkPeriodExists(BudgetPeriod* existing, const std::string& context);

	//function used to check if a period doesn't exist and throws exception if needed
	static void checkPeriodDoesNotExist(BudgetPeriod* existing, const std::string& context);
};

#endif