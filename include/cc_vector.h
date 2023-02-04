#ifndef _cc_H
#define _cc_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


struct vector2_t {
	double x;
	double y;
};

struct vector3_t {
	double x;
	double y;
	double z;
};

/* vector2 */
struct vector2_t cc_vector2_abs(struct vector2_t value);
struct vector2_t cc_vector2_add(struct vector2_t left, struct vector2_t right);
struct vector2_t cc_vector2_clamp(struct vector2_t value, struct vector2_t right, struct vector2_t max);
double cc_vector2_distance(struct vector2_t a, struct vector2_t value2);
double cc_vector2_distance_squared(struct vector2_t a, struct vector2_t value2);
struct vector2_t cc_vector2_divide(struct vector2_t left, double divisor);
double cc_vector2_dot(struct vector2_t a, struct vector2_t value2);
struct vector2_t cc_vector2_lerp(struct vector2_t a, struct vector2_t value2, double amount);
double cc_vector2_angle(struct vector2_t from, struct vector2_t to);
struct vector2_t cc_vector2_max(struct vector2_t a, struct vector2_t value2);
struct vector2_t cc_vector2_min(struct vector2_t a, struct vector2_t value2);
struct vector2_t cc_vector2_lmultiply(double left, struct vector2_t right);
struct vector2_t cc_vector2_rmultiply(struct vector2_t left, double right);
struct vector2_t cc_vector2_negate(struct vector2_t value);
struct vector2_t cc_vector2_normalize(struct vector2_t value);
struct vector2_t cc_vector2_reflect(struct vector2_t vector, struct vector2_t normal);
struct vector2_t cc_vector2_subtract(struct vector2_t left, struct vector2_t right);
bool cc_vector2_equals(struct vector2_t left, struct vector2_t right);
double cc_vector2_length(struct vector2_t value);
double cc_vector2_length_squared(struct vector2_t value);
void cc_vector2_tostring(struct vector2_t a, char* buff);

/* vector3 */
struct vector3_t cc_vector3_abs(struct vector3_t value);
struct vector3_t cc_vector3_add(struct vector3_t left, struct vector3_t right);
struct vector3_t cc_vector3_clamp(struct vector3_t value, struct vector3_t right, struct vector3_t max);
double cc_vector3_distance(struct vector3_t a, struct vector3_t b);
double cc_vector3_distance_squared(struct vector3_t a, struct vector3_t b);
double cc_vector3_dot(struct vector3_t a, struct vector3_t b);
struct vector3_t cc_vector3_lerp(struct vector3_t a, struct vector3_t b, double amount);
double cc_vector3_angle(struct vector3_t from, struct vector3_t to);
struct vector3_t cc_vector3_max(struct vector3_t a, struct vector3_t b);
struct vector3_t cc_vector3_min(struct vector3_t a, struct vector3_t b);
struct vector3_t cc_vector3_lmultiply(double left, struct vector3_t right);
struct vector3_t cc_vector3_rmultiply(struct vector3_t left, double right);
struct vector3_t cc_vector3_negate(struct vector3_t value);
struct vector3_t cc_vector3_normalize(struct vector3_t value);
struct vector3_t cc_vector3_reflect(struct vector3_t value, struct vector3_t normal);
struct vector3_t cc_vector3_subtract(struct vector3_t left, struct vector3_t right);
bool cc_vector3_equals(struct vector3_t left, struct vector3_t right);
double cc_vector3_length(struct vector3_t value);
double cc_vector3_length_squared(struct vector3_t value);
struct vector3_t cc_vector3_cross(struct vector3_t a, struct vector3_t b);
void cc_vector3_tostring(struct vector3_t a, char* buff);


#endif
