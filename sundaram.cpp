#include "sundaram.h"

std::vector<int> sieve(int n) {
	bool* flags = new bool[(n - 1) / 2 + 1];
	for (int i = 0; i < (n - 1) / 2 + 1; i++)
		flags[i] = true;
	for (int i = 1; i <= (n - 1) / 2; i++)
		for (int j = i; (i + j + 2 * i * j) <= (n - 1) / 2; j++)
			flags[i + j + 2 * i * j] = false;
	std::vector<int> primes;
	if (n > 2)
		primes.push_back(2);
	for (int i = 1; i <= (n - 1) / 2; i++)
		if (flags[i])
			primes.push_back(2 * i + 1);
	return primes;
}
