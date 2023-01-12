// COP-4520-Assignments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Assignments/Assingment_1.h"
#include "Common/Assignment.h"

int main(const int argc, char* argv[])
{
	// Cool little menu logo if command-line arguments are not used.
	if (argc == 1)
		std::cout << R"(
    ___              _                                  __      
   /   |  __________(_)___ _____  ____ ___  ___  ____  / /______
  / /| | / ___/ ___/ / __ `/ __ \/ __ `__ \/ _ \/ __ \/ __/ ___/
 / ___ |(__  |__  ) / /_/ / / / / / / / / /  __/ / / / /_(__  ) 
/_/  |_/____/____/_/\__, /_/ /_/_/ /_/ /_/\___/_/ /_/\__/____/  
                   /____/                                       
)";

	// Make the assignments menu, and the current assignment that the user will enter
	Assignment* current_assignment = nullptr;
	auto menu = new AssignmentMenu(current_assignment);

	current_assignment = menu;

	menu->RegisterAssignment<Assignment_1>("Prime statistics");

	current_assignment->AssignmentText();

	delete current_assignment;

	if (current_assignment != menu)
		delete menu;
}
