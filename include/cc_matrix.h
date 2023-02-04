#ifndef _CC_MATRIX_H
#define _CC_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


struct matrix_t {
    /* value at row 1, column 1 of the matrix. */
    double m11;

    /* value at row 1, column 2 of the matrix. */
    double m12;

    /* value at row 1, column 3 of the matrix. */
    double m13;

    /* value at row 1, column 4 of the matrix. */
    double m14;

    /* value at row 2, column 1 of the matrix. */
    double m21;

    /* value at row 2, column 2 of the matrix. */
    double m22;

    /* value at row 2, column 3 of the matrix. */
    double m23;

    /* value at row 2, column 4 of the matrix. */
    double m24;

    /* value at row 3, column 1 of the matrix. */
    double m31;

    /* value at row 3, column 2 of the matrix. */
    double m32;

    /* value at row 3, column 3 of the matrix. */
    double m33;

    /* value at row 3, column 4 of the matrix. */
    double m34;

    /* value at row 4, column 1 of the matrix. */
    double m41;

    /* value at row 4, column 2 of the matrix. */
    double m42;

    /* value at row 4, column 3 of the matrix. */
    double m43;

    /* value at row 4, column 4 of the matrix. */
    double m44;
};

struct matrix2x2_t {
    /* value at row 1, column 1 of the matrix. */
    double m11;

    /* value at row 1, column 2 of the matrix. */
    double m12;

    /* value at row 2, column 1 of the matrix. */
    double m21;

    /* value at row 2, column 2 of the matrix. */
    double m22;
};

struct matrix2x3_t {
    /* value at row 1, column 1 of the matrix. */
    double m11;

    /* value at row 1, column 2 of the matrix. */
    double m12;

    /* value at row 1, column 3 of the matrix. */
    double m13;

    /* value at row 2, column 1 of the matrix. */
    double m21;

    /* value at row 2, column 2 of the matrix. */
    double m22;

    /* value at row 2, column 3 of the matrix. */
    double m23;
};

struct matrix3x2_t {
    /* value at row 1, column 1 of the matrix. */
    double m11;

    /* value at row 1, column 2 of the matrix. */
    double m12;

    /* value at row 2, column 1 of the matrix. */
    double m21;

    /* value at row 2, column 2 of the matrix. */
    double m22;

    /* value at row 3, column 1 of the matrix. */
    double m31;

    /* value at row 3, column 2 of the matrix. */
    double m32;
};

struct matrix3x3_t {
    /* value at row 1, column 1 of the matrix. */
    double m11;

    /* value at row 1, column 2 of the matrix. */
    double m12;

    /* value at row 1, column 3 of the matrix. */
    double m13;

    /* value at row 2, column 1 of the matrix. */
    double m21;

    /* value at row 2, column 2 of the matrix. */
    double m22;

    /* value at row 2, column 3 of the matrix. */
    double m23;

    /* value at row 3, column 1 of the matrix. */
    double m31;

    /* value at row 3, column 2 of the matrix. */
    double m32;

    /* value at row 3, column 3 of the matrix. */
    double m33;
};

struct matrix3x6_t {
    double matrix[3][6];
};

struct matrix4x8_t {
    double matrix[4][8];
};


/* matrix */
struct matrix_t cc_matrix_zero();
struct matrix_t cc_matrix_identity();
double cc_matrix_determinant(struct matrix_t a);
struct matrix_t cc_matrix_transpose(struct matrix_t a);
struct matrix_t cc_matrix_multiply(struct matrix_t a, struct matrix_t b);
struct matrix_t cc_matrix_lmultiply(struct matrix_t a, double b);
void cc_matrix_tostring(struct matrix_t a, char* buff);

/* matrix2x2 */
struct matrix2x2_t cc_matrix2x2_identity();
struct matrix2x2_t cc_matrix2x2_add(struct matrix2x2_t a, struct matrix2x2_t b);
struct matrix2x2_t cc_matrix2x2_invert(struct matrix2x2_t a);
struct matrix2x2_t cc_matrix2x2_multiply(struct matrix2x2_t a, struct matrix2x2_t b);
struct matrix2x2_t cc_matrix2x2_lmultiply(double left, struct matrix2x2_t right);
struct matrix2x2_t cc_matrix2x2_rmultiply(struct matrix2x2_t left, double right);
struct matrix2x2_t cc_matrix2x2_negate(struct matrix2x2_t a);
struct matrix2x2_t cc_matrix2x2_subtract(struct matrix2x2_t a, struct matrix2x2_t b);
struct matrix2x2_t cc_matrix2x2_transpose(struct matrix2x2_t a);
double cc_matrix2x2_determinant(struct matrix2x2_t a);
void cc_matrix2x2_tostring(struct matrix2x2_t a, char* buff);

/* matrix2x3 */
struct matrix2x3_t cc_matrix2x3_add(struct matrix2x3_t a, struct matrix2x3_t value2);
struct matrix2x3_t cc_matrix2x3_negate(struct matrix2x3_t a);
struct matrix2x3_t cc_matrix2x3_subtract(struct matrix2x3_t a, struct matrix2x3_t value2);
struct matrix3x2_t cc_matrix2x3_transpose_matrix3x2(struct matrix2x3_t a);
void cc_matrix2x3_tostring(struct matrix2x3_t a, char* buff);

/* matrix3x2 */
struct matrix3x2_t cc_matrix3x2_add(struct matrix3x2_t a, struct matrix3x2_t value2);
struct matrix3x2_t cc_matrix3x2_negate(struct matrix3x2_t a);
struct matrix3x2_t cc_matrix3x2_subtract(struct matrix3x2_t a, struct matrix3x2_t value2);
struct matrix2x3_t cc_matrix3x2_transpose_matrix2x3(struct matrix3x2_t a);
void cc_matrix3x2_tostring(struct matrix3x2_t a, char* buff);

/* matrix3x3 */
struct matrix3x3_t cc_matrix3x3_zero();
struct matrix3x3_t cc_matrix3x3_identity();
struct matrix3x3_t cc_matrix3x3_add(struct matrix3x3_t a, struct matrix3x3_t b);
struct matrix3x3_t cc_matrix3x3_multiply(struct matrix3x3_t a, struct matrix3x3_t b);
struct matrix3x3_t cc_matrix3x3_lmultiply(double left, struct matrix3x3_t right);
struct matrix3x3_t cc_matrix3x3_rmultiply(struct matrix3x3_t left, double right);
struct matrix3x3_t cc_matrix3x3_negate(struct matrix3x3_t a);
struct matrix3x3_t cc_matrix3x3_subtract(struct matrix3x3_t a, struct matrix3x3_t b);
struct matrix3x3_t cc_matrix3x3_transpose(struct matrix3x3_t a);
double cc_matrix3x3_determinant(struct matrix3x3_t a);
void cc_matrix3x3_tostring(struct matrix3x3_t a, char* buff);


#endif
