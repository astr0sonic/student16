#include "eratosthenes.h"

std::vector<int> sieve(int n) {
	bool* flags = new bool[n + 1];
	//memset(flags, true, sizeof(flags));
	for (int i = 0; i < n + 1; i++)
		flags[i] = true;
	for (int p = 2; p * p <= n; p++) {
		if (flags[p]) {
			for (int i = p * p; i <= n; i += p)
				flags[i] = false;
		}
	}
	std::vector<int> primes;
	for (int p = 2; p <= n; p++)
		if (flags[p])
			primes.push_back(p);
    return primes;
}
