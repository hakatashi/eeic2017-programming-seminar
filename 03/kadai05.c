#include <stdio.h>
#include <stdlib.h>

int mod_apm(int, int, int);

int main() {
	printf("mod(541 ^ 1234, 1299709) = %d\n", mod_apm(541, 1234, 1299709));
	return 0;
}

int mod_apm(int a, int p, int m) {
	if (p == 0) {
		return 1;
	} else {
		return (a * mod_apm(a, p - 1, m)) % m;
	}
}
