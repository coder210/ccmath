#include "cc_vector.h"
#include "cc_math.h"

struct vector3_t 
cc_vector3_abs(struct vector3_t value) {
	struct vector3_t ret;
	ret.x = fabs(value.x);
	ret.y = fabs(value.y);
	ret.z = fabs(value.z);
	return ret;
}

struct vector3_t 
cc_vector3_add(struct vector3_t left, struct vector3_t right) {
	struct vector3_t ret;
	ret.x = left.x + right.x;
	ret.y = left.y + right.y;
	ret.z = left.z + right.z;
	return ret;
}

struct vector3_t 
cc_vector3_clamp(struct vector3_t value, struct vector3_t min, struct vector3_t max) {
	struct vector3_t ret;
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

	if (value.z < min.z) {
		ret.z = min.z;
	}
	else if (value.z > max.z) {
		ret.z = max.z;
	}
	else {
		ret.z = value.z;
	}

	return ret;
}

double 
cc_vector3_distance(struct vector3_t a, struct vector3_t b) {
	return sqrt(cc_vector3_distance_squared(a, b));
}

double 
cc_vector3_distance_squared(struct vector3_t a, struct vector3_t b) {
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2);
}

struct vector3_t
cc_vector3_divide(struct vector3_t left, double divisor) {
	struct vector3_t ret;
	if (divisor == 0) {
		ret.x = 0;
		ret.y = 0;
	}
	else {
		ret.x = left.x / divisor;
		ret.y = left.y / divisor;
		ret.z = left.z / divisor;
	}
	return ret;
}

/*
* 数量积
*/
double
cc_vector3_dot(struct vector3_t a, struct vector3_t b) {
	double ret = a.x * b.x + a.y * b.y + a.z * b.z;
	return ret;
}

struct vector3_t
cc_vector3_lerp(struct vector3_t a, struct vector3_t b, double amount) {
	struct vector3_t ret;
	ret.x = cc_lerp(a.x, b.x, amount);
	ret.y = cc_lerp(a.y, b.y, amount);
	ret.z = cc_lerp(a.z, b.z, amount);
	return ret;
}

double
cc_vector3_angle(struct vector3_t from, struct vector3_t to) {
	double dot = cc_vector3_dot(from, to);
	double mod = cc_vector3_length(from) * cc_vector3_length(to);
	if (mod == 0) {
		return 0;
	}
	else {
		return acos(dot / mod);
	}
}

struct vector3_t
cc_vector3_max(struct vector3_t a, struct vector3_t b) {
	struct vector3_t ret;
	ret.x = fmax(a.x, b.x);
	ret.y = fmax(a.y, b.y);
	ret.z = fmax(a.z, b.z);
	return ret;
}

struct vector3_t
cc_vector3_min(struct vector3_t a, struct vector3_t b) {
	struct vector3_t ret;
	ret.x = fmin(a.x, b.x);
	ret.y = fmin(a.y, b.y);
	ret.z = fmin(a.z, b.z);
	return ret;
}

struct vector3_t
cc_vector3_lmultiply(double left, struct vector3_t right) {
	struct vector3_t ret;
	ret.x = left * right.x;
	ret.y = left * right.y;
	ret.z = left * right.z;
	return ret;
}

struct vector3_t
cc_vector3_rmultiply(struct vector3_t left, double right) {
	struct vector3_t ret;
	ret.x = left.x * right;
	ret.y = left.y * right;
	ret.z = left.z * right;
	return ret;
}

/*
* 向量反量
*/
struct vector3_t
cc_vector3_negate(struct vector3_t value) {
	struct vector3_t ret;
	ret.x = -value.x;
	ret.y = -value.y;
	ret.z = -value.z;
	return ret;
}

struct vector3_t
cc_vector3_normalize(struct vector3_t value) {
	struct vector3_t ret;
	double length = cc_vector3_length(value);
	if (length > 0) {
		double rate = 1 / length;
		ret.x = value.x * rate;
		ret.y = value.y * rate;
		ret.z = value.z * rate;
	}
	else {
		ret.x = 0;
		ret.y = 0;
		ret.z = 0;
	}
	return ret;
}

/*
* 投影到向量上的向量
*/
struct vector3_t
cc_vector3_reflect(struct vector3_t value, struct vector3_t normal) {
	struct vector3_t ret;
	ret.x = 0;
	ret.y = 0;
	return ret;
}

struct vector3_t
cc_vector3_subtract(struct vector3_t left, struct vector3_t right) {
	struct vector3_t ret;
	ret.x = left.x - right.x;
	ret.y = left.y - right.y;
	ret.z = left.z - right.z;
	return ret;
}

bool
cc_vector3_equals(struct vector3_t left, struct vector3_t right) {
	if (left.x == right.x && left.y == right.y && left.z == right.z) {
		return true;
	}
	else {
		return false;
	}
}

double
cc_vector3_length(struct vector3_t value) {
	return sqrt(cc_vector3_length_squared(value));
}

double
cc_vector3_length_squared(struct vector3_t value) {
	return value.x * value.x + value.y * value.y + value.z * value.z;
}

struct vector3_t 
cc_vector3_cross(struct vector3_t a, struct vector3_t b){
	struct vector3_t ret;
	ret.x = a.y * b.z - a.z * b.y;
	ret.y = a.z * b.x - a.x * b.z;
	ret.z = a.x * b.y - a.y * b.x;
	return ret;
}

/*
* 转成buffer
*/
void
cc_vector3_tostring(struct vector3_t a, char* buff) {
	sprintf(buff, "{%lf, %lf, %lf}", a.x, a.y, a.z);
}
