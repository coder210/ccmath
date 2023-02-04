#include "cc_matrix.h"

/*
* gets the 2x2 identity matrix.
*/
struct matrix2x2_t
cc_matrix2x2_identity() {
	struct matrix2x2_t matrix2x2;
	matrix2x2.m11 = 1;
	matrix2x2.m12 = 0;
	matrix2x2.m21 = 0;
	matrix2x2.m22 = 1;
	return matrix2x2;
}

/*
* 加法
*/
struct matrix2x2_t
cc_matrix2x2_add(struct matrix2x2_t a, struct matrix2x2_t b) {
	struct matrix2x2_t ret;
	ret.m11 = a.m11 + b.m11;
	ret.m12 = a.m12 + b.m12;
	ret.m21 = a.m21 + b.m21;
	ret.m22 = a.m22 + b.m22;
	return ret;
}

/*
* 
*/
struct matrix2x2_t
cc_matrix2x2_invert(struct matrix2x2_t a) {
	struct matrix2x2_t ret;
	double determinant_inverse = 1 / cc_matrix2x2_determinant(a);
	ret.m11 = a.m22 * determinant_inverse;
	ret.m12 = -a.m12 * determinant_inverse;
	ret.m21 = -a.m21 * determinant_inverse;
	ret.m22 = a.m11 * determinant_inverse;
	return ret;
}

/*
* 乘法
*/
struct matrix2x2_t
cc_matrix2x2_multiply(struct matrix2x2_t a, struct matrix2x2_t b) {
	struct matrix2x2_t ret;
	ret.m11 = a.m11 * b.m11 + a.m12 * b.m21;
	ret.m12 = a.m11 * b.m12 + a.m12 * b.m22;
	ret.m21 = a.m21 * b.m11 + a.m22 * b.m21;
	ret.m22 = a.m21 * b.m12 + a.m22 * b.m22;
	return ret;
}

/*
* 数乘
*/
struct matrix2x2_t 
cc_matrix2x2_lmultiply(double left, struct matrix2x2_t right) {
	struct matrix2x2_t ret;
	ret.m11 = left * right.m11;
	ret.m12 = left * right.m12;
	ret.m21 = left * right.m21;
	ret.m22 = left * right.m22;
	return ret;
}

/*
* 数乘
*/
struct matrix2x2_t 
cc_matrix2x2_rmultiply(struct matrix2x2_t left, double right) {
	struct matrix2x2_t ret;
	ret.m11 = left.m11 * right;
	ret.m12 = left.m12 * right;
	ret.m21 = left.m21 * right;
	ret.m22 = left.m22 * right;
	return ret;
}

/*
* 
*/
struct matrix2x2_t
cc_matrix2x2_negate(struct matrix2x2_t a) {
	struct matrix2x2_t ret;
	ret.m11 = -a.m11;
	ret.m12 = -a.m12;
	ret.m21 = -a.m21;
	ret.m22 = -a.m22;
	return ret;
}

/*
* 减法
*/
struct matrix2x2_t
cc_matrix2x2_subtract(struct matrix2x2_t a, struct matrix2x2_t b) {
	struct matrix2x2_t ret;
	ret.m11 = a.m11 - b.m11;
	ret.m12 = a.m12 - b.m12;
	ret.m21 = a.m21 - b.m21;
	ret.m22 = a.m22 - b.m22;
	return ret;
}


/*
* 转置
*/
struct matrix2x2_t
cc_matrix2x2_transpose(struct matrix2x2_t a) {
	struct matrix2x2_t ret;

	double m21 = a.m12;

	ret.m11 = a.m11;
	ret.m12 = a.m21;

	ret.m21 = m21;
	ret.m22 = a.m22;

	return ret;
}

/*
* D
*/
double
cc_matrix2x2_determinant(struct matrix2x2_t a) {
	return a.m11 * a.m22 - a.m12 * a.m21;
}

/*
* 转成buffer
*/
void
cc_matrix2x2_tostring(struct matrix2x2_t a, char* buff) {
	sprintf(buff, "{%lf, %lf, %lf, %lf}", a.m11, a.m12, a.m21, a.m22);
}

