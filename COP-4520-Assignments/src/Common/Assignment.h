#pragma once

// Adding all of the multi-threading libraries, since
// I don't know what might and might not be used.
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>

// Smart pointers so I don't have to worry too much about
// memory management
#include <memory>

template < typename T >
using ref = std::unique_ptr<T>;

template < typename T >
using shared_ref = std::shared_ptr<T>;

// The way assignments will work is by having a terminal UI
// that holds Assignment types based, once the user selects
// what assignment they want to use (either through a
// command-line argument, or with the terminal GUI,
// it will show that assignment. Because of this, I will have
// a function that calls another function that creates
// an assignment type. To do this, I need the 'functional'
// library, in order to have function objects.
#include <functional>

// Need to store the assignment environments.
#include <vector>

class Assignment
{
public:
	Assignment() = default;

	virtual ~Assignment();
};

class AssignmentMenu final : Assignment
{
public:
	explicit
	AssignmentMenu(Assignment*& current_assignment_pointer) : m_currentAssignment(current_assignment_pointer) {}

	/**
	 * \brief Creates and adds a new assignment to the list of assignments.
	 * \param name of the assignment.
	 */
	void RegisterAssignment(const std::string& name)
	{
		m_assignments.emplace_back(name, [] { return new Assignment(); });
	}

private:
	// Reference to a pointer because the instances will be dynamically created.
	Assignment*& m_currentAssignment;

	// What holds all of the assignments.
	std::vector<std::pair<std::string, std::function<Assignment*()>>> m_assignments;
};
