#include "GuardClass.h"


void GuardClass::checkIdSet(int currentId, int newId, const std::string& fieldName) {

	//checks if the currentId is set
	if (currentId == -1) {
		//left empty since if passed will let other function know terms are valid
	}
	else {
		//throws exception if current id is already set
		throw std::logic_error(fieldName + " is already set.");
	}
}

void GuardClass::checkPeriodExists(BudgetPeriod* existing, const std::string& context) {

	//checks if existing is null 
	if (existing == nullptr) {
		//left empty because if passed will let other funciton know the terms are valid
	}
	else {
		//throws exception if period already exists
		throw std::logic_error(context + " already exists.");
	}

}

void GuardClass::checkPeriodDoesNotExist(BudgetPeriod* existing, const std::string& context) {

	//checks if existing is not null
	if (existing != nullptr) {
		//left empty because if passed it will let other function know the terms are valid
	}
	else {
		//throws exception if there is no existing period
		throw std::logic_error(context + " does not exist.");
	}
}