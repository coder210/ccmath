#include "cc_matrix.h"


 
bool 
cc_martix3x6_gauss(double matrix[3][6], int m, int n) {
	for (int k = 0; k < m; k++) {
		double max_value = fabs(matrix[k][k]);
		int imax = k;
		for (int i = k + 1; i < m; i++) {
			double value = fabs(matrix[i][k]);
			if (value >= max_value)
			{
				max_value = value;
				imax = i;
			}
		}
		if (max_value == 0)
			return false;
		// Swap rows k, imax
		if (k != imax) {
			for (int j = 0; j < n; j++) {
				double temp = matrix[k][j];
				matrix[k][j] = matrix[imax][j];
				matrix[imax][j] = temp;
			}
		}

		// Divide row by pivot
		double pivot_inverse = 1 / matrix[k][k];

		matrix[k][k] = 1;
		for (int j = k + 1; j < n; j++) {
			matrix[k][j] *= pivot_inverse;
		}

		// Subtract row k from other rows
		for (int i = 0; i < m; i++) {
			if (i == k) {
				continue;
			}
			double f = matrix[i][k];
			for (int j = k + 1; j < n; j++) {
				matrix[i][j] = matrix[i][j] - matrix[k][j] * f;
			}
			matrix[i][k] = 0;
		}
	}
	return true;
}

struct matrix3x3_t
cc_martix3x6_invert(struct matrix3x6_t a, struct matrix3x3_t b) {
	struct matrix3x3_t ret = cc_matrix3x3_zero();

	// Initialize temporary matrix
	a.matrix[0][0] = b.m11;
	a.matrix[0][1] = b.m12;
	a.matrix[0][2] = b.m13;
	a.matrix[1][0] = b.m21;
	a.matrix[1][1] = b.m22;
	a.matrix[1][2] = b.m23;
	a.matrix[2][0] = b.m31;
	a.matrix[2][1] = b.m32;
	a.matrix[2][2] = b.m33;

	a.matrix[0][3] = 1;
	a.matrix[0][4] = 0;
	a.matrix[0][5] = 0;
	a.matrix[1][3] = 0;
	a.matrix[1][4] = 1;
	a.matrix[1][5] = 0;
	a.matrix[2][3] = 0;
	a.matrix[2][4] = 0;
	a.matrix[2][5] = 1;

	if (cc_martix3x6_gauss(a.matrix, 3, 6)) {
		// m11...m13
		ret.m11 = a.matrix[0][3];
		ret.m12 = a.matrix[0][4];
		ret.m13 = a.matrix[0][5];

		// m21...m23
		ret.m21 = a.matrix[1][3];
		ret.m22 = a.matrix[1][4];
		ret.m23 = a.matrix[1][5];

		// m31...m33
		ret.m31 = a.matrix[2][3];
		ret.m32 = a.matrix[2][4];
		ret.m33 = a.matrix[2][5];
	}

	return ret;
}
