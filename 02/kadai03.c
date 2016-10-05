#include <stdio.h>
#include <math.h>
#define LOOP(x, n) for(x = 1; x < n; x++)

int main() {
	int n;
	double sum = 0.0f, pi;

	LOOP(n, 1e3) {
		sum += 1.0f / (n * n * pow(2.0f, n - 1));
	}

	pi = sqrt((sum + M_LN2 * M_LN2) * 6);
	printf("%f", pi);

	return 0;
}
