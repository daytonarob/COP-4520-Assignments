#include "Assingment_1.h"

#include <chrono>

Assignment_1::Assignment_1()
{
	// To know the total elapsed time, get the current time when the program started.
	auto start = std::chrono::high_resolution_clock::now();

	// Create a vector of 8 threads
	std::vector<std::shared_ptr<std::thread>> work_threads;

	// Since there is a range of 1 to 10^8, each thread
	// can handle a range of (10^8)/8, assign each thread
	// their respective range.
	work_threads.reserve(THREAD_COUNT);
	for (int i = 0; i < THREAD_COUNT; i++)
		work_threads.emplace_back(std::make_shared<std::thread>(std::mem_fn(&Assignment_1::PrimeRange), this,
		                                                        i * (MAX / THREAD_COUNT) + 1,
		                                                        (i + 1) * (MAX / THREAD_COUNT)));

	// Execute the threads
	for (auto& thread : work_threads) {
		// Make sure that the thread is not null, and
		// is it not already executing something
		if (thread && thread->joinable())
			thread->join();
	}

	// Now, get the time when we finished the program.
	auto end = std::chrono::high_resolution_clock::now();

	auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	std::printf("Execution time: %lldms\tTotal primes found: %d\tSum of all primes: %lld", total_time,
	            m_primesCount.load(), m_primesSum.load());
}

bool Assignment_1::IsPrime(const int num)
{
	// 1 is not prime
	if (num < 2) return false;

	// The first prime is 2, and from there on
	// each number that is not prime's next multiple
	// would be n * 2
	if (num == 2) return true;
	if (num % 2 == 0) return false;

	// Now the next prime is 3, and we can start from there
	// to iteratively check if the number that is being check
	// is prime or not (Sieve of Eratosthenes).
	for (int i = 3; (i * i) <= num; i += 2) {
		if (num % i == 0)
			return false;
	}

	return true;
}

// Since the top primes data structure is a priority queue,
// it cannot be atomic, because of this, it needs to use
// a mutual exclusion. I provided a lock_guard to it since
// it is a nice wrapper.
std::mutex top_primes_mutex;

void Assignment_1::PrimeRange(const int start, const int end)
{
	// Create a local primes sum, and prime count
	// so that less atomic operations have to be done.

	long long local_sum = 0;
	int local_count = 0;

	// check if a number is prime from the starting number,
	// to the end number.
	for (int i = start; i <= end; i++) {
		if (IsPrime(i)) {
			local_sum += i;
			local_count++;

			// Add to the priority queue, but since we only want
			// the top 10 primes, so if there are more than 10,
			// remove the bottom one.
			std::lock_guard lock(top_primes_mutex);
			m_topPrimes.push(i);
			if (m_topPrimes.size() > 10)
				m_topPrimes.pop();
		}
	}

	// Finally, add to each atomic their corresponding local sum
	m_primesCount.fetch_add(local_count, std::memory_order_relaxed);
	m_primesSum.fetch_add(local_sum, std::memory_order_relaxed);
}
