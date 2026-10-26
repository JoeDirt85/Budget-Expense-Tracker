#include "DataBase.h"
#include <iostream>

DataBase::DataBase(const std::string& dbPath) : db(dbPath, SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE) {


}

void DataBase::createExpenseTable() {

	db.exec("CREATE TABLE IF NOT EXISTS expense (id INTEGER AUTOINCREMENET PRIMARY KEY, category_id INT, "
		"name TEXT NOT NULL, price REAL NOT NULL, date TEXT, description TEXT, FOREIGN KEY (category_id) REFERENCES category (id))" );
}

void DataBase::createCategorytable() {

}

void DataBase::createBudgetPeriodTable() { 

}