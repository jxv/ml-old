#include <stdlib.h>
#include <math.h>
#include "ml.h"

#define DEF_POINT(B,TY,ABS,SQRT,EPSILON)	\
	TY mlAbs##B(const TY x) {	\
		return ABS(x);	\
	}	\
	\
	TY mlSqrt##B(const TY x) {	\
		return SQRT(x);	\
	}	\
	\
	bool mlNearZero##B(const TY x) {	\
		return mlAbs##B(x) <= EPSILON;	\
	}	\
	\
	TY mlClamp##B(const TY low, const TY hi, const TY val) {	\
		if (low >= val)	return low;	\
		if (hi <= val)	return hi;	\
		return val;	\
	}


DEF_POINT(i,int,abs,sqrtl,0)
DEF_POINT(f,float,fabsf,sqrtf,0.0000001)
DEF_POINT(d,double,fabs,sqrt,0.0000001)

#define DEF_V2(A,B,TY)	\
	ML_V2##A mlV2##B(const TY x, const TY y) {	\
		return (ML_V2##A) { .x = x, .y = y };	\
	}	\
	\
	ML_V2##A mlV2##B##Pnt(const TY x) {	\
		return (ML_V2##A) { .x = x, .y = x };	\
	}	\
	\
	ML_V2##A mlAbsV2##B(const ML_V2##A x) {	\
		return mlV2##B(mlAbs##B(x.x), mlAbs##B(x.y));	\
	}	\
	\
	ML_V2##A mlAddV2##B##V2##B(const ML_V2##A x, const ML_V2##A y) {	\
		return mlV2##B(x.x + y.x, x.y + y.y);	\
	}	\
	\
	ML_V2##A mlSubV2##B##V2##B(const ML_V2##A x, const ML_V2##A y) {	\
		return mlV2##B(x.x - y.x, x.y - y.y);	\
	}	\
	\
	ML_V2##A mlMulV2##B##V2##B(const ML_V2##A x, const ML_V2##A y) {	\
		return mlV2##B(x.x * y.x, x.y * y.y);	\
	}	\
	\
	ML_V2##A mlDivV2##B##V2##B(const ML_V2##A x, const ML_V2##A y) {	\
		return mlV2##B(x.x / y.x, x.y / y.y);	\
	}	\
	\
	ML_V2##A mlAddV2##B##B(const ML_V2##A x, const TY y) {	\
		return mlV2##B(x.x + y, x.y + y);	\
	}	\
	\
	ML_V2##A mlSubV2##B##B(const ML_V2##A x, const TY y) {	\
		return mlV2##B(x.x - y, x.y - y);	\
	}	\
	\
	ML_V2##A mlMulV2##B##B(const ML_V2##A x, const TY y) {	\
		return mlV2##B(x.x * y, x.y * y);	\
	}	\
	\
	ML_V2##A mlDivV2##B##B(const ML_V2##A x, const TY y) {	\
		return mlV2##B(x.x / y, x.y / y);	\
	}	\
	\
	TY mlSqLenV2##B(const ML_V2##A x) {	\
		return x.x * x.x + x.y * x.y;	\
	}	\
	\
	TY mlLenV2##B(const ML_V2##A x) {	\
		return mlSqrt##B(mlSqLenV2##B(x));	\
	}	\
	\
	ML_V2##A mlClampV2##B(const ML_V2##A low, const ML_V2##A hi, const ML_V2##A x) {	\
		return mlV2##B(mlClamp##B(low.x, hi.x, x.x), mlClamp##B(low.y, hi.y, x.y));	\
	}

DEF_V2(I,i,int)
DEF_V2(F,f,float)
DEF_V2(D,d,double)
