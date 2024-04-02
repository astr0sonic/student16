#include "eratosthenes.h"

std::vector<int> sieve(int n) {
	bool* prime = new bool[n + 1];
	memset(prime, true, sizeof(prime));
	for (int p = 2; p * p <= n; p++) {
		if (prime[p]) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	std::vector<int> primes;
	for (int p = 2; p <= n; p++)
		if (prime[p])
			primes.push_back(p);
    return primes;
}
