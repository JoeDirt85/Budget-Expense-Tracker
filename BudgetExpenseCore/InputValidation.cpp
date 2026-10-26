#include "InputValidation.h"
#include <iostream>
#include <limits>

/*
//implementation of class to validate any values that are supposed to be int
int InputValidation::getInt() {
	int value;

	//loop that checks if value is correct type
	while (true) {
		std::cin >> value;

		//if cin fails, its clears and ignores other inputs and outputs error 
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, please enter a whole number: " << std::endl;
		}
		else { //if cin doesn't fail goes into another loop, checks for positive value
			if (value < 0){
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input, please enter a positive number: " << std::endl;
			}
			else {//if value passes both checks, it gets returned
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;
			}
		}
	}
}

//loop to validate double types
double InputValidation::getDouble() {
	double value;

	//loop that checks if value is correct type
	while (true) {
		std::cin >> value;

		//if cin fails, its clears and ignores other inputs and outputs error
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, please enter a number: " << std::endl;
		}
		else {
			if (value < 0) { //if cin doesn't fail goes into another loop, checks for positive value
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input, please enter a positive number: " << std::endl;
			}
			else {//if value passes both checks, it gets returned
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;
			}
		}
	}
}

//gets full line of string so that spaces in input comes in as two seperate strings
std::string InputValidation::getString() {
	std::string value;

	std::getline(std::cin >> std::ws, value);
	return value;
}
*/

