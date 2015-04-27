#include <stdlib.h>
#include <math.h>
#include "ml.h"

#define DEF_POINT(A,TY,ABS,SQRT,EPSILON)	\
	inline	\
	TY mlAbs##A(const TY x) {	\
		return ABS(x);	\
	}	\
	\
	inline	\
	TY mlSqrt##A(const TY x) {	\
		return SQRT(x);	\
	}	\
	\
	inline	\
	TY mlRecip##A(const TY x) {	\
		return mlNearZero##A(x) ? 0 : (1 / x);	\
	}	\
	\
	inline	\
	bool mlNearZero##A(const TY x) {	\
		return mlAbs##A(x) <= EPSILON;	\
	}	\
	\
	inline	\
	TY mlClamp##A(const TY low, const TY hi, const TY val) {	\
		if (low >= val)	return low;	\
		if (hi <= val)	return hi;	\
		return val;	\
	}


DEF_POINT(i,int,abs,sqrtl,0)
DEF_POINT(f,float,fabsf,sqrtf,0.0000001)
DEF_POINT(d,double,fabs,sqrt,0.0000001)

#define DEF_V2(A,TY)	\
	inline	\
	MLV2##A mlV2##A(const TY x, const TY y) {	\
		return (MLV2##A) { .x = x, .y = y };	\
	}	\
	\
	inline	\
	MLV2##A mlV2##A##Point(const TY x) {	\
		return (MLV2##A) { .x = x, .y = x };	\
	}	\
	\
	inline	\
	MLV2##A mlV2##A##Zero() {	\
		return mlV2##A(0,0);	\
	}	\
	\
	inline	\
	MLV2##A mlV2##A##One() {	\
		return mlV2##A(1,1);	\
	}	\
	\
	inline	\
	MLV2##A mlAbsV2##A(const MLV2##A x) {	\
		return mlV2##A(mlAbs##A(x.x), mlAbs##A(x.y));	\
	}	\
	\
	inline	\
	MLV2##A mlAddV2##A(const MLV2##A x, const MLV2##A y) {	\
		return mlV2##A(x.x + y.x, x.y + y.y);	\
	}	\
	\
	inline	\
	MLV2##A mlSubV2##A(const MLV2##A x, const MLV2##A y) {	\
		return mlV2##A(x.x - y.x, x.y - y.y);	\
	}	\
	\
	inline	\
	MLV2##A mlMulV2##A(const MLV2##A x, const MLV2##A y) {	\
		return mlV2##A(x.x * y.x, x.y * y.y);	\
	}	\
	\
	inline	\
	MLV2##A mlDivV2##A(const MLV2##A x, const MLV2##A y) {	\
		return mlV2##A(x.x / y.x, x.y / y.y);	\
	}	\
	\
	inline	\
	MLV2##A mlAddV2##A##A(const MLV2##A x, const TY y) {	\
		return mlV2##A(x.x + y, x.y + y);	\
	}	\
	\
	inline	\
	MLV2##A mlSubV2##A##A(const MLV2##A x, const TY y) {	\
		return mlV2##A(x.x - y, x.y - y);	\
	}	\
	\
	inline	\
	MLV2##A mlMulV2##A##A(const MLV2##A x, const TY y) {	\
		return mlV2##A(x.x * y, x.y * y);	\
	}	\
	\
	inline	\
	MLV2##A mlDivV2##A##A(const MLV2##A x, const TY y) {	\
		return mlV2##A(x.x / y, x.y / y);	\
	}	\
	\
	inline	\
	TY mlSqLenV2##A(const MLV2##A x) {	\
		return x.x * x.x + x.y * x.y;	\
	}	\
	\
	inline	\
	TY mlLenV2##A(const MLV2##A x) {	\
		return mlSqrt##A(mlSqLenV2##A(x));	\
	}	\
	\
	inline	\
	TY mlDotV2##A(const MLV2##A x, const MLV2##A y) {	\
		return x.x * y.x + x.y * y.y;	\
	}	\
	\
	inline	\
	MLV2##A mlNormalizeV2##A(const MLV2##A x) {	\
		/* TODO */	\
		if (mlNearZeroV2##A(x)) {	\
			return x;	\
		} else {	\
			return x;	\
		}	\
	}	\
	\
	inline	\
	MLV2##A mlClampV2##A(const MLV2##A low, const MLV2##A hi, const MLV2##A x) {	\
		return mlV2##A(mlClamp##A(low.x, hi.x, x.x), mlClamp##A(low.y, hi.y, x.y));	\
	}	\
	\
	inline	\
	bool mlNearZeroV2##A(const MLV2##A x)	{	\
		return mlNearZero##A(x.x) && mlNearZero##A(x.y);	\
	}

DEF_V2(i,int)
DEF_V2(f,float)
DEF_V2(d,double)
