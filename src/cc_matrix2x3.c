#include "cc_matrix.h"

/*
* 加法
*/
struct matrix2x3_t
cc_matrix2x3_add(struct matrix2x3_t a, struct matrix2x3_t value2) {
	struct matrix2x3_t ret;
	ret.m11 = a.m11 + value2.m11;
	ret.m12 = a.m12 + value2.m12;
	ret.m13 = a.m13 + value2.m13;
	
	ret.m21 = a.m21 + value2.m21;
	ret.m22 = a.m22 + value2.m22;
	ret.m23 = a.m23 + value2.m23;
	return ret;
}

/*
*
*/
struct matrix2x3_t
cc_matrix2x3_negate(struct matrix2x3_t a) {
	struct matrix2x3_t ret;
	ret.m11 = -a.m11;
	ret.m12 = -a.m12;
	ret.m13 = -a.m13;
	ret.m21 = -a.m21;
	ret.m22 = -a.m22;
	ret.m23 = -a.m23;
	return ret;
}

/*
* 减法
*/
struct matrix2x3_t
cc_matrix2x3_subtract(struct matrix2x3_t a, struct matrix2x3_t value2) {
	struct matrix2x3_t ret;
	ret.m11 = a.m11 - value2.m11;
	ret.m12 = a.m12 - value2.m12;
	ret.m13 = a.m13 - value2.m13;

	ret.m21 = a.m21 - value2.m21;
	ret.m22 = a.m22 - value2.m22;
	ret.m23 = a.m23 - value2.m23;
	return ret;
}


/*
* 转置
*/
struct matrix3x2_t
cc_matrix2x3_transpose_matrix3x2(struct matrix2x3_t a) {
	struct matrix3x2_t ret;

	ret.m11 = a.m11;
	ret.m12 = a.m21;

	ret.m21 = a.m12;
	ret.m22 = a.m22;

	ret.m31 = a.m13;
	ret.m32 = a.m23;

	return ret;
}

/*
* 转成buffer
*/
void
cc_matrix2x3_tostring(struct matrix2x3_t a, char* buff) {
	sprintf(buff, "{%lf, %lf, %lf, %lf, %lf, %lf}", a.m11, a.m12, a.m13, a.m21, a.m22, a.m23);
}
