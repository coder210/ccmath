#include <stdio.h>
#include "cc_vector.h"

int main(){
	struct vector2_t v1;
	v1.x = 10;
	v1.y = 20;
	struct vector2_t v2;
	v2.x = -20;
	v2.y = -10;
	struct vector2_t ret = cc_vector2_add(v1, v2);
	printf("x=%lf, y=%lf", ret.x, ret.y);
	return 0;
}