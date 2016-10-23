#include <stdio.h>
#define LOOP(x, f, t) for(x = f; x < t; x++)
#define ILOOP(x, f, t) for(x = f; x <= t; x++)

int main() {
	int x, y, z;

	LOOP(x, 1, 1000) ILOOP(y, x, 1000) LOOP(z, 1, 1000)
		if (x * x + y * y == z * z)
			printf("%d^2 + %d^2 = %d^2\n", x, y, z);

	return 0;
}
