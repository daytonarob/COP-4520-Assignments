#pragma once
#include "../Common/Assignment.h"

#include <queue>

class Assignment_1 final : public Assignment
{
public:
	Assignment_1();

private:
	static bool IsPrime(int num);

	void PrimeRange(int start, int end);

	// The amount of given threads
	int THREAD_COUNT = 8;

	// 10^8, faster than having to do std::pow
	int MAX = 100000000;

	// This allows for lock-free safe thread addition
	std::atomic_llong m_primesSum;

	std::atomic_int m_primesCount;

	std::priority_queue<int, std::vector<int>, std::greater<>> m_topPrimes;
};
