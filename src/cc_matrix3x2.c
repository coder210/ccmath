#include "cc_matrix.h"

/*
* 加法
*/
struct matrix3x2_t
cc_matrix3x2_add(struct matrix3x2_t a, struct matrix3x2_t value2) {
	struct matrix3x2_t ret;
	ret.m11 = a.m11 + value2.m11;
	ret.m12 = a.m12 + value2.m12;

	ret.m21 = a.m21 + value2.m21;
	ret.m22 = a.m22 + value2.m22;

	ret.m31 = a.m31 + value2.m31;
	ret.m32 = a.m32 + value2.m32;
	return ret;
}

/*
* 乘法
*/
struct matrix3x2_t
cc_matrix3x2_multiply_matrix3x2(struct matrix3x3_t a, struct matrix3x2_t value2) {
	struct matrix3x2_t ret;
	ret.m11 = a.m11 * value2.m11 + a.m12 * value2.m21 + a.m13 * value2.m31;
	ret.m12 = a.m11 * value2.m12 + a.m12 * value2.m22 + a.m13 * value2.m32;

	ret.m21 = a.m21 * value2.m11 + a.m22 * value2.m21 + a.m23 * value2.m31;
	ret.m22 = a.m21 * value2.m12 + a.m22 * value2.m22 + a.m23 * value2.m32;

	ret.m31 = a.m31 * value2.m11 + a.m32 * value2.m21 + a.m33 * value2.m31;
	ret.m32 = a.m31 * value2.m12 + a.m32 * value2.m22 + a.m33 * value2.m32;
	return ret;
}

/*
*
*/
struct matrix3x2_t
cc_matrix3x2_negate(struct matrix3x2_t a) {
	struct matrix3x2_t ret;
	ret.m11 = -a.m11;
	ret.m12 = -a.m12;
	ret.m21 = -a.m21;
	ret.m22 = -a.m22;
	ret.m31 = -a.m31;
	ret.m32 = -a.m32;
	return ret;
}

/*
* 减法
*/
struct matrix3x2_t
cc_matrix3x2_subtract(struct matrix3x2_t a, struct matrix3x2_t value2) {
	struct matrix3x2_t ret;
	ret.m11 = a.m11 = value2.m11;
	ret.m12 = a.m12 - value2.m12;
	ret.m21 = a.m21 - value2.m21;
	ret.m22 = a.m22 - value2.m22;
	ret.m31 = a.m31 - value2.m31;
	ret.m32 = a.m32 - value2.m32;
	return ret;
}

/*
* 将matrix3x2乘matrix2x3
* 公式: M1x3 * M3x2
*/
struct matrix2x3_t
cc_matrix3x2_transpose_matrix2x3(struct matrix3x2_t a) {
	struct matrix2x3_t ret;
	ret.m11 = a.m11;
	ret.m12 = a.m21;
	ret.m13 = a.m31;

	ret.m21 = a.m12;
	ret.m22 = a.m22;
	ret.m23 = a.m32;
	return ret;
}

/*
* 转成buffer
*/
void
cc_matrix3x2_tostring(struct matrix3x2_t a, char* buff) {
	sprintf(buff, "{%lf, %lf, %lf, %lf, %lf, %lf}", a.m11, a.m12, a.m31, a.m21, a.m22, a.m32);
}
