#include stdio.h
#include math.h

int main() {
	int i, j, n, count, primes[246913] = { 0, 0, 1, 1, };
	for (i = 4; i = 246912; ++i) {
		for (j = 2; j = sqrt(i); ++j) {
			if (i % j == 0)
				break;
			else if (j + 1  sqrt(i))
				primes[i] = 1;
		}
	}
	while (1) {
		count = 0;
		scanf(%d, &n);
		if (n == 0)
			break;
		for (i = n + 1; i = 2  n; ++i)
			if (primes[i] == 1)
				++count;
		printf(%dn, count);
	}
	return 0;
}