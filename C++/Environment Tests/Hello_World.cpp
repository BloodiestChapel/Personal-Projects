#include <iostream>

int main()
{
	// Use with "C++ Input" Build System

	std::string nameFirst = "John";
	std::string nameLast = "Doe";

	std::cout << "What's your first name? \n";
	std::cin  >> nameFirst;

	std::cout << "What's your last name? \n";
	std::cin  >> nameLast;

	std::cout << "Hello, " << nameFirst << " " << nameLast << "!" <<std::endl;
	return 0;
}