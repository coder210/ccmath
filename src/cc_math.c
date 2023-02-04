#include "cc_math.h"

double
cc_lerp(double a, double b, double t) {
	if (t <= 0) {
		return a;
	}
	else if (t >= 1) {
		return b;
	}
	return a + (b - a) * t;
}
