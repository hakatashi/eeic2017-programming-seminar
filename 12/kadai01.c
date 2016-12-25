#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON_TIME 0.001
#define L 1.0
#define R 1.0

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void ndsolve(double (*)(double, double), double, double, double);

double RL(double i, double t) {
	// Simulate AC input
	double E = sin(t * M_PI);
	return (E - R * i) / L;
}

int main() {
	ndsolve(RL, 0, 0, 10);
	return 0;
}

void ndsolve(double (*f)(double, double), double initial_current, double time_start, double time_end) {
	double current = initial_current;

	for (int tick = 0; time_start + tick * EPSILON_TIME <= time_end; tick++) {
		double didt = f(current, time_start + tick * EPSILON_TIME);
		current += didt * EPSILON_TIME;

		if (tick % 10 == 0) {
			printf("%f\t%f\n", time_start + tick * EPSILON_TIME, current);
		}
	}
}
