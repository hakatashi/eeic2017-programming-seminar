#include <stdio.h>
#define LOOP(x, n) for(x = 1; x < n; x++)
#define ILOOP(x, n) for(x = 1; x <= n; x++)

int main() {
	int x, y, z;

	LOOP(y, 1000) ILOOP(x, y) LOOP(z, 1000)
		if (x * x + y * y == z * z)
			printf("%d^2 + %d^2 = %d^2\n", x, y, z);

	return 0;
}
