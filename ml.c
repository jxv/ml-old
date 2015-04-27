#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "ml.h"

#define DEF_POINT(B,TY)	\
	TY mlClamp##B(const TY low, const TY hi, const TY val) {	\
		if (low >= val)	return low;	\
		if (hi <= val)	return hi;	\
		return val;	\
	}

DEF_POINT(i,int)
DEF_POINT(f,float)
DEF_POINT(d,double)			

#define DEF_V2(A,B,TY,ABS,SQRT)	\
	ML_V2##A mlV2##B(const TY x, const TY y) {	\
		return (ML_V2##A) { .x = x, .y = y };	\
	}	\
	\
	ML_V2##A mlV2##B##Pnt(const TY x) {	\
		return (ML_V2##A) { .x = x, .y = x };	\
	}	\
	\
	ML_V2##A mlAbsV2##B(const ML_V2##A x) {	\
		return mlV2##B(ABS(x.x), ABS(x.y));	\
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
		return SQRT(mlSqLenV2##B(x));	\
	}	\
	\
	ML_V2##A mlClampV2##B(const ML_V2##A low, const ML_V2##A hi, const ML_V2##A x) {	\
		return mlV2##B(mlClamp##B(low.x, hi.x, x.x), mlClamp##B(low.y, hi.y, x.y));	\
	}

DEF_V2(I,i,int,abs,sqrtl)
DEF_V2(F,f,float,fabsf,sqrtf)
DEF_V2(D,d,double,fabs,sqrt)
