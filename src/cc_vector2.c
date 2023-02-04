#include "cc_vector.h"
#include "cc_math.h"

struct vector2_t 
cc_vector2_abs(struct vector2_t value) {
	struct vector2_t ret;
	ret.x = fabs(value.x);
	ret.y = fabs(value.y);
	return ret;
}

struct vector2_t 
cc_vector2_add(struct vector2_t left, struct vector2_t right) {
	struct vector2_t ret;
	ret.x = left.x + right.x;
	ret.y = left.y + right.y;
	return ret;
}

struct vector2_t
cc_vector2_clamp(struct vector2_t value, struct vector2_t min, struct vector2_t max) {
	struct vector2_t ret;
	if (value.x < min.x) {
		ret.x = min.x;
	}
	else if (value.x > max.x) {
		ret.x = max.x;
	}
	else {
		ret.x = value.x;
	}
	if (value.y < min.y) {
		ret.y = min.y;
	}
	else if (value.y > max.y) {
		ret.y = max.y;
	}
	else {
		ret.y = value.y;
	}
	return ret;
}

double
cc_vector2_distance(struct vector2_t a, struct vector2_t value2) {
	return sqrt(cc_vector2_distance_squared(a, value2));
}

double 
cc_vector2_distance_squared(struct vector2_t a, struct vector2_t value2) {
	return pow(a.x - value2.x, 2) + pow(a.y - value2.y, 2);
}

struct vector2_t 
cc_vector2_divide(struct vector2_t left, double divisor) {
	struct vector2_t ret;
	if (divisor == 0) {
		ret.x = 0;
		ret.y = 0;
	}
	else {
		ret.x = left.x / divisor;
		ret.y = left.y / divisor;
	}
	return ret;
}

/*
* 数量积
*/
double 
cc_vector2_dot(struct vector2_t a, struct vector2_t value2) {
	double ret = a.x * value2.x + a.y * value2.y;
	return ret;
}

struct vector2_t
cc_vector2_lerp(struct vector2_t a, struct vector2_t value2, double amount) {
	struct vector2_t ret;
	ret.x = cc_lerp(a.x, value2.x, amount);
	ret.y = cc_lerp(a.y, value2.y, amount);
	return ret;
}

double
cc_vector2_angle(struct vector2_t from, struct vector2_t to) {
	double dot = cc_vector2_dot(from, to);
	double mod = cc_vector2_length(from) * cc_vector2_length(to);
	if (mod == 0) {
		return 0;
	}
	else {
		return acos(dot / mod);
	}
}

struct vector2_t 
cc_vector2_max(struct vector2_t a, struct vector2_t value2) {
	struct vector2_t ret;
	ret.x = fmax(a.x, value2.x);
	ret.y = fmax(a.y, value2.y);
	return ret;
}

struct vector2_t 
cc_vector2_min(struct vector2_t a, struct vector2_t value2) {
	struct vector2_t ret;
	ret.x = fmin(a.x, value2.x);
	ret.y = fmin(a.y, value2.y);
	return ret;
}

struct vector2_t 
cc_vector2_lmultiply(double left, struct vector2_t right) {
	struct vector2_t ret;
	ret.x = left * right.x;
	ret.y = left * right.y;
	return ret;
}

struct vector2_t 
cc_vector2_rmultiply(struct vector2_t left, double right) {
	struct vector2_t ret;
	ret.x = left.x * right;
	ret.y = left.y * right;
	return ret;
}

/*
* 向量反量
*/
struct vector2_t 
cc_vector2_negate(struct vector2_t value) {
	struct vector2_t ret;
	ret.x = -value.x;
	ret.y = -value.y;
	return ret;
}

struct vector2_t 
cc_vector2_normalize(struct vector2_t value) {
	struct vector2_t ret;
	double length = cc_vector2_length(value);
	if (length > 0) {
		double rate = 1 / length;
		ret.x = value.x * rate;
		ret.y = value.y * rate;
	}
	else {
		ret.x = 0;
		ret.y = 0;
	}
	return ret;
}

/*
* 投影到向量上的向量
*/
struct vector2_t 
cc_vector2_reflect(struct vector2_t vector, struct vector2_t normal) {
	struct vector2_t ret;
	ret.x = 0;
	ret.y = 0;
	return ret;
}

struct vector2_t 
cc_vector2_subtract(struct vector2_t left, struct vector2_t right) {
	struct vector2_t ret;
	ret.x = left.x - right.x;
	ret.y = left.y - right.y;
	return ret;
}

bool 
cc_vector2_equals(struct vector2_t left, struct vector2_t right) {
	if (left.x == right.x && left.y == right.y) {
		return true;
	}
	else {
		return false;
	}
}

double 
cc_vector2_length(struct vector2_t value) {
	return sqrt(cc_vector2_length_squared(value));
}

double 
cc_vector2_length_squared(struct vector2_t value) {
	return value.x * value.x + value.y * value.y;
}

/*
* 转成buffer
*/
void
cc_vector2_tostring(struct vector2_t a, char* buff) {
	sprintf(buff, "{%lf, %lf}", a.x, a.y);
}
