// COP-4520-Assignments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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
}
