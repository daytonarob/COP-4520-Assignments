# Assignment 1 Report

## Approaches

Since my best language is C++, and there are some benefits to it because of how low-level it is, I decided to work on this task with it. However, there are a multitude of ways that C++ can do parallel applications.

### std::thread

In a way, this is the lowest level class that C++ includes; as the name suggests, this is a true thread object that takes in a function to perform independently. Earlier commits for this assignment used these kinds of object, the only reason why I moved away from it is because there would be some extra time that I would have to take care of managing each threads lifetime, and to also check that they are currently not operating.

### std::future and std::async

The `std::future` class is simply an abstracted wrap of std::thread that handles the aforementioned lifetime and execution checking; a future object (in a grammatical standpoint) is simply an object that C++ interprets as, "In the future, I will recieve an object of the specified type to this container." In order for a future to be given a value, the function `std::async` has to be called; this function takes in another function as a parameter and gets automatically assigned to a thread, and then it returns a future object of whatever data type it was specified. Another benefit that this brings is that one can specify to the `async` function whether you can to execute asynchronously, deferred, or let it choose depending on the implementation; this was great because it allowed me to test the program either iteratively or in parallel with the simple change of a parameter.

## Implementation

This assignment was implemented into a single class that had some objects that were used to calculate everything that was required.

### Atomics

Since I had to calculate of all the primes from 1 to 10^8, I knew the sum would be quite large, because of this, I decided to make an `atomic_llong` (`atomic long long`) in order to keep the total sum. I did this by first having a local sum of whatever the number range of 1 to 10^8 was assigned to a thread, the thread-local version of whatever is being executed would keep the local sum of primes, which would lastly then add to the total sum.

I created an `atomic_int` in order keep count of how many prime numbers where found, similar to the previously mentioned atomic, there would be a local count of how many primes where found in the range given to a thread, which then would be added to the total count.

### Finding if a Number is Prime

I simply created a Sieve of Eratosthenes algorithm that follows the square-root property of numbers:

```cpp
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
	// to iteratively check if the number that is being checked
	// can be divisible or not. We are only checking up to
	// the square root of the number.
	for (int i = 3; (i * i) <= num; i += 2) {
		if (num % i == 0)
			return false;
	}

	return true;
}
```

### Keeping Track of the Top Primes

Since at the end of execution, I had to print out the top 10 prime numbers found, from lowest to highest, I created a reverse priority queue that kept its lowest values in the front, and its highest in the back. From there, I also had to create a mutex for safely adding or removing from the queue, along with a lock, so a thread could signal the others to not add to the queue until the mentioned lock is destroyed. If a new prime number was found, it would be pushed to the queue, and if its size was now greater than 10, it would pop one number from the front of the queue.

## Results and Performance

As mentioned before, the `std::async` function allowed me easily to test execution time between single-threaded and multi-threaded runtime. These are example results of one execution, however, the speed increase was estimated from looking at *10 different execution times*, and averaging them out:

**Single-Threaded**

```
Execution time: 30433ms Total primes found: 5761455     Sum of all primes: 279209790387276
```

**Multi-Threaded**
```
Execution time: 5967ms  Total primes found: 5761455     Sum of all primes: 279209790387276
```

---

The average of all the execution times showed that the speed in-execution increased by *~5.13 times* when the application was converted to multi-threaded.
