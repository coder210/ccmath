#include "cc_matrix.h"

/*
* gets the 3x3 zero matrix.
*/
struct matrix3x3_t
cc_matrix3x3_zero() {
	struct matrix3x3_t matrix3x3;
	matrix3x3.m11 = 0;
	matrix3x3.m12 = 0;
	matrix3x3.m13 = 0;
	matrix3x3.m21 = 0;
	matrix3x3.m22 = 0;
	matrix3x3.m23 = 0;
	matrix3x3.m31 = 0;
	matrix3x3.m32 = 0;
	matrix3x3.m33 = 0;
	return matrix3x3;
}

/*
* gets the 3x3 identity matrix.
*/
struct matrix3x3_t
cc_matrix3x3_identity() {
	struct matrix3x3_t matrix3x3;
	matrix3x3.m11 = 1;
	matrix3x3.m12 = 0;
	matrix3x3.m13 = 0;
	matrix3x3.m21 = 0;
	matrix3x3.m22 = 1;
	matrix3x3.m23 = 0;
	matrix3x3.m31 = 0;
	matrix3x3.m32 = 0;
	matrix3x3.m33 = 1;
	return matrix3x3;
}

/*
* 加法
*/
struct matrix3x3_t
cc_matrix3x3_add(struct matrix3x3_t a, struct matrix3x3_t b) {
	struct matrix3x3_t ret;
	ret.m11 = a.m11 + b.m11;
	ret.m12 = a.m12 + b.m12;
	ret.m13 = a.m13 + b.m13;
	ret.m21 = a.m21 + b.m21;
	ret.m22 = a.m22 + b.m22;
	ret.m23 = a.m23 + b.m23;
	ret.m31 = a.m31 + b.m31;
	ret.m32 = a.m32 + b.m32;
	ret.m33 = a.m33 + b.m33;
	return ret;
}

/*
* 乘法
*/
struct matrix3x3_t
cc_matrix3x3_multiply(struct matrix3x3_t a, struct matrix3x3_t b) {
	struct matrix3x3_t ret;
	ret.m11 = a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
	ret.m12 = a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
	ret.m13 = a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33;

	ret.m21 = a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
	ret.m22 = a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
	ret.m23 = a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33;

	ret.m31 = a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
	ret.m32 = a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
	ret.m33 = a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33;
	return ret;
}

/*
* 数乘
*/
struct matrix3x3_t
cc_matrix3x3_lmultiply(double left, struct matrix3x3_t right) {
	struct matrix3x3_t ret;
	ret.m11 = left * right.m11;
	ret.m12 = left * right.m12;
	ret.m13 = left * right.m13;
	ret.m21 = left * right.m21;
	ret.m22 = left * right.m22;
	ret.m23 = left * right.m23;
	ret.m31 = left * right.m31;
	ret.m32 = left * right.m32;
	ret.m33 = left * right.m33;
	return ret;
}

/*
* 数乘
*/
struct matrix3x3_t
cc_matrix3x3_rmultiply(struct matrix3x3_t left, double right) {
	struct matrix3x3_t ret;
	ret.m11 = left.m11 * right;
	ret.m12 = left.m12 * right;
	ret.m13 = left.m13 * right;
	ret.m21 = left.m21 * right;
	ret.m22 = left.m22 * right;
	ret.m23 = left.m23 * right;
	ret.m31 = left.m31 * right;
	ret.m32 = left.m32 * right;
	ret.m33 = left.m33 * right;
	return ret;
}

/*
*
*/
struct matrix3x3_t
cc_matrix3x3_negate(struct matrix3x3_t a) {
	struct matrix3x3_t ret;
	ret.m11 = -a.m11;
	ret.m12 = -a.m12;
	ret.m13 = -a.m13;
	ret.m21 = -a.m21;
	ret.m22 = -a.m22;
	ret.m23 = -a.m23;
	ret.m31 = -a.m31;
	ret.m32 = -a.m32;
	ret.m33 = -a.m33;
	return ret;
}

/*
* 减法
*/
struct matrix3x3_t
cc_matrix3x3_subtract(struct matrix3x3_t a, struct matrix3x3_t b) {
	struct matrix3x3_t ret;
	ret.m11 = a.m11 = b.m11;
	ret.m12 = a.m12 - b.m12;
	ret.m13 = a.m13 - b.m13;
	ret.m21 = a.m21 - b.m21;
	ret.m22 = a.m22 - b.m22;
	ret.m23 = a.m23 - b.m23;
	ret.m31 = a.m31 - b.m31;
	ret.m32 = a.m32 - b.m32;
	ret.m33 = a.m33 - b.m33;
	return ret;
}

/*
* 转置
*/
struct matrix3x3_t
cc_matrix3x3_transpose(struct matrix3x3_t a) {
	struct matrix3x3_t ret;

	double m21 = a.m12;
	double m31 = a.m13;
	double m12 = a.m21;
	double m32 = a.m23;
	double m13 = a.m31;
	double m23 = a.m32;

	ret.m11 = a.m11;
	ret.m12 = m12;
	ret.m13 = m13;
	ret.m21 = m21;
	ret.m22 = a.m22;
	ret.m23 = m23;
	ret.m31 = m31;
	ret.m32 = m32;
	ret.m33 = a.m33;

	return ret;
}

/*
* D
*/
double
cc_matrix3x3_determinant(struct matrix3x3_t a) {
	double ret = a.m11 * a.m22 * a.m33 + a.m12 * a.m23 * a.m31 + a.m13 * a.m21 * a.m32 - a.m13 * a.m22 * a.m31 - a.m12 * a.m21 * a.m33 - a.m11 * a.m23 * a.m32;
	return ret;
}

/*
* 转成buffer
*/
void
cc_matrix3x3_tostring(struct matrix3x3_t a, char* buff) {
	sprintf(buff, "{%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf}", a.m11, a.m12, a.m13, a.m21, a.m22, a.m23, a.m31, a.m32, a.m33);
}
