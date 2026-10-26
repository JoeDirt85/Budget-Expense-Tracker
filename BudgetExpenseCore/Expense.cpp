#include "Expense.h"



//implementation of class default constructor
Expense::Expense()
{
	id = -1;
	categoryId = -1;
	name = "";
	price = 0.0;
	date = "";
	description = "";
}

//implements class constructor
Expense::Expense(const std::string& n, double p, int ci, const std::string& d, const std::string& desc)
{
	id = -1;
	name = n;
	price = p;
	categoryId = ci;
	date = d;
	description = desc;
}

//function that is used to set the value of the id
void Expense::setId(int newId) {

	//CheckIdSet function to verify if Expense Id is set or not
	GuardClass::checkIdSet(id, newId, "Expense ID");

	//if Id is not already set, sets it with new Id
	id = newId;
}

//function to set the value of the name variable
void Expense::setName(const std::string& n)
{
	name = n;
}

//function to set the value of price variable
void Expense::setPrice(double p)
{
	price = p;
}

//fucntion that sets date varuiable
void Expense::setDate(const std::string& d) {
	date = d;
}

//function that sets the description
void Expense::setDescription(const std::string& desc) {
	description = desc;
}

//sets categoryId
void Expense::setCategoryId(int ci) {
	categoryId = ci;
}

//gets id
int Expense::getId() const
{
	return id;
}

//gets category Id
int Expense::getCategoryId() const
{
	return categoryId;
}

//gets name
std::string Expense::getName() const
{
	return name;
}

//gets price
double Expense::getPrice() const
{
	return price;
}

//gets the date
std::string Expense::getDate() const {
	return date;
}

//gets the description
std::string Expense::getDescription() const {
	return description;
}