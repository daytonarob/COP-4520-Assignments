// COP-4520-Assignments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Assignments/Assingment_1.h"
#include "Common/Assignment.h"

int main(const int argc, char* argv[])
{
	// Make the assignments menu, and the current assignment that the user will enter
	Assignment* current_assignment = nullptr;
	auto menu = new AssignmentMenu(current_assignment);

	current_assignment = menu;

	menu->RegisterAssignment<Assignment_1>("Prime statistics");

	// Check if command-line arguments are being passed
	if (argc == 2)
		current_assignment->AssignmentText(std::strtol(argv[1], nullptr, 10));
	else
		current_assignment->AssignmentText();

	delete current_assignment;

	if (current_assignment != menu)
		delete menu;

	std::cout << "Press the ENTER key to exit.\n";
	std::cin.get();
}
