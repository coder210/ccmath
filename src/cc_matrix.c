#include "cc_matrix.h"


/*
* gets the 4x4 zero matrix.
*/
struct matrix_t
cc_matrix_zero() {
	struct matrix_t ret;
    ret.m11 = 0;
    ret.m12 = 0;
    ret.m13 = 0;
    ret.m14 = 0;
    ret.m21 = 0;
    ret.m22 = 0;
    ret.m23 = 0;
    ret.m24 = 0;
    ret.m31 = 0;
    ret.m32 = 0;
    ret.m33 = 0;
    ret.m34 = 0;
    ret.m41 = 0;
    ret.m42 = 0;
    ret.m43 = 0;
    ret.m44 = 0;
    return ret;
}

/*
* gets the 4x4 identity matrix.
*/
struct matrix_t
cc_matrix_identity() {
    struct matrix_t ret;
    ret.m11 = 1;
    ret.m12 = 0;
    ret.m13 = 0;
    ret.m14 = 0;
    ret.m21 = 0;
    ret.m22 = 1;
    ret.m23 = 0;
    ret.m24 = 0;
    ret.m31 = 0;
    ret.m32 = 0;
    ret.m33 = 1;
    ret.m34 = 0;
    ret.m41 = 0;
    ret.m42 = 0;
    ret.m43 = 0;
    ret.m44 = 1;
    return ret;
}


/*
* computes the determinant of the matrix.
*/
double 
cc_matrix_determinant(struct matrix_t a) {
    // compute the re-used 2x2 determinants.
    double det1 = a.m33 * a.m44 - a.m34 * a.m43;
    double det2 = a.m32 * a.m44 - a.m34 * a.m42;
    double det3 = a.m32 * a.m43 - a.m33 * a.m42;
    double det4 = a.m31 * a.m44 - a.m34 * a.m41;
    double det5 = a.m31 * a.m43 - a.m33 * a.m41;
    double det6 = a.m31 * a.m42 - a.m32 * a.m41;
    return
        (a.m11 * ((a.m22 * det1 - a.m23 * det2) + a.m24 * det3)) -
        (a.m12 * ((a.m21 * det1 - a.m23 * det4) + a.m24 * det5)) +
        (a.m13 * ((a.m21 * det2 - a.m22 * det4) + a.m24 * det6)) -
        (a.m14 * ((a.m21 * det3 - a.m22 * det5) + a.m23 * det6));
}

/* ×ªÖÃ */
struct matrix_t
cc_matrix_transpose(struct matrix_t a) {
    struct matrix_t ret;
    ret.m11 = a.m41;
    ret.m12 = a.m31;
    ret.m13 = a.m21;
    ret.m14 = a.m11;

    ret.m21 = a.m42;
    ret.m22 = a.m32;
    ret.m23 = a.m22;
    ret.m24 = a.m12;

    ret.m31 = a.m43;
    ret.m32 = a.m33;
    ret.m33 = a.m23;
    ret.m34 = a.m13;

    ret.m41 = a.m44;
    ret.m42 = a.m34;
    ret.m43 = a.m24;
    ret.m44 = a.m14;
    return ret;
}


/*
* ³Ë·¨
*/
struct matrix_t
cc_matrix_multiply(struct matrix_t a, struct matrix_t b) {
    struct matrix_t ret;
    double ret_m11 = a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31 + a.m14 * b.m41;
    double ret_m12 = a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32 + a.m14 * b.m42;
    double ret_m13 = a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33 + a.m14 * b.m43;
    double ret_m14 = a.m11 * b.m14 + a.m12 * b.m24 + a.m13 * b.m34 + a.m14 * b.m44;

    double ret_m21 = a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31 + a.m24 * b.m41;
    double ret_m22 = a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32 + a.m24 * b.m42;
    double ret_m23 = a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33 + a.m24 * b.m43;
    double ret_m24 = a.m21 * b.m14 + a.m22 * b.m24 + a.m23 * b.m34 + a.m24 * b.m44;

    double ret_m31 = a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31 + a.m34 * b.m41;
    double ret_m32 = a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32 + a.m34 * b.m42;
    double ret_m33 = a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33 + a.m34 * b.m43;
    double ret_m34 = a.m31 * b.m14 + a.m32 * b.m24 + a.m33 * b.m34 + a.m34 * b.m44;

    double ret_m41 = a.m41 * b.m11 + a.m42 * b.m21 + a.m43 * b.m31 + a.m44 * b.m41;
    double ret_m42 = a.m41 * b.m12 + a.m42 * b.m22 + a.m43 * b.m32 + a.m44 * b.m42;
    double ret_m43 = a.m41 * b.m13 + a.m42 * b.m23 + a.m43 * b.m33 + a.m44 * b.m43;
    double ret_m44 = a.m41 * b.m14 + a.m42 * b.m24 + a.m43 * b.m34 + a.m44 * b.m44;

    ret.m11 = ret_m11;
    ret.m12 = ret_m12;
    ret.m13 = ret_m13;
    ret.m14 = ret_m14;

    ret.m21 = ret_m21;
    ret.m22 = ret_m22;
    ret.m23 = ret_m23;
    ret.m24 = ret_m24;

    ret.m31 = ret_m31;
    ret.m32 = ret_m32;
    ret.m33 = ret_m33;
    ret.m34 = ret_m34;

    ret.m41 = ret_m41;
    ret.m42 = ret_m42;
    ret.m43 = ret_m43;
    ret.m44 = ret_m44;

    return ret;
}


/*
Êı³Ë
*/
struct matrix_t
cc_matrix_lmultiply(struct matrix_t a, double b) {
    struct matrix_t ret;
    ret.m11 = a.m11 * b;
    ret.m12 = a.m12 * b;
    ret.m13 = a.m13 * b;
    ret.m14 = a.m14 * b;

    ret.m21 = a.m21 * b;
    ret.m22 = a.m22 * b;
    ret.m23 = a.m23 * b;
    ret.m24 = a.m24 * b;

    ret.m31 = a.m31 * b;
    ret.m32 = a.m32 * b;
    ret.m33 = a.m33 * b;
    ret.m34 = a.m34 * b;

    ret.m41 = a.m41 * b;
    ret.m42 = a.m42 * b;
    ret.m43 = a.m43 * b;
    ret.m44 = a.m44 * b;

    return ret;
}

void 
cc_matrix_tostring(struct matrix_t a, char* buff) {
    sprintf(buff, "{%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf}", a.m11, a.m12, a.m13, a.m14, a.m21, a.m22, a.m23, a.m24, a.m31, a.m32, a.m33, a.m34, a.m41, a.m42, a.m43, a.m44);
}
